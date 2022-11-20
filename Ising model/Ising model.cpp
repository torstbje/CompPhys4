// Ising model.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>

#include "Particle.hpp"
#include "Lattice.hpp"
#include "funcs.hpp"


using namespace ising;

int main()
{
    const int dim = 10;
    const int n_particles = dim * dim;
    double temperature = 1.0;
    
    Particle particles[n_particles];
    fill_particle_list(particles,n_particles,"uniform");
    Lattice lattice(dim, particles,temperature);
    
    if (!lattice.test_lattice()) {
        return 1;
    }


    std::string filename = "mcmc.txt";
    mcmc_calculate(lattice,1000,filename);

}
