#include <iostream>
#include "Particle.hpp"
#include "Lattice.hpp"
using namespace std;

Lattice::Lattice(const int dim, Particle* particles) {
    L = dim;
    N = L * L;
    first = &particles[0];
    connect_particles(particles);
}
void Lattice::connect_particles(Particle* particles) {
    
    // Fills and connects everything but the edges and corners
    // i : row number
    // j : col number
    for (int i = 1; i < L - 1; i++) {
        for (int j = 1; j < L - 1; j++) {
            particles[i * L + j].add_neighbor(&particles[i * L + j + 1], 'E');
            particles[i * L + j].add_neighbor(&particles[i * L + j - 1], 'W');
            particles[i * L + j].add_neighbor(&particles[(i-1) * L + j], 'N');
            particles[i * L + j].add_neighbor(&particles[(i+1) * L + j], 'S');
        }
    }

    // index for the last row and column
    int row_f = N - L;
    int col_f = L - 1;

    // Connects the edges except for the corners
    for (int i = 1; i < L -1; i++) {

        // top row
        particles[i].add_neighbor(&particles[i + 1], 'E');
        particles[i].add_neighbor(&particles[i - 1], 'W');
        particles[i].add_neighbor(&particles[L + i], 'S');
        particles[i].add_neighbor(&particles[row_f + i], 'N');

        // bottom row
        particles[row_f + i].add_neighbor(&particles[row_f + i + 1], 'E');
        particles[row_f + i].add_neighbor(&particles[row_f + i - 1], 'W');
        particles[row_f + i].add_neighbor(&particles[row_f - L + i], 'N');
        particles[row_f + i].add_neighbor(&particles[i], 'S');

        // left column
        particles[L * i].add_neighbor(&particles[L * (i + 1)], 'S');
        particles[L * i].add_neighbor(&particles[L * (i - 1)], 'N');
        particles[L * i].add_neighbor(&particles[L * i + 1 ], 'E');
        particles[L * i].add_neighbor(&particles[L * i + col_f], 'W');

        // right column
        particles[L * i + col_f].add_neighbor(&particles[L * (i+2) - 1], 'S');
        particles[L * i + col_f].add_neighbor(&particles[L * i - 1], 'N');
        particles[L * i + col_f].add_neighbor(&particles[L * i], 'E');
        particles[L * i + col_f].add_neighbor(&particles[L * i + L - 2], 'W');

    }

    // Connects the corners

    // Top left
    particles[0].add_neighbor(&particles[1], 'E');
    particles[0].add_neighbor(&particles[col_f], 'W');
    particles[0].add_neighbor(&particles[L], 'S');
    particles[0].add_neighbor(&particles[row_f], 'N');

    // Top right
    particles[col_f].add_neighbor(&particles[0], 'E');
    particles[col_f].add_neighbor(&particles[col_f - 1], 'W');
    particles[col_f].add_neighbor(&particles[col_f + L], 'S');
    particles[col_f].add_neighbor(&particles[col_f + row_f], 'N');

    // Bottom left
    particles[row_f].add_neighbor(&particles[row_f + 1], 'E');
    particles[row_f].add_neighbor(&particles[row_f + col_f], 'W');
    particles[row_f].add_neighbor(&particles[0], 'S');
    particles[row_f].add_neighbor(&particles[row_f - L], 'N');

    // Bottom right
    particles[col_f + row_f].add_neighbor(&particles[row_f], 'E');
    particles[col_f + row_f].add_neighbor(&particles[col_f + row_f - 1], 'W');
    particles[col_f + row_f].add_neighbor(&particles[col_f], 'S');
    particles[col_f + row_f].add_neighbor(&particles[col_f - 1], 'N');

}


bool Lattice::test_lattice() {
    /* Loops through every element in the lattice and tests if their index correspond to the expected one */
    Particle* particle = first;
    int exp = 0;
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < L; j++) {
            if (particle->index_ != exp) {
                std::cout << "Error: The lattice in not in the right configuration. Expected index: " << exp << " , got: " << particle->index_ << "\n";
                return false;
            }
            particle->print();
            particle = particle->east;
            exp++;
        }
        particle = particle->south;
    }

    if (particle->index_ != first->index_) {
        std::cout << "Error: The row is not connected at the ends. \n";
        return false;
    }
    return true;
}

Particle* Lattice::find_particle(int n, int m) {
    /* Traverses the lattice to find a specific particle */
    current = first;
    for (int i = 0; i < n; i++) {
        current = current->south;
    }
    for (int i = 0; i < m; i++) {
        current = current->east;
    }
    return current;
}

void Lattice::find_energy_magnetization() {
    /*
    Finds the total energy and absolute magnetization of the lattice.
    The energy contribution from the particle class is divided by 2 to avoid double counting.
    It also countains the negative sign, but not the coupling factor. 
    The total energy is scaled by the coupling factor J.
    */

    // Resets energy and magnetization
    total_energy = 0;
    total_magnetization = 0;

    // Starts at the first point
    current = first;

    // Iterates through lattice, updates magnetization and energy for each step
    // For the magnetization terms, the absolute value is used.
    // For the energy terms, they are divided by two to account for double counting of the neighbors.
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < L; j++) {
            total_energy += current->get_energy_contribution();
            total_magnetization += current->get_magnetization_contribution();
            cout << "Energy: " << total_energy << endl;
            cout << "Magnetization: " << total_magnetization << endl;

            // One step to the east
            current = current->east;
        }
        // One step to the south
        current = current->south;
    }
}
