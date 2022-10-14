
# PART A

# Data from system figure
reliability_probabilities <- c(.97, .68, .89, .93)

num_of_components_in_parallel <- c(1, 5, 3, 2)

# function to calculate the reliability of the series-parallel system
calc_system_reliability <- function(num_of_components_in_parallel, reliability_probabilities)
{
  system_reliability_probability <- 1
  
  for(i in 1:length(num_of_components_in_parallel)) # for each component in the series
  {
    p <- reliability_probabilities[i] # take the reliability probability for that component
    nc <- num_of_components_in_parallel[i] # take the number of replicates for that probability
    
    system_reliability_probability <- system_reliability_probability * (1 -((1 - p)^nc)) # we plonk p and nc into our formula and multiply that by the current system_reliability_probability
  }
  
  return(system_reliability_probability) # return our final calculation
}

sprintf("Probability of system working = %f", calc_system_reliability(num_of_components_in_parallel, reliability_probabilities))

# --------------------------------------------------------------------------------------------------------------------------------------------------------------

# PART B

# function to simulation to estimate the reliability of the system
simulate_system_reliability <- function(num_iterations, num_of_components_in_parallel, reliability_probabilities)
{
  sys_success <- 0 # array to stores successes and failures
  fail_count <- 0
  for(i in c(1:num_iterations)) # 100 times in this case
  {
    sys_success[i] <- 1  # assume system succeeds unless all the components fail
    
    for(j in 1:length(num_of_components_in_parallel)) # for each component
    {
      fail_count <- 0 # reset count to 0
      for(k in 1:num_of_components_in_parallel[j]) # for each component in parallel
      {
        if(runif(1) > reliability_probabilities[j]) # check if a number generated between 0 and 1 is greater than the reliability probability for each component
        {
          fail_count <- fail_count + 1 # if so, add 1 to the fail count
        }
      }
      
      if(fail_count == num_of_components_in_parallel[j]) # if all the components in parallel have failed
      {
        sys_success[i] <- 0
        break # go to next iteration of the system reliability test
      }
      
    }
  }
  return(sum(sys_success)/num_iterations) # estimated probability of success
}


result <- simulate_system_reliability(num_iterations = 100, num_of_components_in_parallel, reliability_probabilities)

sprintf("Simulated estimate probability of system working = %f", result)
# ----------------------------------------------------------------------------------------------------------------------------------------------------------------

# PART C

# plot Part B 

iteration_intervals <- seq(1,10000,50)
reliabilities <- 0 # array of estimated probabilities of success
i <- 1

for (iteration_n in iteration_intervals ) # 10,000 times in this  case
{
  reliabilities[i] <- simulate_system_reliability(iteration_n, num_of_components_in_parallel, reliability_probabilities) # call simulation function
  i <- i + 1
}

plot(iteration_intervals, reliabilities, xlab='Number of iterations in simulation', ylab='System Reliability', main='Results for Simulation of Sysetm Reliability', abline(h=calc_system_reliability(num_of_components_in_parallel, reliability_probabilities), col='red')) # plot array

