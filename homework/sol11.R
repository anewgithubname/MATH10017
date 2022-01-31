start_time <- Sys.time()
n <- 5000

num_prime <- 0

for (i in 2:n){
  num_factors <- 0
  for (j in 1:i){
    if(i %% j == 0){
      num_factors = num_factors + 1
    }
  }
  if (num_factors == 2){
    # print(i)
    num_prime = num_prime + 1
  }
}

print(num_prime)
end_time <- Sys.time()
end_time - start_time
