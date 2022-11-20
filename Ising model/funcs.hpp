
#ifndef FUNCS_HPP
#define FUNCS_HPP


namespace ising {

	void mcmc_calculate(Lattice& lattice, int cycles);
	double susceptibility(double temperature, int n_particles, double mean_mag, double mean_sq_mag);
	double specific_heat_capacity(double temperature, int n_particles, double mean_energy, double mean_sq_energy);
	void fill_particle_list(Particle* particles,int n_particles, std::string fill_method);
};
#endif
