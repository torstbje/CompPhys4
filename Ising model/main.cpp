// Ising model.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <cmath>


#include "Particle.hpp"
#include "Lattice.hpp"
#include "funcs.hpp"

#define ERR_MISSING_PARAMS 1

// Contains the free functions of this project.
using namespace ising;

int main(int argc, char *argv[])
{
    // Random seed
    srand(time(NULL));

    if (argc < 6) {
        std::cout << "\nMissing input parameters! (" << argc - 1 << " parameters was included.) \n"
            "Necessary parameters:\n"
            "- Aligned spins ('1'/'0') \n"
            "- L: Length of one side of the lattice:(integer) \n"
            "- T: Temperature (double, unit [J/k_B]) \n"
            "- Number of cycles (integer) \n";
        return ERR_MISSING_PARAMS;
    }
    
    bool aligned = atoi(argv[1]);
    int dim = atoi(argv[2]);
    double temperature = std::stod(argv[3]);
    int cycles = atoi(argv[4]);

    int n_particles = dim * dim;
    
    Particle* particles = nullptr;
    fill_particle_list(particles,n_particles,aligned);
    Lattice lattice(dim, particles,temperature);
    
    if (!lattice.test_lattice()) {
        return 1;
    }

    std::string filename = "textfiles/mcmc.txt";
    mcmc_calculate(lattice,1000,filename);
}
