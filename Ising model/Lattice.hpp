#include <vector>
#ifndef LATTICE_HPP
#define LATTICE_HPP
class Lattice
{
public:
	Particle* p;
	int dim_;

	Lattice(const int dim, Particle* particles);
	void connect_particles(Particle* particles);
	bool test_lattice();

};
#endif