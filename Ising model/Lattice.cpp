#include <iostream>
#include "Particle.hpp"
#include "Lattice.hpp"
using namespace std;

Lattice::Lattice(const int dim, Particle* particles) {
    dim_ = dim;
    first = &particles[0];
    connect_particles(particles);
}
void Lattice::connect_particles(Particle* particles) {
    
    // Fills and connects everything but the edges and corners
    // i : row number
    // j : col number
    for (int i = 1; i < dim_ - 1; i++) {
        for (int j = 1; j < dim_ - 1; j++) {
            particles[i * dim_ + j].add_neighbor(&particles[i * dim_ + j + 1], 'E');
            particles[i * dim_ + j].add_neighbor(&particles[i * dim_ + j - 1], 'W');
            particles[i * dim_ + j].add_neighbor(&particles[(i-1) * dim_ + j], 'N');
            particles[i * dim_ + j].add_neighbor(&particles[(i+1) * dim_ + j], 'S');
        }
    }

    // index for the last row and column
    int row_f = dim_ * (dim_ - 1);
    int col_f = dim_ - 1;

    // Connects the edges except for the corners
    for (int i = 1; i < dim_ -1; i++) {

        // top row
        particles[i].add_neighbor(&particles[i + 1], 'E');
        particles[i].add_neighbor(&particles[i - 1], 'W');
        particles[i].add_neighbor(&particles[dim_ + i], 'S');
        particles[i].add_neighbor(&particles[row_f + i], 'N');

        // bottom row
        particles[row_f + i].add_neighbor(&particles[row_f + i + 1], 'E');
        particles[row_f + i].add_neighbor(&particles[row_f + i - 1], 'W');
        particles[row_f + i].add_neighbor(&particles[row_f - dim_ + i], 'N');
        particles[row_f + i].add_neighbor(&particles[i], 'S');

        // left column
        particles[dim_ * i].add_neighbor(&particles[dim_ * (i + 1)], 'S');
        particles[dim_ * i].add_neighbor(&particles[dim_ * (i - 1)], 'N');
        particles[dim_ * i].add_neighbor(&particles[dim_ * i + 1 ], 'E');
        particles[dim_ * i].add_neighbor(&particles[dim_ * i + col_f], 'W');

        // right column
        particles[dim_ * i + col_f].add_neighbor(&particles[dim_ * (i+2) - 1], 'S');
        particles[dim_ * i + col_f].add_neighbor(&particles[dim_ * i - 1], 'N');
        particles[dim_ * i + col_f].add_neighbor(&particles[dim_ * i], 'E');
        particles[dim_ * i + col_f].add_neighbor(&particles[dim_ * i + dim_ - 2], 'W');

    }

    // Connects the corners

    // Top left
    particles[0].add_neighbor(&particles[1], 'E');
    particles[0].add_neighbor(&particles[col_f], 'W');
    particles[0].add_neighbor(&particles[dim_], 'S');
    particles[0].add_neighbor(&particles[row_f], 'N');

    // Top right
    particles[col_f].add_neighbor(&particles[0], 'E');
    particles[col_f].add_neighbor(&particles[col_f - 1], 'W');
    particles[col_f].add_neighbor(&particles[col_f + dim_], 'S');
    particles[col_f].add_neighbor(&particles[col_f + row_f], 'N');

    // Bottom left
    particles[row_f].add_neighbor(&particles[row_f + 1], 'E');
    particles[row_f].add_neighbor(&particles[row_f + col_f], 'W');
    particles[row_f].add_neighbor(&particles[0], 'S');
    particles[row_f].add_neighbor(&particles[row_f - dim_], 'N');

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
    for (int i = 0; i < dim_; i++) {
        for (int j = 0; j < dim_; j++) {
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

double Lattice::find_total_energy() {
    /* Finds the total energy of the lattice */
    current = first;
    int total_energy = 0;
    for (int i = 0; i < dim_; i++) {
        for (int j = 0; j < dim_; j++) {
            current->print();
            total_energy += current->get_energy_contribution();
            cout << "Energy: " << total_energy << endl;
            current = current->east;
        }
        current = current->south;
    }
    return total_energy;
}
