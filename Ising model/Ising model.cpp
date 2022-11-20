// Ising model.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "Particle.hpp"
#include "Lattice.hpp"

using namespace std;

int main()
{
    const int dim = 20;
    double temperature = 1;
    Particle particles[dim*dim];
    // All spins are given positive spin
    for (int i = 0; i < dim * dim; i++) {
        particles[i] = Particle(1, i);
    }
    Lattice lattice(dim, particles,temperature);
    
    if (!lattice.test_lattice()) {
        return 1;
    }
    lattice.attempt_flip();
}
