// [[Rcpp::depends(RcppArmadillo)]]
#include "gicl_tools.h"
#include "Mm.h"
using namespace Rcpp;

Mm::Mm(const arma::sp_mat  & xp,S4 modeli,bool verb){
  model = modeli;
  
  // dirichlet prior parameter on proportion
  beta = model.slot("beta");
  // data
  // store transpose for fast colum acces
  xt = xp.t();
  // Number of individuals
  N  = xp.n_rows;
  
  // TODO : add a filed to store the icl const ?
  verbose=verb;
}



void Mm::set_cl(arma::uvec clt){

  K = arma::max(clt)+1;
  // x_counts : col sums for each cluster
  x_counts = gsum_mm(clt,xt,K);
  
  col_sums = sum(x_counts);

}


List Mm::get_obs_stats(){
  // return observed stats
  return List::create(Named("x_counts", x_counts));
}

double Mm::icl_emiss(const List & obs_stats){
  // compute log(p(X|Z))
  arma::sp_mat x_counts =as<arma::sp_mat>(obs_stats["x_counts"]);
  int d = x_counts.n_rows;
  int K = x_counts.n_cols;
  double icl_emiss = 0;
  for (int k = 0;k<K;++k){
    // B(X+beta)/B(beta)
    // ! sparse + double -> dense : x_counts.col(k)+beta
    icl_emiss += lgamma(d*beta)+arma::accu(lgamma(x_counts.col(k)+beta))-d*lgamma(beta)-lgamma(arma::accu(x_counts.col(k)+beta));
  }
  return icl_emiss;
}

double Mm::icl_emiss(const List & obs_stats,int oldcl,int newcl, bool dead_cluster){
  // compute log(p(X|Z)) but only for the 2 classes which haved changed (oldcl,newcl)
  arma::sp_mat x_counts =as<arma::sp_mat>(obs_stats["x_counts"]);
  arma::rowvec col_sums =as<arma::rowvec>(obs_stats["col_sums"]);
  double icl_emiss = 0;
  int d = x_counts.n_rows;
  // only for the 2 classes which haved changed (oldcl,newcl) and not empty
  if(!dead_cluster){
    // compute log(p(X|Z))
    icl_emiss += lgamma(d*beta)+arma::accu(lgamma(x_counts.col(oldcl)+beta))-d*lgamma(beta)-lgamma(col_sums(oldcl)+d*beta);
  }
  // compute log(p(X|Z))
  icl_emiss += lgamma(d*beta)+arma::accu(lgamma(x_counts.col(newcl)+beta))-d*lgamma(beta)-lgamma(col_sums(newcl)+d*beta);
  return icl_emiss;
}




arma::vec Mm::delta_swap(int i,arma::uvec & cl, bool almost_dead_cluster, arma::uvec iclust, int K){
  // old cluster
  int oldcl = cl(i);

  // extract current row 
  arma::sp_mat ccol = xt.col(i);
  
  // initialize vecor of delta ICL
  arma::vec delta(K);
  delta.fill(-std::numeric_limits<double>::infinity());
  delta(oldcl)=0;
  // old stats
  
  
  arma::sp_mat old_ec = x_counts;
  // if cluster will die do not sparsify the counts
  if(!almost_dead_cluster){
    old_ec.col(oldcl) = add_sppat(add_sppat(old_ec.col(oldcl),ccol),-ccol);
  }
  

  int k = 0;
  // for each possible move
  for(arma::uword j = 0; j < iclust.n_elem; ++j) {
    k=iclust(j);
    if(k!=oldcl){
      // construct new stats
      arma::sp_mat new_ec = x_counts;
      // siwtch current row
      //new_ec.col(k) = new_ec.col(k)+ccol;
      //new_ec.col(oldcl) = new_ec.col(oldcl)-ccol;
      
      // sparcify the counts and move current doc
      new_ec.col(k) = add_sppat(new_ec.col(k),ccol);
      
      new_ec.col(oldcl) = add_sppat(new_ec.col(oldcl),-ccol);
      
      old_ec.col(k) = add_sppat(add_sppat(old_ec.col(k),ccol),-ccol);
      


      
      // update colsums
      arma::rowvec new_col_sums = col_sums;
      double nbt = arma::accu(ccol);
      new_col_sums(k)=new_col_sums(k)+nbt;
      new_col_sums(oldcl)=new_col_sums(oldcl)-nbt;
      //Rcout << new_col_sums << std::endl;
      // new stats and delta
      List new_stats = List::create( Named("x_counts", new_ec),Named("col_sums",new_col_sums));
      List old_stats = List::create( Named("x_counts", old_ec),Named("col_sums",col_sums));

      delta(k)=icl_emiss(new_stats,oldcl,k,almost_dead_cluster)-icl_emiss(old_stats,oldcl,k,false);
    }
    

  }

  return delta;
}


void Mm::swap_update(const int i,arma::uvec &  cl,bool dead_cluster,const int newcl){
  // a swap is done !
  // old cluster
  int oldcl = cl(i);
  // current row
  arma::sp_mat ccol = xt.col(i);
  // update x_counts
  
  x_counts.col(newcl) = x_counts.col(newcl)+ccol;
  x_counts.col(oldcl) = x_counts.col(oldcl)-ccol;

    // if a cluster is dead
  // update col_sums
  double nbt = arma::accu(ccol);
  col_sums(newcl)=col_sums(newcl)+nbt;
  col_sums(oldcl)=col_sums(oldcl)-nbt;
  
  if(dead_cluster){
    // remove from x_counts
    x_counts = x_counts.cols(arma::find(arma::linspace(0,K-1,K)!=oldcl));
    // remove from col_sums
    col_sums.shed_col(oldcl);
    // upate K
    --K;
  }
  
}


double Mm::delta_merge(int k,int l){
  // optim a calculer uniquement lors de l'init et des update 
  //arma::rowvec col_sums(sum(x_counts));   
  arma::sp_mat new_ec = x_counts;
  // x_counts after merge on l
  // row/col k will not be taken into account since counts(k)==0
  new_ec.col(l) = new_ec.col(l)+new_ec.col(k);
  
  // colsums changes
  arma::rowvec new_col_sums = col_sums;
  new_col_sums(l)=new_col_sums(k)+new_col_sums(l);
  new_col_sums(k)=0;
  List new_stats = List::create( Named("x_counts", new_ec),Named("col_sums",new_col_sums));
  List old_stats = List::create( Named("x_counts", x_counts),Named("col_sums",col_sums));
  
  // small optim possible by only tacking into account values that change un new_ec.col(l) // x_counts.col(l)
  
  // delta
  double delta=icl_emiss(new_stats,k,l,true)-icl_emiss(old_stats,k,l,false);
  return delta;
}



// Merge update between k and l
void Mm::merge_update(int k,int l){
  // update x_counts
  x_counts.col(l) = x_counts.col(k)+x_counts.col(l);
  x_counts = x_counts.cols(arma::find(arma::linspace(0,K-1,K)!=k));
  // update col_sums
  col_sums(l) = col_sums(l) + col_sums(k);
  col_sums.shed_col(k);
  // update K
  --K;
}