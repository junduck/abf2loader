#include <Rcpp.h>
#include "abf2/loader.hpp"

Rcpp::List attr_Header(abf2::FileMeta const &meta);
Rcpp::List attr_Protocol(abf2::FileMeta const &meta);
Rcpp::List attr_ADC(abf2::FileMeta const &meta);
Rcpp::List attr_DAC(abf2::FileMeta const &meta);
Rcpp::List attr_Epoch(abf2::FileMeta const &meta);
Rcpp::List attr_EpochPerDAC(abf2::FileMeta const &meta);
Rcpp::List attr_UserList(abf2::FileMeta const &meta);
Rcpp::List attr_SynchArray(abf2::FileMeta const &meta);

//' Load an ABF2 file
//'
//' @param path Path to the file
//' @export
// [[Rcpp::export]]
Rcpp::NumericVector abf2load(Rcpp::String path) {
#if 0
  abf2::detail::SimpleFileReader m(path);
#else
  abf2::detail::SimpleFileMapper m(path);
#endif
  abf2::FileMeta meta(m.data());
  abf2::DataLoader load(meta);

  Rcpp::NumericVector v(load.alloc_size());
  load.fill_data(m.data(), v.begin());
  v.attr("dim") = Rcpp::Dimension(load.n_tick(), load.n_sweep(), load.n_chan());

  v.attr("header") = attr_Header(meta);
  v.attr("protocol") = attr_Protocol(meta);
  v.attr("adc") =  attr_ADC(meta);
  v.attr("dac") = attr_DAC(meta);
  v.attr("epoch") = attr_Epoch(meta);
  v.attr("epoch_per_dac") = attr_EpochPerDAC(meta);
  v.attr("user_list") = attr_UserList(meta);
  v.attr("synch_array") = attr_SynchArray(meta);

  return v;
}
