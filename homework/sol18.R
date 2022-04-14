
pdist5_r <- function(A,B){
  D <- matrix(0, nrow = dim(A)[1], ncol = dim(B)[1])
  
  for(i in 1:dim(A)[1]){
    for(j in 1:dim(B)[1]){
      D[i,j] = min(abs(A[i,] - B[j,]))
    }
  }
  
  return(D)
}

A <- matrix(rnorm(500*500), nrow = 500)
B <- matrix(rnorm(500*500), nrow = 500)

t1 <- Sys.time()
D1<- pdist5_r(A,B)
Sys.time() - t1

t1 <- Sys.time()
D2<-pdist5(A,B)
Sys.time() - t1

norm(D1 - D2)
