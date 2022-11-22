#include<iostream>
#include<vector>
#include<fstream>
#include <cmath>
#include <stdlib.h>
#include <time.h>       /* time */

#include "Particle.hpp"
#include "Lattice.hpp"
#include "funcs.hpp"

using namespace std;

namespace ising {
	
	void mcmc_calculate(Lattice& lattice, int cycles, int burn_cycles, string filename, double* values) {
		/* Overload function to perform burn cycles before data is collected */
		for (int i = 0; i < burn_cycles; i++) {
			lattice.monte_carlo_cycle();
		}
		mcmc_calculate(lattice, cycles, filename, values);

	}

	void mcmc_calculate(Lattice& lattice, int cycles, string filename, double* values) {
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
		double mean_energy = 0;
		double mean_sq_energy = 0;
		double mean_magnetization = 0;
		double mean_sq_magnetization = 0 ;
		double c_v = -9999;
		double chi = -9999;

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

        values[0] = c_v;
        values[2] = chi;
		// Success message
		cout << "Finishied simulations successfully \n";
        
	}

	void mc_phase(Lattice& lattice, int cycles, int burn_cycles, double* values) {
		/* Overload function to perform burn cycles before data is collected */
		for (int i = 0; i < burn_cycles; i++) {
			lattice.monte_carlo_cycle();
		}
		mc_phase(lattice, cycles, values);
	}

	void mc_phase(Lattice& lattice, int cycles, double* values) {
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
		double mean_energy = 0;
		double mean_sq_energy = 0;
		double mean_magnetization = 0;
		double mean_sq_magnetization = 0;

		for (int i = 0; i < cycles; i++) {
			// Finds magnetization and energy of lattice state.
			magnetization = lattice.total_magnetization;
			energy = lattice.total_energy;

			// Update cumulative quantities.
			cumu_energy += energy;
			cumu_magnetization += abs(magnetization);
			cumu_sq_energy += energy * energy;
			cumu_sq_magnetization += magnetization * magnetization;

			// Does one Monte Carlo cycle (attempts to flip random spins equal to the number of spins in lattice).
			lattice.monte_carlo_cycle();
		}
		double scale_cycles = 1.0 / (cycles + 1);
		double scale_cycles_spins = scale_cycles / n_spins;
		mean_energy = scale_cycles * cumu_energy;
		mean_magnetization = scale_cycles * cumu_magnetization;
		mean_sq_energy = scale_cycles * cumu_sq_energy;
		mean_sq_magnetization = scale_cycles * cumu_sq_magnetization;

		// Computes the specific heat capacity and the susceptibility, divided by the current number of cycles and add it to the values pointer
		values[0] = mean_energy;																		// Energy
		values[1] = mean_magnetization;																	// Magnetization
		values[2] = specific_heat_capacity(temperature, n_spins, mean_energy, mean_sq_energy);			// C_V
		values[3] = susceptibility(temperature, n_spins, mean_magnetization, mean_sq_magnetization);	// chi
	}

	void mc_find_burn(Lattice& lattice, int cycles,std::string info) {
		/* Used for finding burn-in rate. Writes mean energy and magnetization to file for every mc cycle */

		string filename = "textfiles/burn_" + info + ".txt";
		cout << filename;

		// Number of particles in the lattice.
		int n_spins = lattice.N;

		// Initialization of cumulative values.
		int cumu_energy = 0;
		int cumu_magnetization = 0;

		// Variables used for scaling with respect to number of spins and number of cycles (initialized inside loop).
		double scale;

		// Opens file for writing to
		std::ofstream outfile;
		outfile.open(filename);

		for (int i = 0; i < cycles; i++) {

			// Update cumulative quantities.
			cumu_energy += lattice.total_magnetization;
			cumu_magnetization += abs(lattice.total_energy);

			// Scalefactor for number of cycles and number of particles
			scale = 1.0 / (n_spins*(i + 1));

			// Writes the energy and absolute magnetization of the state to file: 
			// - mean energy per particle
			// - mean magnetization per particle 
			outfile << cumu_energy * scale << " , " << cumu_magnetization * scale << endl;

			// Performs one Monte Carlo cycle (N attempts of flipping spins).
			lattice.monte_carlo_cycle();
		}

		// Closes output file.
		outfile.close();

	}

	double susceptibility(double temperature,int n_particles, double mean_mag, double mean_sq_mag) {
		/* Susceptibility */
		return (mean_sq_mag - mean_mag*mean_mag)/(n_particles*temperature);
	}
	double specific_heat_capacity(double temperature, int n_particles, double mean_energy, double mean_sq_energy) {
		/* Specific heat capacity */
		return (mean_sq_energy - mean_energy * mean_energy) / (n_particles * temperature*temperature);
	}
	void fill_particle_list(int n_particles, std::vector<Particle> &particles,bool aligned) {
		/* Fills the pointer 'particles' with Particle objects with spins decided by the fill_method parameter. */
		
		if (aligned) {
			// Initialize all particles with positive spin.
			for (int i = 0; i < n_particles; i++) {
                particles.push_back(Particle(1, i));
			}
		} else {
			// Initialize all particles randomly chosen spin.
			for (int i = 0; i < n_particles; i++) {
				int r = rand() % 2;
				if (r == 0) {
					r = -1;
				}
				particles.push_back(Particle(r, i));
			}
		}
	}
	void wrong_cmd_input(std::string instruction){

	}
}
