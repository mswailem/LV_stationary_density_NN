In this project I will use neural networks to predict the stationary density values of the Lotka Volterra model by inputting the reaction rates.

This is still a work in progress.

I have implemented a C++ code that handles the data generation. I am using multi-threading to speed up the data generatin process. The data I am generating are the three rate values (features):
Death rate
Birth rate
Predation rate
and their output is the stationary density values (2 values)

Each rate value is choosen randomly using a uniform distriubtion from 0.1 to 10.1.

I have tested my code so far with a batch_size of 3 threads, and a total of batchsize^3 data points.

This takes around 2m and 54s to generate those 27 data points on my machine.

My aim is to generate 1000 data points (might end up generating more in the future) and then use those 1000 data points to train and test the neural network.

Future Plans:
	- Generate the 1000 data points
	- Implement the neural networks

Possible issues that I might encounter:
The system has three phases with two absorbing states: total exctinction (both prey and predator densities are zero), and prey fixation (predator density is zero, prey density is 1). The active phase is the coexistence phase with non-zero density values for the predator and prey. Therefore, this might lead to issues with the neural network not being able to distinguish between the three phases (since their boundaries are not smooth, but they are continous). One possible solution is to feed my data into a classifier before feeding it into the neural network
