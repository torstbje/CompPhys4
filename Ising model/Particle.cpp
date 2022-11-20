#include <iostream>
#include <string>
#include "Particle.hpp"

Particle::Particle() {
    /*
    Default initializer for Particle class. This function is only chosen to allow for declaration before initialization.
    */
    spin_ = 0;                                // spin: 0 is chosen to show that the particle hasn't been properly initialized yet.
    index_ = NULL;                            // index: NULL is chosen to show that the particle hasn't been properly initialized yet.
    north = east = west = south = nullptr;
}

Particle::Particle(int spin,int index) {
    /*
    Initializer for Particle class
    */
    spin_ = spin;
    north = east = west = south = nullptr;
    index_ = index;
}

void Particle::flip() {
    spin_ = -spin_;
}

void Particle::print() {
    std::cout << "Index: " << index_ << ", Spin: " << spin_ << std::endl;
}

void Particle::add_neighbor(Particle* neighbor, char direction) {
    switch (direction) {
        case 'N':
            north = neighbor;
            break;
        case 'S':
            south = neighbor;
            break;
        case 'E':
            east = neighbor;
            break;
        case 'W':
            west = neighbor;
            break;
    }
}

int Particle::get_energy_contribution(){
    /* 
    Return the total energy contribution from this particle in a lattice. 
    If this is done for every particle, this should be divided by 2 to account for double counting .
    If this is used to measure change for a flip, it should be multiplied by (-2) to get the energy change.
    */
    return -spin_*(east->spin_ + west->spin_ + south->spin_ + north->spin_);
}

int Particle::get_magnetization_contribution() {
    /* Return the total energy contribution from this particle in a lattice. */
    return spin_;
}


