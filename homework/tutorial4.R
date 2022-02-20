# Rejection Sampling, Song Liu (song.liu@bristol.ac.uk)
# The following code is for educational purpose only. All rights reserved. 

# number of simulations we want from the distribution. 
n_max = 1000

# density function of the distribution we would like to simulate
pdf <- function(x){
  # your density function does not have to be normalized. 
  return(exp(-(x-1)^2/.5))
}

# a vector, storing all accepted samples. 
acc <- c()
# number of accepted samples
n <- 0
# M, a constant required for rejection sampling. 
M <- 200
while(n < n_max){
  # draw a sample from uniform distribution
  u <- runif(1)
  # draw a sample from standard normal dist. 
  x <- rnorm(1)
  
  # check, do we accept or reject? 
  if(pdf(x)/dnorm(x)/M > u){
    # if accept, we save it to the acc vector
    # acc vector will grow automatically. 
    n <- n+1
    acc[n] <- x
  }
}

# visualize our simulation using histogram
hist(acc)