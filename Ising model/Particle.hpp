
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

	Particle(int);
	bool evaluate_flip();
	void flip();
	std::string to_string();
	void add_neighbor(Particle* neighbor, const char direction);
};
#endif

