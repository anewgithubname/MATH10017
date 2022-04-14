#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
NumericMatrix pdist5(NumericMatrix A, NumericMatrix B) {
  NumericMatrix D(A.rows(), B.rows());
  
  for(int i = 0; i < A.rows(); i++){
    for(int j = 0; j < B.rows(); j++){
      double minval = 999999;
      for(int k = 0; k < A.cols(); k++){
        double diff = fabs(A(i,k)-B(j,k));
        if( diff <= minval){
          minval = diff;
        }
      }
      D(i,j) = minval;
    }
  }
  
  return D; 
}

