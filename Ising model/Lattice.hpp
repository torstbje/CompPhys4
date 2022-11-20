#include <vector>
#ifndef LATTICE_HPP
#define LATTICE_HPP
class Lattice
{
public:
	Particle* first;
	Particle* current;
	int L;											// Lattice length
	int N;											// Number of particles
	double T;										// Temperature
	int total_energy = 0;
	int total_magnetization = 0;

	// Values used by acceptence function for spin flips. Dependent on temperature
	double f4;
	double f8;

	Lattice(const int dim, Particle* particles,double temperature);
	void connect_particles(Particle* particles);
	bool test_lattice();
	void traverse(int n_south, int n_east);
	void find_energy_magnetization();
	bool acceptence(int d_energy);
	void attempt_flip();

};
#endif