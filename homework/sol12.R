a <- c(1,0)
b <- c(1,1)

dist <- function(v1, v2){
  return(sqrt(sum((v1 - v2)^2)))
}

angle <- function(v1, v2){
  return(acos(v1%*%v2/dist(v1,0)/dist(v2,0))/2/pi*360)
}

dist(a,b)
angle(a,b)