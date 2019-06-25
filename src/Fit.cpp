// [[Rcpp::depends(RcppArmadillo)]]
#include <RcppArmadilloExtensions/sample.h>
#include "IclModel.h"
#include "Sbm.h"
#include "DcSbm.h"
#include "Mm.h"
#include "Mreg.h"
#include "Mvmreg.h"
using namespace Rcpp;



IclModel * init(S4 model,List data, arma::vec clt, bool verbose) {
  
  IclModel * M;
  int Ki = arma::max(clt);
  int N = clt.n_elem;
  clt = clt-arma::ones(N);
  S4 sol;
  try{
    if(strcmp(model.slot("name"),"sbm")!=0 && 
       strcmp(model.slot("name"),"dcsbm")!=0 && 
       strcmp(model.slot("name"),"co_dcsbm")!=0 && 
       strcmp(model.slot("name"),"mm")!=0 &&
       strcmp(model.slot("name"),"mvmreg")!=0 &&
       strcmp(model.slot("name"),"mreg")!=0){
      stop("Unsuported model");
    }
    if(strcmp(model.slot("name"),"sbm")==0){
      arma::sp_mat xp = as<arma::sp_mat>(data["X"]);
      M = new Sbm(xp,Ki,model.slot("alpha"),model.slot("a0"),model.slot("b0"),clt,verbose);
    }
    if(strcmp(model.slot("name"),"dcsbm")==0){
      arma::sp_mat xp = as<arma::sp_mat>(data["X"]);
      M = new DcSbm(xp,Ki,model.slot("alpha"),clt,verbose);
    }
    if(strcmp(model.slot("name"),"co_dcsbm")==0){
      arma::sp_mat xp = as<arma::sp_mat>(data["X"]);
      M = new DcSbm(xp,Ki,model.slot("alpha"),clt,verbose);
    }
    if(strcmp(model.slot("name"),"mm")==0){
      arma::sp_mat xp = as<arma::sp_mat>(data["X"]);
      M = new Mm(xp,Ki,model.slot("alpha"),model.slot("beta"),clt,verbose);
    }
    if(strcmp(model.slot("name"),"mreg")==0){
      arma::mat X = as<arma::mat>(data["X"]);
      arma::colvec y = as<arma::colvec>(data["y"]);
      M = new Mreg(X,y,Ki,model.slot("alpha"),model.slot("reg"),model.slot("a0"),model.slot("b0"),clt,verbose);
    }
    
    if(strcmp(model.slot("name"),"mvmreg")==0){
      arma::mat X = as<arma::mat>(data["X"]);
      arma::mat Y = as<arma::mat>(data["Y"]);
      M = new Mvmreg(X,Y,Ki,model.slot("alpha"),model.slot("beta"),model.slot("N0"),clt,verbose);
    }
    
    
    return(M);
  }catch(std::exception &ex) {	
    forward_exception_to_r(ex);
  }
}

S4 init_sol(S4 model,String type="fit") {
  String mname = model.slot("name");
  mname+="_";
  mname+=type;
  S4 sol(mname);
  sol.slot("name")=mname;
  return(sol);
}

//' post_probs
//' @param model icl_model
//' @param data list with clustering data (fileds depend on model type)
//' @param clt cluster labels in 1,..,K
//' @export
// [[Rcpp::export]]
arma::mat post_probs(S4 model,List data,  arma::vec& clt) {
  IclModel * M = init(model,data,clt,false);
  arma::mat probs = M->get_probs();
  delete M;
  return(probs);
}

