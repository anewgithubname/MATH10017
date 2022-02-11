A <- matrix(rnorm(500*28*28), nrow = 500, byrow = T)
B <- matrix(rnorm(500*28*28), nrow = 500, byrow = T)

# A <- matrix(1:4,nrow = 2, byrow = T)
# B <- matrix(5:8,nrow = 2, byrow = T)

pdist1 <- function(A,B){
  D <- matrix(0, nrow = dim(A)[1], ncol = dim(B)[1])
  for (i in 1:dim(A)[1]){
    for (j in 1:dim(B)[1]){
      for (k in 1:dim(A)[2]){
        D[i,j] <- D[i,j] + (A[i,k] - B[j,k])^2
      }
      D[i,j] <- sqrt(D[i,j])
    }
  }
  return(D)
}

pdist2 <- function(A,B){
  D <- matrix(0, nrow = dim(A)[1], ncol = dim(B)[1])
  for (i in 1:dim(A)[1]){
    for (j in 1:dim(B)[1]){
      D[i,j] <- sqrt(sum((A[i,] - B[j,])^2))
    }
  }
  return(D)
}

pdist3 <- function(A,B){
  D <- matrix(0, nrow = dim(A)[1], ncol = dim(B)[1])
  for (i in 1:dim(A)[1]){
    t1 <- sum(A[i,]^2)
    t2 <- rowSums(B^2)
    t3 <- A[i,]%*%t(B)
    
    D[i,] <- sqrt(t1 - 2*t3 + t2)
  }
  return(D)
}