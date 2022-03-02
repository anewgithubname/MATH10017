set.seed(1) 
# update particle positions
update <- function(x,v){
  # checking whether a particle has hit the wall, if so, reflect its velocity.
  v[(x[,1] > 5 | x[,1] < -5),1] = -v[(x[,1] > 5 | x[,1] < -5),1]
  v[(x[,2] > 5 | x[,2] < -5),2] = -v[(x[,2] > 5 | x[,2] < -5),2]
  
  x <- x + v
  return(list(x,v))
}

# initialize particle positions and velocities
x <- matrix(runif(50*2,-1,1), nrow = 50)
v <- matrix(runif(50*2,-.5,.5), nrow = 50)

# start the simulation, press ESC to stop
while(T){
  # plot particles
  plot(c(-5,5),c(-5,5), type = "n", xlab = "x1", ylab = "x2")
  
  points(x[,1], x[,2], col = 'red', lwd = 0, pch = 16)
  # plotting arrows indicating the velocity of the particles
  arrows(x[,1], x[,2], x[,1] + v[,1], x[,2] + v[,2], length = .05 , col = "green")
  title("particle simulation. Press ESC to stop")  
  
  xv <- update(x,v)
  
  print(x)
  print(v)
  x<- xv[[1]]
  v<- xv[[2]]
  
  # sleep a second so rstudio can draw.
  Sys.sleep(.1)
}