#include <Rcpp.h>
#include "abf2/loader.hpp"

//' Load an ABF2 file
//' 
//' @param path Path to the file
//' @export
// [[Rcpp::export]]
Rcpp::NumericVector abf2load(Rcpp::String path) {
  std::string path_ = path;
  abf2::detail::SimpleFileMapper m(path);
  abf2::FileMeta meta(m.data());
  abf2::DataLoader load(meta);
  
  Rcpp::NumericVector v(load.alloc_size());
  load.fill_data(m.data(), v.begin());
  v.attr("dim") = Rcpp::Dimension(load.n_tick(), load.n_sweep(), load.n_chan());
  return v;
}