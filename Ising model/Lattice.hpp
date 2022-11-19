#include <vector>
#ifndef LATTICE_HPP
#define LATTICE_HPP
class Lattice
{
public:
	Particle* first;
	Particle* current;
	int dim_;

	Lattice(const int dim, Particle* particles);
	void connect_particles(Particle* particles);
	bool test_lattice();
	Particle* find_particle(int n, int m);
	double find_total_energy();

};
#endif