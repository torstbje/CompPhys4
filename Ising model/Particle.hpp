#include <string>
#ifndef PARTICLE_HPP
#define PARTICLE_HPP
class Particle
{
public:
	Particle* north;
	Particle* south;
	Particle* east;
	Particle* west;
	int spin_;
	int index_;

	Particle();					// Default constructor, sets spin to 0
	Particle(int,int);			// Constructor with spin and index as parameter
	void set_spin(int);
	void flip();
	void print();
	void add_neighbor(Particle* neighbor, char direction);
	int get_energy_contribution();
};
#endif

