#include "LVSimulator.h"
#include <iostream>
#include <vector>
#include <thread>

//Random number generator to generate the random rates that will generate the training data set
std::random_device rd{};
std::mt19937 rng{rd()};
std::uniform_real_distribution<double> dist{0.0, 1.0};
int simulation_count = 0;

void runSim(LatticeSimulator& sim, int lattice_size, double death_rate, double birth_rate, double pred_rate, int num_of_timesteps, double n0, int wait_time) {
    double* data = sim.run_simulation(lattice_size, death_rate, birth_rate, pred_rate, num_of_timesteps, n0, wait_time);
    std::cout << "Death Rate: " << death_rate << " Birth Rate: " << birth_rate << " Pred Rate: " << pred_rate << " Predator: " << data[0] << " Prey: " << data[1] << " " << "Simulation_count: " << simulation_count << std::endl;
	simulation_count++;
}

int main (int argc, char *argv[]) {
	int batchSize = 3;
	std::vector<LatticeSimulator> sims(std::pow(batchSize, 3));

	/* double*	data; */

	double death_rate;
	double birth_rate;
	double pred_rate;
	//Submitting multiple simulation to 10 threads at a time
	for (int i = 0; i < sims.size(); i += batchSize) {
		std::vector<std::thread> batchThreads;
		for (int j = 0; j < batchSize; j++) {
			//Randomly generate the rates for the simulation
			death_rate = 0.1 + dist(rng) * 10;
			birth_rate = 0.1 + dist(rng) * 10;
			pred_rate = 0.1 + dist(rng) * 10;
			batchThreads.emplace_back(std::thread(runSim, std::ref(sims[i + j]), 256, death_rate, birth_rate,pred_rate , 1000, 0.5, 500));
		}

		for (auto& thread : batchThreads) {
			thread.join();
		}
	}

	return 0;
}
