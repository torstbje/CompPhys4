// Ising model.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

#include "Particle.hpp"
#include "Lattice.hpp"

#include "funcs.hpp"

using namespace ising;

int main()
{
    const int dim = 2;
    double temperature = 1.0;
    Particle particles[dim*dim];
    // All spins are given positive spin
    for (int i = 0; i < dim * dim; i++) {
        particles[i] = Particle(1, i);
    }
    Lattice lattice(dim, particles,temperature);
    
    if (!lattice.test_lattice()) {
        return 1;
    }

    mcmc_calculate(lattice,100);

}
