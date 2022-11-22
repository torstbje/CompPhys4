#include<iostream>
#include<vector>
#include<fstream>
#include <cmath>
#include <stdlib.h>
#include <time.h>
#include <string>

#include "Particle.hpp"
#include "Lattice.hpp"
#include "funcs.hpp"

using namespace std;

namespace ising {
	
	void mc_dist(Lattice& lattice, int cycles, int burn_cycles, string filename) {
		/* Overload function to perform burn cycles before data is collected */
		for (int i = 0; i < burn_cycles; i++) {
			lattice.monte_carlo_cycle();
		}
		mc_dist(lattice, cycles, filename);

	}

	void mc_dist(Lattice& lattice, int cycles, string filename) {
		/* Does multiple monte carlo cycles over the lattice, writing down the energy for each state */

		// Declarations
		int n_spins = lattice.N;
		int energy;

		// Variable used to scale for the number or spins
		double scale_spins = 1.0 / n_spins;

		// Opens file for writing to
		std::ofstream outfile;
		outfile.open(filename);

		for (int i = 0; i < cycles; i++) {
			// Collects the energy and writes it to file.
			energy = lattice.total_energy;
			outfile << energy * scale_spins << endl;

			// Does one Monte Carlo cycle (attempts to flip random spins equal to the number of spins in lattice).
			lattice.monte_carlo_cycle();
		}

		// Closes output file.
		outfile.close();
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
		double scale = 1.0 / (n_spins * (cycles + 1));
		double scale_sq = scale / n_spins;
		mean_energy = scale * cumu_energy;
		mean_magnetization = scale * cumu_magnetization;
		mean_sq_energy = scale_sq * cumu_sq_energy;
		mean_sq_magnetization = scale_sq * cumu_sq_magnetization;

		// Computes the specific heat capacity and the susceptibility, divided by the current number of cycles and add it to the values pointer
		values[0] = mean_energy;																		// Energy
		values[1] = mean_magnetization;																	// Magnetization
		values[2] = specific_heat_capacity(temperature, n_spins, mean_energy, mean_sq_energy);			// C_V
		values[3] = susceptibility(temperature, n_spins, mean_magnetization, mean_sq_magnetization);	// chi
	}

	void mc_find_burn(Lattice& lattice, int cycles,std::string filename) {
		/* Used for finding burn-in rate. Writes mean energy and magnetization to file for every mc cycle */

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
			cumu_energy += lattice.total_energy;
			cumu_magnetization += abs(lattice.total_magnetization);

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
		return (mean_sq_mag - mean_mag*mean_mag)/(temperature);
	}
	double specific_heat_capacity(double temperature, int n_particles, double mean_energy, double mean_sq_energy) {
		/* Specific heat capacity */
		return (mean_sq_energy - mean_energy * mean_energy) / (temperature*temperature);
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
	void wrong_cmd_input(std::string instruction) {
		/* Writes error message if the number of arguments is not correct for the given instructions */

		// Is called regardless of what is missing
		std::cout << "To run program with instruction '" << instruction << "', the following parameters : are needed\n"
			"- Run time instruction: " << instruction << "\n"
			"- Aligned spins ('1'/'0') \n"
			"- Number of cycles (integer) \n";

		if (instruction == "burn") {
			std::cout << "- L: length of lattice \n"
				"- T: Temperature (double, unit [J/k_B]) \n";
		}

		if (instruction == "distribution") {
			std::cout << "- L: length of lattice \n";
		}

		if (instruction == "critical") {
			std::cout << "- L: length of lattice \n"
				"- Min temp \n"
				"- Max temp \n"
				"- Number of steps for temperature run\n";
		}
	}

	std::string make_filename(std::string instruction, bool aligned, double temperature) {

		std::string filename = "textfiles/";

		if (instruction == "burn") {
			filename += "burn_";
			if (aligned) {
				filename += "aligned_";
			}
			else {
				filename += "unaligned_";
			}
			filename += std::to_string(temperature).substr(0, std::to_string(temperature).find(".") + 2) + ".txt";
		}
		else if (instruction == "distribution") {
			filename += "dist";
			filename += std::to_string(temperature).substr(0, std::to_string(temperature).find(".") + 2) + ".txt";
		}
		return filename;
	}
	std::string make_filename(std::string instruction, int dim)
	{
		std::string filename = "textfiles/";

		if (instruction == "np_critical") {
			filename += "np_critical" + to_string(dim) + ".txt";
		}
		return filename;
	}
}