//' fit_greed
//' @param model icl_model
//' @param data list with clustering data (fileds depend on model type)
//' @param clt cluster labels {0,...,K-1}
//' @param type merge, swap, none, or both (default)  
//' @param nb_max_pass maximum number of pass for greedy swap
//' @param verbose boolean for verbose mode default to false
//' @return a model_fit object  
//' @export
// [[Rcpp::export]]
S4 fit_greed_cstr(S4 model,List data,  arma::vec& clt,arma::vec workingset,arma::uvec iclust, std::string type="both", int nb_max_pass = 50,bool verbose=false) {
  IclModel * M = init(model,data,clt,verbose);
  S4 sol = init_sol(model);
  if(type!="merge" && type!="swap" && type!="both" && type!="none"){
    stop("Unsuported algorithm");
  }
  if(type=="swap" || type=="both"){
    M->greedy_swap(nb_max_pass,workingset,iclust-1);
  }
  if(type=="merge" || type=="both"){
    M->greedy_merge();
  }

  List obs_stats = M->get_obs_stats();
  sol.slot("model") = model;
  sol.slot("obs_stats") = obs_stats;
  sol.slot("cl") = M->get_cl()+1 ;
  sol.slot("icl") = M->icl(obs_stats);
  sol.slot("K") = M->get_K();
  delete M;
  return(sol);
}

// [[Rcpp::export]]
S4 merge_cstr(S4 model,List data,  arma::vec& clt,arma::sp_mat & merge_graph,bool verbose=false) {
  IclModel * M = init(model,data,clt,verbose);
  S4 sol = init_sol(model);
  Rcout << "Merge" << std::endl;
  M->nasty_delta_merge(merge_graph);

  List obs_stats = M->get_obs_stats();
  double bicl = M->icl(obs_stats);
  sol.slot("model") = model;
  sol.slot("obs_stats") = obs_stats;
  sol.slot("cl") = M->get_cl()+1 ;
  sol.slot("icl") = bicl;
  sol.slot("K") = M->get_K();
  // List path = M->greedy_merge_path();
  // for(int i=0;i<path.length();++i){
  //   List cp = path[i];
  //   if(as<double>(cp["icl1"])>bicl){
  //     bicl = as<double>(cp["icl1"]);
  //     sol.slot("obs_stats") = as<List>(cp["obs_stats"]);
  //     sol.slot("cl") = as<arma::vec>(cp["cl"]) ;
  //     sol.slot("icl") = bicl;
  //     sol.slot("K") = as<int>(cp["K"]);
  //   }
  // }


  delete M;
  return(sol);
}

//' fit_greed
//' @param model icl_model
//' @param data list with clustering data (fileds depend on model type)
//' @param clt cluster labels {0,...,K-1}
//' @param type merge, swap, none, or both (default)  
//' @param nb_max_pass maximum number of pass for greedy swap
//' @param verbose boolean for verbose mode default to false
//' @return a model_fit object  
//' @export
// [[Rcpp::export]]
S4 fit_greed(S4 model,List data,  arma::vec& clt,std::string type="both", int nb_max_pass = 50,bool verbose=false) {

  int N = clt.n_elem;
  arma::vec workingset = arma::ones(N);
  int Ki = arma::max(clt);
  arma::uvec iclust = arma::find(arma::ones(Ki))+1;
  S4 sol = fit_greed_cstr(model,data,clt,workingset,iclust,type,nb_max_pass,verbose);
  return(sol);
}

//' fit_greed_path
//' @param data list with clustering data depnds on model type
//' @param init_fit initial fit object
//' @return a model_path object
//' @export
// [[Rcpp::export]]
S4 fit_greed_path(List data, S4 init_fit) {
  S4 model = init_fit.slot("model");
  arma::vec clt = init_fit.slot("cl");
  IclModel * M = init(model,data,clt,false);
  S4 sol = init_sol(model,"path");
  List obs_stats = M->get_obs_stats();
  sol.slot("obs_stats") = obs_stats;
  sol.slot("cl") = M->get_cl()+1 ;
  sol.slot("icl") = M->icl(obs_stats);
  sol.slot("K") = M->get_K();
  sol.slot("path") = M->greedy_merge_path();
  delete M;
  return(sol);
  
}




