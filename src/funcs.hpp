
#ifndef FUNCS_HPP
#define FUNCS_HPP


namespace ising {

	//void mc_simple(Lattice& lattice, int cycles);
	//void mc_simple(Lattice& lattice, int cycles, int burn_cycles);

	void mc_phase(Lattice& lattice, int cycles, double* values);
	void mc_phase(Lattice& lattice, int cycles, int burn_cycles, double* values);
	void mc_find_burn(Lattice& lattice, int cycles,std::string filename);
	void mcmc_calculate(Lattice& lattice, int cycles, int burn_cycles, std::string filename, double* values);
	void mcmc_calculate(Lattice& lattice, int cycles, std::string filename, double* values);
	double susceptibility(double temperature, int n_particles, double mean_mag, double mean_sq_mag);
	double specific_heat_capacity(double temperature, int n_particles, double mean_energy, double mean_sq_energy);
	void fill_particle_list(int n_particles, std::vector<Particle> &particles, bool aligned);
	void wrong_cmd_input(std::string instruction);
	std::string make_filename(std::string instruction, bool aligned, double temperature);
};
#endif
