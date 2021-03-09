// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <RcppArmadillo.h>
#include <Rcpp.h>

using namespace Rcpp;

// post_probs
arma::mat post_probs(S4 model, List data, arma::vec& clt);
RcppExport SEXP _greed_post_probs(SEXP modelSEXP, SEXP dataSEXP, SEXP cltSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< S4 >::type model(modelSEXP);
    Rcpp::traits::input_parameter< List >::type data(dataSEXP);
    Rcpp::traits::input_parameter< arma::vec& >::type clt(cltSEXP);
    rcpp_result_gen = Rcpp::wrap(post_probs(model, data, clt));
    return rcpp_result_gen;
END_RCPP
}
// fit_greed_cstr
S4 fit_greed_cstr(S4 model, List data, arma::vec& clt, arma::vec workingset, arma::uvec iclust, std::string type, int nb_max_pass, bool verbose);
RcppExport SEXP _greed_fit_greed_cstr(SEXP modelSEXP, SEXP dataSEXP, SEXP cltSEXP, SEXP workingsetSEXP, SEXP iclustSEXP, SEXP typeSEXP, SEXP nb_max_passSEXP, SEXP verboseSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< S4 >::type model(modelSEXP);
    Rcpp::traits::input_parameter< List >::type data(dataSEXP);
    Rcpp::traits::input_parameter< arma::vec& >::type clt(cltSEXP);
    Rcpp::traits::input_parameter< arma::vec >::type workingset(workingsetSEXP);
    Rcpp::traits::input_parameter< arma::uvec >::type iclust(iclustSEXP);
    Rcpp::traits::input_parameter< std::string >::type type(typeSEXP);
    Rcpp::traits::input_parameter< int >::type nb_max_pass(nb_max_passSEXP);
    Rcpp::traits::input_parameter< bool >::type verbose(verboseSEXP);
    rcpp_result_gen = Rcpp::wrap(fit_greed_cstr(model, data, clt, workingset, iclust, type, nb_max_pass, verbose));
    return rcpp_result_gen;
END_RCPP
}
// merge_cstr
S4 merge_cstr(S4 model, List data, arma::vec& clt, arma::sp_mat& merge_graph, bool verbose);
RcppExport SEXP _greed_merge_cstr(SEXP modelSEXP, SEXP dataSEXP, SEXP cltSEXP, SEXP merge_graphSEXP, SEXP verboseSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< S4 >::type model(modelSEXP);
    Rcpp::traits::input_parameter< List >::type data(dataSEXP);
    Rcpp::traits::input_parameter< arma::vec& >::type clt(cltSEXP);
    Rcpp::traits::input_parameter< arma::sp_mat& >::type merge_graph(merge_graphSEXP);
    Rcpp::traits::input_parameter< bool >::type verbose(verboseSEXP);
    rcpp_result_gen = Rcpp::wrap(merge_cstr(model, data, clt, merge_graph, verbose));
    return rcpp_result_gen;
END_RCPP
}
// swap_cstr
S4 swap_cstr(S4 model, List data, arma::vec& clt, arma::sp_mat& move_mat, int nb_max_pass, bool verbose);
RcppExport SEXP _greed_swap_cstr(SEXP modelSEXP, SEXP dataSEXP, SEXP cltSEXP, SEXP move_matSEXP, SEXP nb_max_passSEXP, SEXP verboseSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< S4 >::type model(modelSEXP);
    Rcpp::traits::input_parameter< List >::type data(dataSEXP);
    Rcpp::traits::input_parameter< arma::vec& >::type clt(cltSEXP);
    Rcpp::traits::input_parameter< arma::sp_mat& >::type move_mat(move_matSEXP);
    Rcpp::traits::input_parameter< int >::type nb_max_pass(nb_max_passSEXP);
    Rcpp::traits::input_parameter< bool >::type verbose(verboseSEXP);
    rcpp_result_gen = Rcpp::wrap(swap_cstr(model, data, clt, move_mat, nb_max_pass, verbose));
    return rcpp_result_gen;
END_RCPP
}
// fit_greed
S4 fit_greed(S4 model, List data, arma::vec& clt, std::string type, int nb_max_pass, bool verbose);
RcppExport SEXP _greed_fit_greed(SEXP modelSEXP, SEXP dataSEXP, SEXP cltSEXP, SEXP typeSEXP, SEXP nb_max_passSEXP, SEXP verboseSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< S4 >::type model(modelSEXP);
    Rcpp::traits::input_parameter< List >::type data(dataSEXP);
    Rcpp::traits::input_parameter< arma::vec& >::type clt(cltSEXP);
    Rcpp::traits::input_parameter< std::string >::type type(typeSEXP);
    Rcpp::traits::input_parameter< int >::type nb_max_pass(nb_max_passSEXP);
    Rcpp::traits::input_parameter< bool >::type verbose(verboseSEXP);
    rcpp_result_gen = Rcpp::wrap(fit_greed(model, data, clt, type, nb_max_pass, verbose));
    return rcpp_result_gen;
END_RCPP
}
// fit_greed_path
S4 fit_greed_path(List data, S4 init_fit);
RcppExport SEXP _greed_fit_greed_path(SEXP dataSEXP, SEXP init_fitSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< List >::type data(dataSEXP);
    Rcpp::traits::input_parameter< S4 >::type init_fit(init_fitSEXP);
    rcpp_result_gen = Rcpp::wrap(fit_greed_path(data, init_fit));
    return rcpp_result_gen;
END_RCPP
}
// merge_mat
arma::mat merge_mat(List data, S4 init_fit);
RcppExport SEXP _greed_merge_mat(SEXP dataSEXP, SEXP init_fitSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< List >::type data(dataSEXP);
    Rcpp::traits::input_parameter< S4 >::type init_fit(init_fitSEXP);
    rcpp_result_gen = Rcpp::wrap(merge_mat(data, init_fit));
    return rcpp_result_gen;
END_RCPP
}
// sp_cross
arma::sp_mat sp_cross(arma::sp_mat colvec, arma::sp_mat rowvec, int self, int oldcl, int newcl, int K);
RcppExport SEXP _greed_sp_cross(SEXP colvecSEXP, SEXP rowvecSEXP, SEXP selfSEXP, SEXP oldclSEXP, SEXP newclSEXP, SEXP KSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::sp_mat >::type colvec(colvecSEXP);
    Rcpp::traits::input_parameter< arma::sp_mat >::type rowvec(rowvecSEXP);
    Rcpp::traits::input_parameter< int >::type self(selfSEXP);
    Rcpp::traits::input_parameter< int >::type oldcl(oldclSEXP);
    Rcpp::traits::input_parameter< int >::type newcl(newclSEXP);
    Rcpp::traits::input_parameter< int >::type K(KSEXP);
    rcpp_result_gen = Rcpp::wrap(sp_cross(colvec, rowvec, self, oldcl, newcl, K));
    return rcpp_result_gen;
END_RCPP
}
// add_sppat
arma::sp_mat add_sppat(const arma::sp_mat& a, const arma::sp_mat& b);
RcppExport SEXP _greed_add_sppat(SEXP aSEXP, SEXP bSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::sp_mat& >::type a(aSEXP);
    Rcpp::traits::input_parameter< const arma::sp_mat& >::type b(bSEXP);
    rcpp_result_gen = Rcpp::wrap(add_sppat(a, b));
    return rcpp_result_gen;
END_RCPP
}
// add_spmatpat
arma::sp_mat add_spmatpat(const arma::sp_mat& a, const arma::sp_mat& b);
RcppExport SEXP _greed_add_spmatpat(SEXP aSEXP, SEXP bSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::sp_mat& >::type a(aSEXP);
    Rcpp::traits::input_parameter< const arma::sp_mat& >::type b(bSEXP);
    rcpp_result_gen = Rcpp::wrap(add_spmatpat(a, b));
    return rcpp_result_gen;
END_RCPP
}
// which_spmatpat
arma::sp_mat which_spmatpat(const arma::sp_mat& a, const arma::sp_mat& b);
RcppExport SEXP _greed_which_spmatpat(SEXP aSEXP, SEXP bSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::sp_mat& >::type a(aSEXP);
    Rcpp::traits::input_parameter< const arma::sp_mat& >::type b(bSEXP);
    rcpp_result_gen = Rcpp::wrap(which_spmatpat(a, b));
    return rcpp_result_gen;
END_RCPP
}
// delcol
arma::sp_mat delcol(const arma::sp_mat& a, int ci);
RcppExport SEXP _greed_delcol(SEXP aSEXP, SEXP ciSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::sp_mat& >::type a(aSEXP);
    Rcpp::traits::input_parameter< int >::type ci(ciSEXP);
    rcpp_result_gen = Rcpp::wrap(delcol(a, ci));
    return rcpp_result_gen;
END_RCPP
}
// delrowcol
void delrowcol(arma::sp_mat& a, int ci);
RcppExport SEXP _greed_delrowcol(SEXP aSEXP, SEXP ciSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::sp_mat& >::type a(aSEXP);
    Rcpp::traits::input_parameter< int >::type ci(ciSEXP);
    delrowcol(a, ci);
    return R_NilValue;
END_RCPP
}
// gsum_cube
arma::cube gsum_cube(arma::vec cl, const arma::cube& x, int K);
RcppExport SEXP _greed_gsum_cube(SEXP clSEXP, SEXP xSEXP, SEXP KSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::vec >::type cl(clSEXP);
    Rcpp::traits::input_parameter< const arma::cube& >::type x(xSEXP);
    Rcpp::traits::input_parameter< int >::type K(KSEXP);
    rcpp_result_gen = Rcpp::wrap(gsum_cube(cl, x, K));
    return rcpp_result_gen;
END_RCPP
}
// gsum_mat
arma::mat gsum_mat(arma::vec cl, const arma::sp_mat& x, int K);
RcppExport SEXP _greed_gsum_mat(SEXP clSEXP, SEXP xSEXP, SEXP KSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::vec >::type cl(clSEXP);
    Rcpp::traits::input_parameter< const arma::sp_mat& >::type x(xSEXP);
    Rcpp::traits::input_parameter< int >::type K(KSEXP);
    rcpp_result_gen = Rcpp::wrap(gsum_mat(cl, x, K));
    return rcpp_result_gen;
END_RCPP
}
// gsum_bimat
arma::mat gsum_bimat(arma::vec clr, arma::vec clc, const arma::sp_mat& x, int K);
RcppExport SEXP _greed_gsum_bimat(SEXP clrSEXP, SEXP clcSEXP, SEXP xSEXP, SEXP KSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::vec >::type clr(clrSEXP);
    Rcpp::traits::input_parameter< arma::vec >::type clc(clcSEXP);
    Rcpp::traits::input_parameter< const arma::sp_mat& >::type x(xSEXP);
    Rcpp::traits::input_parameter< int >::type K(KSEXP);
    rcpp_result_gen = Rcpp::wrap(gsum_bimat(clr, clc, x, K));
    return rcpp_result_gen;
END_RCPP
}
// gsum_mat_sp
arma::sp_mat gsum_mat_sp(arma::vec cl, const arma::sp_mat& x, int K);
RcppExport SEXP _greed_gsum_mat_sp(SEXP clSEXP, SEXP xSEXP, SEXP KSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::vec >::type cl(clSEXP);
    Rcpp::traits::input_parameter< const arma::sp_mat& >::type x(xSEXP);
    Rcpp::traits::input_parameter< int >::type K(KSEXP);
    rcpp_result_gen = Rcpp::wrap(gsum_mat_sp(cl, x, K));
    return rcpp_result_gen;
END_RCPP
}
// gsum_mm
arma::sp_mat gsum_mm(arma::vec cl, const arma::sp_mat& x, int K);
RcppExport SEXP _greed_gsum_mm(SEXP clSEXP, SEXP xSEXP, SEXP KSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::vec >::type cl(clSEXP);
    Rcpp::traits::input_parameter< const arma::sp_mat& >::type x(xSEXP);
    Rcpp::traits::input_parameter< int >::type K(KSEXP);
    rcpp_result_gen = Rcpp::wrap(gsum_mm(cl, x, K));
    return rcpp_result_gen;
END_RCPP
}
// lm_post
List lm_post(const arma::mat X, const arma::colvec& y, double regu, double a0, double b0);
RcppExport SEXP _greed_lm_post(SEXP XSEXP, SEXP ySEXP, SEXP reguSEXP, SEXP a0SEXP, SEXP b0SEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::mat >::type X(XSEXP);
    Rcpp::traits::input_parameter< const arma::colvec& >::type y(ySEXP);
    Rcpp::traits::input_parameter< double >::type regu(reguSEXP);
    Rcpp::traits::input_parameter< double >::type a0(a0SEXP);
    Rcpp::traits::input_parameter< double >::type b0(b0SEXP);
    rcpp_result_gen = Rcpp::wrap(lm_post(X, y, regu, a0, b0));
    return rcpp_result_gen;
END_RCPP
}
// lm_post_add1
List lm_post_add1(List current, const arma::rowvec X, double y, double regu, double a0, double b0);
RcppExport SEXP _greed_lm_post_add1(SEXP currentSEXP, SEXP XSEXP, SEXP ySEXP, SEXP reguSEXP, SEXP a0SEXP, SEXP b0SEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< List >::type current(currentSEXP);
    Rcpp::traits::input_parameter< const arma::rowvec >::type X(XSEXP);
    Rcpp::traits::input_parameter< double >::type y(ySEXP);
    Rcpp::traits::input_parameter< double >::type regu(reguSEXP);
    Rcpp::traits::input_parameter< double >::type a0(a0SEXP);
    Rcpp::traits::input_parameter< double >::type b0(b0SEXP);
    rcpp_result_gen = Rcpp::wrap(lm_post_add1(current, X, y, regu, a0, b0));
    return rcpp_result_gen;
END_RCPP
}
// lm_post_del1
List lm_post_del1(List current, const arma::rowvec X, double y, double regu, double a0, double b0);
RcppExport SEXP _greed_lm_post_del1(SEXP currentSEXP, SEXP XSEXP, SEXP ySEXP, SEXP reguSEXP, SEXP a0SEXP, SEXP b0SEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< List >::type current(currentSEXP);
    Rcpp::traits::input_parameter< const arma::rowvec >::type X(XSEXP);
    Rcpp::traits::input_parameter< double >::type y(ySEXP);
    Rcpp::traits::input_parameter< double >::type regu(reguSEXP);
    Rcpp::traits::input_parameter< double >::type a0(a0SEXP);
    Rcpp::traits::input_parameter< double >::type b0(b0SEXP);
    rcpp_result_gen = Rcpp::wrap(lm_post_del1(current, X, y, regu, a0, b0));
    return rcpp_result_gen;
END_RCPP
}
// lm_post_merge
List lm_post_merge(List current_k, List current_l, double regu, double a0, double b0);
RcppExport SEXP _greed_lm_post_merge(SEXP current_kSEXP, SEXP current_lSEXP, SEXP reguSEXP, SEXP a0SEXP, SEXP b0SEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< List >::type current_k(current_kSEXP);
    Rcpp::traits::input_parameter< List >::type current_l(current_lSEXP);
    Rcpp::traits::input_parameter< double >::type regu(reguSEXP);
    Rcpp::traits::input_parameter< double >::type a0(a0SEXP);
    Rcpp::traits::input_parameter< double >::type b0(b0SEXP);
    rcpp_result_gen = Rcpp::wrap(lm_post_merge(current_k, current_l, regu, a0, b0));
    return rcpp_result_gen;
END_RCPP
}
// lm_post_add
List lm_post_add(List current, const arma::mat X, const arma::colvec& y, double regu, double a0, double b0);
RcppExport SEXP _greed_lm_post_add(SEXP currentSEXP, SEXP XSEXP, SEXP ySEXP, SEXP reguSEXP, SEXP a0SEXP, SEXP b0SEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< List >::type current(currentSEXP);
    Rcpp::traits::input_parameter< const arma::mat >::type X(XSEXP);
    Rcpp::traits::input_parameter< const arma::colvec& >::type y(ySEXP);
    Rcpp::traits::input_parameter< double >::type regu(reguSEXP);
    Rcpp::traits::input_parameter< double >::type a0(a0SEXP);
    Rcpp::traits::input_parameter< double >::type b0(b0SEXP);
    rcpp_result_gen = Rcpp::wrap(lm_post_add(current, X, y, regu, a0, b0));
    return rcpp_result_gen;
END_RCPP
}
// lm_post_del
List lm_post_del(List current, const arma::mat X, const arma::colvec& y, double regu, double a0, double b0);
RcppExport SEXP _greed_lm_post_del(SEXP currentSEXP, SEXP XSEXP, SEXP ySEXP, SEXP reguSEXP, SEXP a0SEXP, SEXP b0SEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< List >::type current(currentSEXP);
    Rcpp::traits::input_parameter< const arma::mat >::type X(XSEXP);
    Rcpp::traits::input_parameter< const arma::colvec& >::type y(ySEXP);
    Rcpp::traits::input_parameter< double >::type regu(reguSEXP);
    Rcpp::traits::input_parameter< double >::type a0(a0SEXP);
    Rcpp::traits::input_parameter< double >::type b0(b0SEXP);
    rcpp_result_gen = Rcpp::wrap(lm_post_del(current, X, y, regu, a0, b0));
    return rcpp_result_gen;
END_RCPP
}
// mvlm_post_comp
List mvlm_post_comp(const arma::mat X, const arma::mat Y, const arma::mat M, const arma::mat K, const arma::mat S0, double N0);
RcppExport SEXP _greed_mvlm_post_comp(SEXP XSEXP, SEXP YSEXP, SEXP MSEXP, SEXP KSEXP, SEXP S0SEXP, SEXP N0SEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::mat >::type X(XSEXP);
    Rcpp::traits::input_parameter< const arma::mat >::type Y(YSEXP);
    Rcpp::traits::input_parameter< const arma::mat >::type M(MSEXP);
    Rcpp::traits::input_parameter< const arma::mat >::type K(KSEXP);
    Rcpp::traits::input_parameter< const arma::mat >::type S0(S0SEXP);
    Rcpp::traits::input_parameter< double >::type N0(N0SEXP);
    rcpp_result_gen = Rcpp::wrap(mvlm_post_comp(X, Y, M, K, S0, N0));
    return rcpp_result_gen;
END_RCPP
}
// mvlm_post_add1_comp
List mvlm_post_add1_comp(List current, const arma::rowvec X, const arma::rowvec Y, const arma::mat M, const arma::mat K, const arma::mat S0, double N0);
RcppExport SEXP _greed_mvlm_post_add1_comp(SEXP currentSEXP, SEXP XSEXP, SEXP YSEXP, SEXP MSEXP, SEXP KSEXP, SEXP S0SEXP, SEXP N0SEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< List >::type current(currentSEXP);
    Rcpp::traits::input_parameter< const arma::rowvec >::type X(XSEXP);
    Rcpp::traits::input_parameter< const arma::rowvec >::type Y(YSEXP);
    Rcpp::traits::input_parameter< const arma::mat >::type M(MSEXP);
    Rcpp::traits::input_parameter< const arma::mat >::type K(KSEXP);
    Rcpp::traits::input_parameter< const arma::mat >::type S0(S0SEXP);
    Rcpp::traits::input_parameter< double >::type N0(N0SEXP);
    rcpp_result_gen = Rcpp::wrap(mvlm_post_add1_comp(current, X, Y, M, K, S0, N0));
    return rcpp_result_gen;
END_RCPP
}
// mvlm_post_del1_comp
List mvlm_post_del1_comp(List current, const arma::rowvec X, const arma::rowvec Y, const arma::mat M, const arma::mat K, const arma::mat S0, double N0);
RcppExport SEXP _greed_mvlm_post_del1_comp(SEXP currentSEXP, SEXP XSEXP, SEXP YSEXP, SEXP MSEXP, SEXP KSEXP, SEXP S0SEXP, SEXP N0SEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< List >::type current(currentSEXP);
    Rcpp::traits::input_parameter< const arma::rowvec >::type X(XSEXP);
    Rcpp::traits::input_parameter< const arma::rowvec >::type Y(YSEXP);
    Rcpp::traits::input_parameter< const arma::mat >::type M(MSEXP);
    Rcpp::traits::input_parameter< const arma::mat >::type K(KSEXP);
    Rcpp::traits::input_parameter< const arma::mat >::type S0(S0SEXP);
    Rcpp::traits::input_parameter< double >::type N0(N0SEXP);
    rcpp_result_gen = Rcpp::wrap(mvlm_post_del1_comp(current, X, Y, M, K, S0, N0));
    return rcpp_result_gen;
END_RCPP
}
// mvlm_post_merge_comp
List mvlm_post_merge_comp(List current1, List current2, const arma::mat M, const arma::mat K, const arma::mat S0, double N0);
RcppExport SEXP _greed_mvlm_post_merge_comp(SEXP current1SEXP, SEXP current2SEXP, SEXP MSEXP, SEXP KSEXP, SEXP S0SEXP, SEXP N0SEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< List >::type current1(current1SEXP);
    Rcpp::traits::input_parameter< List >::type current2(current2SEXP);
    Rcpp::traits::input_parameter< const arma::mat >::type M(MSEXP);
    Rcpp::traits::input_parameter< const arma::mat >::type K(KSEXP);
    Rcpp::traits::input_parameter< const arma::mat >::type S0(S0SEXP);
    Rcpp::traits::input_parameter< double >::type N0(N0SEXP);
    rcpp_result_gen = Rcpp::wrap(mvlm_post_merge_comp(current1, current2, M, K, S0, N0));
    return rcpp_result_gen;
END_RCPP
}
// gmm_marginal
List gmm_marginal(const arma::mat X, double tau, int N0i, const arma::mat epsilon, const arma::rowvec mu);
RcppExport SEXP _greed_gmm_marginal(SEXP XSEXP, SEXP tauSEXP, SEXP N0iSEXP, SEXP epsilonSEXP, SEXP muSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::mat >::type X(XSEXP);
    Rcpp::traits::input_parameter< double >::type tau(tauSEXP);
    Rcpp::traits::input_parameter< int >::type N0i(N0iSEXP);
    Rcpp::traits::input_parameter< const arma::mat >::type epsilon(epsilonSEXP);
    Rcpp::traits::input_parameter< const arma::rowvec >::type mu(muSEXP);
    rcpp_result_gen = Rcpp::wrap(gmm_marginal(X, tau, N0i, epsilon, mu));
    return rcpp_result_gen;
END_RCPP
}
// gmm_marginal_eb
List gmm_marginal_eb(const arma::mat X, double tau, int N0i, const arma::mat epsilon, const arma::rowvec mu);
RcppExport SEXP _greed_gmm_marginal_eb(SEXP XSEXP, SEXP tauSEXP, SEXP N0iSEXP, SEXP epsilonSEXP, SEXP muSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::mat >::type X(XSEXP);
    Rcpp::traits::input_parameter< double >::type tau(tauSEXP);
    Rcpp::traits::input_parameter< int >::type N0i(N0iSEXP);
    Rcpp::traits::input_parameter< const arma::mat >::type epsilon(epsilonSEXP);
    Rcpp::traits::input_parameter< const arma::rowvec >::type mu(muSEXP);
    rcpp_result_gen = Rcpp::wrap(gmm_marginal_eb(X, tau, N0i, epsilon, mu));
    return rcpp_result_gen;
END_RCPP
}
// gmm_marginal_add1
List gmm_marginal_add1(List current, const arma::rowvec X, double tau, int N0i, const arma::mat epsilon, const arma::rowvec mu);
RcppExport SEXP _greed_gmm_marginal_add1(SEXP currentSEXP, SEXP XSEXP, SEXP tauSEXP, SEXP N0iSEXP, SEXP epsilonSEXP, SEXP muSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< List >::type current(currentSEXP);
    Rcpp::traits::input_parameter< const arma::rowvec >::type X(XSEXP);
    Rcpp::traits::input_parameter< double >::type tau(tauSEXP);
    Rcpp::traits::input_parameter< int >::type N0i(N0iSEXP);
    Rcpp::traits::input_parameter< const arma::mat >::type epsilon(epsilonSEXP);
    Rcpp::traits::input_parameter< const arma::rowvec >::type mu(muSEXP);
    rcpp_result_gen = Rcpp::wrap(gmm_marginal_add1(current, X, tau, N0i, epsilon, mu));
    return rcpp_result_gen;
END_RCPP
}
// gmm_marginal_add1_eb
List gmm_marginal_add1_eb(List current, const arma::rowvec X, double tau, int N0i, const arma::mat epsilon, const arma::rowvec mu);
RcppExport SEXP _greed_gmm_marginal_add1_eb(SEXP currentSEXP, SEXP XSEXP, SEXP tauSEXP, SEXP N0iSEXP, SEXP epsilonSEXP, SEXP muSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< List >::type current(currentSEXP);
    Rcpp::traits::input_parameter< const arma::rowvec >::type X(XSEXP);
    Rcpp::traits::input_parameter< double >::type tau(tauSEXP);
    Rcpp::traits::input_parameter< int >::type N0i(N0iSEXP);
    Rcpp::traits::input_parameter< const arma::mat >::type epsilon(epsilonSEXP);
    Rcpp::traits::input_parameter< const arma::rowvec >::type mu(muSEXP);
    rcpp_result_gen = Rcpp::wrap(gmm_marginal_add1_eb(current, X, tau, N0i, epsilon, mu));
    return rcpp_result_gen;
END_RCPP
}
// gmm_marginal_del1
List gmm_marginal_del1(List current, const arma::rowvec X, double tau, int N0i, const arma::mat epsilon, const arma::rowvec mu);
RcppExport SEXP _greed_gmm_marginal_del1(SEXP currentSEXP, SEXP XSEXP, SEXP tauSEXP, SEXP N0iSEXP, SEXP epsilonSEXP, SEXP muSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< List >::type current(currentSEXP);
    Rcpp::traits::input_parameter< const arma::rowvec >::type X(XSEXP);
    Rcpp::traits::input_parameter< double >::type tau(tauSEXP);
    Rcpp::traits::input_parameter< int >::type N0i(N0iSEXP);
    Rcpp::traits::input_parameter< const arma::mat >::type epsilon(epsilonSEXP);
    Rcpp::traits::input_parameter< const arma::rowvec >::type mu(muSEXP);
    rcpp_result_gen = Rcpp::wrap(gmm_marginal_del1(current, X, tau, N0i, epsilon, mu));
    return rcpp_result_gen;
END_RCPP
}
// gmm_marginal_del1_eb
List gmm_marginal_del1_eb(List current, const arma::rowvec X, double tau, int N0i, const arma::mat epsilon, const arma::rowvec mu);
RcppExport SEXP _greed_gmm_marginal_del1_eb(SEXP currentSEXP, SEXP XSEXP, SEXP tauSEXP, SEXP N0iSEXP, SEXP epsilonSEXP, SEXP muSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< List >::type current(currentSEXP);
    Rcpp::traits::input_parameter< const arma::rowvec >::type X(XSEXP);
    Rcpp::traits::input_parameter< double >::type tau(tauSEXP);
    Rcpp::traits::input_parameter< int >::type N0i(N0iSEXP);
    Rcpp::traits::input_parameter< const arma::mat >::type epsilon(epsilonSEXP);
    Rcpp::traits::input_parameter< const arma::rowvec >::type mu(muSEXP);
    rcpp_result_gen = Rcpp::wrap(gmm_marginal_del1_eb(current, X, tau, N0i, epsilon, mu));
    return rcpp_result_gen;
END_RCPP
}
// gmm_marginal_merge
List gmm_marginal_merge(List current1, List current2, double tau, int N0i, const arma::mat epsilon, const arma::rowvec mu);
RcppExport SEXP _greed_gmm_marginal_merge(SEXP current1SEXP, SEXP current2SEXP, SEXP tauSEXP, SEXP N0iSEXP, SEXP epsilonSEXP, SEXP muSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< List >::type current1(current1SEXP);
    Rcpp::traits::input_parameter< List >::type current2(current2SEXP);
    Rcpp::traits::input_parameter< double >::type tau(tauSEXP);
    Rcpp::traits::input_parameter< int >::type N0i(N0iSEXP);
    Rcpp::traits::input_parameter< const arma::mat >::type epsilon(epsilonSEXP);
    Rcpp::traits::input_parameter< const arma::rowvec >::type mu(muSEXP);
    rcpp_result_gen = Rcpp::wrap(gmm_marginal_merge(current1, current2, tau, N0i, epsilon, mu));
    return rcpp_result_gen;
END_RCPP
}
// gmm_marginal_merge_eb
List gmm_marginal_merge_eb(List current1, List current2, double tau, int N0i, const arma::mat epsilon, const arma::rowvec mu);
RcppExport SEXP _greed_gmm_marginal_merge_eb(SEXP current1SEXP, SEXP current2SEXP, SEXP tauSEXP, SEXP N0iSEXP, SEXP epsilonSEXP, SEXP muSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< List >::type current1(current1SEXP);
    Rcpp::traits::input_parameter< List >::type current2(current2SEXP);
    Rcpp::traits::input_parameter< double >::type tau(tauSEXP);
    Rcpp::traits::input_parameter< int >::type N0i(N0iSEXP);
    Rcpp::traits::input_parameter< const arma::mat >::type epsilon(epsilonSEXP);
    Rcpp::traits::input_parameter< const arma::rowvec >::type mu(muSEXP);
    rcpp_result_gen = Rcpp::wrap(gmm_marginal_merge_eb(current1, current2, tau, N0i, epsilon, mu));
    return rcpp_result_gen;
END_RCPP
}
// possible_moves
arma::uvec possible_moves(int k, arma::sp_mat& move_mat);
RcppExport SEXP _greed_possible_moves(SEXP kSEXP, SEXP move_matSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< int >::type k(kSEXP);
    Rcpp::traits::input_parameter< arma::sp_mat& >::type move_mat(move_matSEXP);
    rcpp_result_gen = Rcpp::wrap(possible_moves(k, move_mat));
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_greed_post_probs", (DL_FUNC) &_greed_post_probs, 3},
    {"_greed_fit_greed_cstr", (DL_FUNC) &_greed_fit_greed_cstr, 8},
    {"_greed_merge_cstr", (DL_FUNC) &_greed_merge_cstr, 5},
    {"_greed_swap_cstr", (DL_FUNC) &_greed_swap_cstr, 6},
    {"_greed_fit_greed", (DL_FUNC) &_greed_fit_greed, 6},
    {"_greed_fit_greed_path", (DL_FUNC) &_greed_fit_greed_path, 2},
    {"_greed_merge_mat", (DL_FUNC) &_greed_merge_mat, 2},
    {"_greed_sp_cross", (DL_FUNC) &_greed_sp_cross, 6},
    {"_greed_add_sppat", (DL_FUNC) &_greed_add_sppat, 2},
    {"_greed_add_spmatpat", (DL_FUNC) &_greed_add_spmatpat, 2},
    {"_greed_which_spmatpat", (DL_FUNC) &_greed_which_spmatpat, 2},
    {"_greed_delcol", (DL_FUNC) &_greed_delcol, 2},
    {"_greed_delrowcol", (DL_FUNC) &_greed_delrowcol, 2},
    {"_greed_gsum_cube", (DL_FUNC) &_greed_gsum_cube, 3},
    {"_greed_gsum_mat", (DL_FUNC) &_greed_gsum_mat, 3},
    {"_greed_gsum_bimat", (DL_FUNC) &_greed_gsum_bimat, 4},
    {"_greed_gsum_mat_sp", (DL_FUNC) &_greed_gsum_mat_sp, 3},
    {"_greed_gsum_mm", (DL_FUNC) &_greed_gsum_mm, 3},
    {"_greed_lm_post", (DL_FUNC) &_greed_lm_post, 5},
    {"_greed_lm_post_add1", (DL_FUNC) &_greed_lm_post_add1, 6},
    {"_greed_lm_post_del1", (DL_FUNC) &_greed_lm_post_del1, 6},
    {"_greed_lm_post_merge", (DL_FUNC) &_greed_lm_post_merge, 5},
    {"_greed_lm_post_add", (DL_FUNC) &_greed_lm_post_add, 6},
    {"_greed_lm_post_del", (DL_FUNC) &_greed_lm_post_del, 6},
    {"_greed_mvlm_post_comp", (DL_FUNC) &_greed_mvlm_post_comp, 6},
    {"_greed_mvlm_post_add1_comp", (DL_FUNC) &_greed_mvlm_post_add1_comp, 7},
    {"_greed_mvlm_post_del1_comp", (DL_FUNC) &_greed_mvlm_post_del1_comp, 7},
    {"_greed_mvlm_post_merge_comp", (DL_FUNC) &_greed_mvlm_post_merge_comp, 6},
    {"_greed_gmm_marginal", (DL_FUNC) &_greed_gmm_marginal, 5},
    {"_greed_gmm_marginal_eb", (DL_FUNC) &_greed_gmm_marginal_eb, 5},
    {"_greed_gmm_marginal_add1", (DL_FUNC) &_greed_gmm_marginal_add1, 6},
    {"_greed_gmm_marginal_add1_eb", (DL_FUNC) &_greed_gmm_marginal_add1_eb, 6},
    {"_greed_gmm_marginal_del1", (DL_FUNC) &_greed_gmm_marginal_del1, 6},
    {"_greed_gmm_marginal_del1_eb", (DL_FUNC) &_greed_gmm_marginal_del1_eb, 6},
    {"_greed_gmm_marginal_merge", (DL_FUNC) &_greed_gmm_marginal_merge, 6},
    {"_greed_gmm_marginal_merge_eb", (DL_FUNC) &_greed_gmm_marginal_merge_eb, 6},
    {"_greed_possible_moves", (DL_FUNC) &_greed_possible_moves, 2},
    {NULL, NULL, 0}
};

RcppExport void R_init_greed(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
