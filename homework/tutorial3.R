f <- function (x){
  return(sin(x)^3+x^2+1)
}

df <- function(x){
  return(3*sin(x)^2*cos(x) + 2*x)
}

x <- .5
while( abs(df(x)) > .01){
  x <- x - .1*df(x)
}

# x is the minimizer now. 
# f(x) 

f(x)