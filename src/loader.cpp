#include <Rcpp.h>
#include "abf2/loader.hpp"

Rcpp::List attr_Header(abf2::FileMeta const &meta);
Rcpp::List attr_Protocol(abf2::FileMeta const &meta);
Rcpp::List attr_ADC(abf2::FileMeta const &meta);

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

  return v;
}
