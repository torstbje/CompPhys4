
#ifndef FUNCS_HPP
#define FUNCS_HPP


namespace ising {
	void mcmc_calculate(Lattice& lattice, int cycles, int burn_cycles, std::string filename, double* values);
	void mcmc_calculate(Lattice& lattice, int cycles, std::string filename, double* values);
	double susceptibility(double temperature, int n_particles, double mean_mag, double mean_sq_mag);
	double specific_heat_capacity(double temperature, int n_particles, double mean_energy, double mean_sq_energy);
	void fill_particle_list(int n_particles, std::vector<Particle> &particles, bool aligned);
};
#endif
