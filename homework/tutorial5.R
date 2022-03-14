set.seed(2) 

update <- function(x, v) {
  # check for collision with the boundary. 
  v[(x[, 1] > 5 | x[, 1] < -5), 1] = -v[(x[, 1] > 5 | x[, 1] < -5), 1]
  v[(x[, 2] > 5 | x[, 2] < -5), 2] = -v[(x[, 2] > 5 | x[, 2] < -5), 2]
  
  # compute the pressure at this time point. 
  dp <- sum(abs(v[(x[, 1] > 5 | x[, 1] < -5), 1])) + 
        sum(abs(v[(x[, 2] > 5 | x[, 2] < -5), 2]))
  # divide by the surface area of the box
  dp <- dp/20 
  
  x <- x + v
  return(list(x, v, dp))
}

p_list <- c()
# start simulations. Do simulation 100 times. 
for (sim in 1:100) {
  n <- 100
  # initialize molecules with random positions and velocities.
  x <- matrix(runif(n * 2, -1, 1), nrow = n)
  v <- matrix(runif(n * 2, -.5, .5), nrow = n)
  
  max_T <- 500
  # the average pressure
  p <- 0
  for (tt in 1:max_T) {
    # I deleted the plotting code, to speed up. 
    xv <- update(x, v)
    
    x <- xv[[1]]
    v <- xv[[2]]
    
    # p by dp, calculated in update function
    p <- p + xv[[3]]
  }
  
  # average the pressure over 500 seconds. 
  p <- p/max_T

  p_list[sim] <- p
}

# plot histogram for all simulations.
hist(p_list)
