#include <vector>
#ifndef LATTICE_HPP
#define LATTICE_HPP
class Lattice
{
public:
	Particle* first;
	Particle* current;
	int dim_;
	int total_energy = 0;
	int total_magnetization = 0;

	Lattice(const int dim, Particle* particles);
	void connect_particles(Particle* particles);
	bool test_lattice();
	Particle* find_particle(int n, int m);
	void find_energy_magnetization();

};
#endif