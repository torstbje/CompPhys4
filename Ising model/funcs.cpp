#include<iostream>
#include<vector>
#include<fstream>
#include <stdlib.h>
#include <time.h>       /* time */

#include "Particle.hpp"
#include "Lattice.hpp"
#include "funcs.hpp"

using namespace std;

namespace ising {
	

	void mcmc_calculate(Lattice& lattice, int cycles, string filename) {
		/* Does multiple monte carlo cycles over the lattice, collecting the energy and magnetization for each state */


		// Collection of lattice specific values.
		int n_spins = lattice.N;
		double temperature = lattice.T;

		// Initialization of cumulative values.
		int cumu_energy = 0;
		int cumu_magnetization = 0;
		int cumu_sq_energy = 0;
		int cumu_sq_magnetization = 0;

		// Declaration for values used inside loop. 
		int energy;
		int magnetization;
		double mean_energy;
		double mean_sq_energy;
		double mean_magnetization;
		double mean_sq_magnetization;
		double c_v;
		double chi;

		// Variables used for scaling with respect to number of spins and number of cycles (initialized inside loop).
		double scale_cycles;
		double scale_spins = 1.0 / n_spins;


		// Opens file for writing to
		std::ofstream outfile;
		outfile.open(filename);

		for (int i = 0; i < cycles; i++) {
			// Finds magnetization and energy of lattice state.
			magnetization = lattice.total_magnetization;
			energy = lattice.total_energy;

			// Update cumulative quantities.
			cumu_energy += energy;
			cumu_magnetization += abs(magnetization);
			cumu_sq_energy += energy*energy;
			cumu_sq_magnetization += magnetization*magnetization;

			// Calculates average values of current number of cycles
			scale_cycles = 1.0 / (i + 1);
			mean_energy = scale_cycles * cumu_energy;
			mean_magnetization = scale_cycles * cumu_magnetization;
			mean_sq_energy = scale_cycles * cumu_sq_energy;
			mean_sq_magnetization = scale_cycles * cumu_sq_magnetization;

			// Computes the specific heat capacity and the susceptibility, divided by the current number of cycles.
			c_v = specific_heat_capacity(temperature, n_spins, mean_energy, mean_sq_energy);
			chi = susceptibility(temperature, n_spins, mean_magnetization, mean_sq_magnetization);


			// Writes the values: 
			// - energy per spin
			// - mean energy per particle
			// - mean magnetization per particle 
			// - specific heat-capacity
			// - susceptibility to file
			outfile << energy * scale_spins << " , " << (mean_energy * scale_spins) << " , " << mean_magnetization * scale_spins << " , " << c_v << " , " << chi << endl;


			// Does one Monte Carlo cycle (attempts to flip random spins equal to the number of spins in lattice).
			lattice.monte_carlo_cycle();
		}

		// Closes output file.
		outfile.close();

		// Success message
		cout << "Finishied simulations successfully \n";
	}

	double susceptibility(double temperature,int n_particles, double mean_mag, double mean_sq_mag) {
		/* Susceptibility */
		return (mean_sq_mag - mean_mag*mean_mag)/(n_particles*temperature);
	}
	double specific_heat_capacity(double temperature, int n_particles, double mean_energy, double mean_sq_energy) {
		/* Specific heat capacity */
		return (mean_sq_energy - mean_energy * mean_energy) / (n_particles * temperature*temperature);
	}
	void fill_particle_list(Particle* particles,int n_particles, std::string fill_method) {
		/* Fills the pointer 'particles' with Particle objects with spins decided by the fill_method parameter. */

		if (fill_method == "up") {
			// Initialize all particles with positive spin.
			for (int i = 0; i < n_particles; i++) {
				particles[i] = Particle(1,i);
			}
		}
		else if (fill_method == "down") {
			// Initialize all particles with negative spin.
			for (int i = 0; i < n_particles; i++) {
				particles[i] = Particle(-1, i);
			}
		}
		else {
			// Initialize all particles randomly chosen spin.
			for (int i = 0; i < n_particles; i++) {
				int r = rand() % 2;
				if (r == 0) {
					r = -1;
				}
				particles[i] = Particle(r, i);
			}
		}
	}
}
