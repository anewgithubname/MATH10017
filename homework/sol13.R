# Rejection Sampling, Song Liu (song.liu@bristol.ac.uk)
# The following code is for educational purpose only. All rights reserved. 

# generating big matrices. 
A <- matrix(rnorm(500*28*28), nrow = 500, byrow = T)
B <- matrix(rnorm(500*28*28), nrow = 500, byrow = T)

# # two smaller matrices for testing purposes. 
# A <- matrix(1:4, nrow = 2, byrow = T)
# B <- matrix(5:8, nrow = 2, byrow = T)

# Version 1, No vectorization 
pdist1 <- function(A,B){
  # Create a zero matrix D, storing our pairwise distance. 
  D <- matrix(0, nrow = dim(A)[1], ncol = dim(B)[1])
  
  # loop over rows of A
  for (i in 1:dim(A)[1]){
    # Loop over rows of B
    for (j in 1:dim(B)[1]){
      # Compute the *squared* distance. 
      for (k in 1:dim(A)[2]){
        D[i,j] <- D[i,j] + (A[i,k] - B[j,k])^2
      }
      D[i,j] <- sqrt(D[i,j])
    }
  }
  return(D)
}

# Version 2, vectorizing the distance calculation 
pdist2 <- function(A,B){
  # Create a zero matrix D, storing our pairwise distance. 
  D <- matrix(0, nrow = dim(A)[1], ncol = dim(B)[1])
  # loop over rows of A
  for (i in 1:dim(A)[1]){
    # Loop over rows of B
    for (j in 1:dim(B)[1]){
      # Vectorized distance calculation.
      D[i,j] <- sqrt(sum((A[i,] - B[j,])^2))
    }
  }
  return(D)
}

# Version 3, vectorizing distance calculation for every row in D
pdist3 <- function(A,B){
  # Create a zero matrix D, storing our pairwise distance.
  D <- matrix(0, nrow = dim(A)[1], ncol = dim(B)[1])
  # loop over rows of A
  for (i in 1:dim(A)[1]){
    # Vectorized distance calculation for i-th row
    t1 <- sum(A[i,]^2)
    t2 <- rowSums(B^2)
    t3 <- A[i,]%*%t(B)
    
    D[i,] <- sqrt(t1 - 2*t3 + t2)
  }
  return(D)
}

# Version 4, vectorizing the calculation of D
pdist4 <- function(A,B){
  # Create a zero matrix D, storing our pairwise distance.
  D <- matrix(0, nrow = dim(A)[1], ncol = dim(B)[1])
  # Vectorized distance calculation for D
  a <- matrix(rowSums(A^2), nrow = dim(A)[1])
  b <- matrix(rowSums(B^2), nrow = dim(B)[1])
  oneb <- matrix(1, nrow = dim(B)[1]);
  onea <- matrix(1, nrow = dim(A)[1]);
  
  # D = sqrt( a1^T + 1b^T - 2AB )
  D <- sqrt(a%*%t(oneb) + onea%*%t(b) -2*A%*%t(B))
  return(D)
}

# Performance Testing
t1 = Sys.time()
D1 <- pdist1(A,B)
Sys.time() - t1

t1 = Sys.time()
D2 <- pdist2(A,B)
Sys.time() - t1

t1 = Sys.time()
D3 <- pdist3(A,B)
Sys.time() - t1

t1 = Sys.time()
D4 <- pdist4(A,B)
Sys.time() - t1
