// Ising model.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "Particle.hpp"
#include "Lattice.hpp"

using namespace std;

int main()
{
    const int dim = 5;
    Particle particles[dim*dim];
    for (int i = 0; i < dim * dim; i++) {
        particles[i] = Particle(pow(-1,i), i);
    }
    Lattice lattice(dim, particles);
    
    if (!lattice.test_lattice()) {
        return 1;
    }
}
