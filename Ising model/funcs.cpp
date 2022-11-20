#include<iostream>
#include<vector>

#include "Particle.hpp"
#include "Lattice.hpp"
#include "funcs.hpp"

using namespace std;

namespace ising {


	void mcmc_calculate(Lattice& lattice, int cycles) {
		/* Does multiple monte carlo cycles over the lattice, collecting the energy and magnetization for each state */

		int n_spins = lattice.N;
		double temperature = lattice.T;

		double mean_energy = 0.0;
		double mean_magnetization = 0.0;
		double mean_sq_energy = 0.0;
		double mean_sq_magnetization = 0.0;


		int magnetization;
		int energy;
		for (int i = 0; i < cycles; i++) {
			// Finds magnetization and energy of lattice state.
			magnetization = lattice.total_magnetization;
			energy = lattice.total_energy;

			// Accumulates average in quantities of interest.
			mean_energy += energy;
			mean_magnetization += abs(magnetization);
			mean_sq_energy += energy*energy;
			mean_sq_magnetization += magnetization*magnetization;

			// Does one Monte Carlo cycle.
			lattice.monte_carlo_cycle();
		}

		// Divides by number of cycles to find the average
		mean_energy /= cycles;
		mean_magnetization /= cycles;
		mean_sq_energy /= cycles;
		mean_sq_magnetization /= cycles;

		// Computes the specific heat capacity and the susceptibility
		double c_v = specific_heat_capacity(temperature, n_spins, mean_energy, mean_sq_energy);
		double chi = susceptibility(temperature, n_spins, mean_magnetization, mean_sq_magnetization);


		cout << "Cycles: " << cycles << ", C_v: " << c_v << ", susceptibility: " << chi << endl;


	}

	double susceptibility(double temperature,int n_particles, double mean_mag, double mean_sq_mag) {
		return (mean_sq_mag - mean_mag*mean_mag)/(n_particles*temperature);
	}
	double specific_heat_capacity(double temperature, int n_particles, double mean_energy, double mean_sq_energy) {
		return (mean_sq_energy - mean_energy * mean_energy) / (n_particles * temperature*temperature);
	}
	void fill_particle_list(Particle* particles,int n_particles, std::string fill_method) {

		if (fill_method == "up") {
			for (int i = 0; i < n_particles; i++) {
				particles[i] = Particle(1,i);
			}
		}
		else if (fill_method == "down") {
			for (int i = 0; i < n_particles; i++) {
				particles[i] = Particle(-1, i);
			}
		}
		else {
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
