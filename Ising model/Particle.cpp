#include <iostream>
#include <string>
#include "Particle.hpp"

Particle::Particle() {
    /*
    Initializer for Particle class
    */
    spin_ = 0;
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


void Particle::set_spin(int spin) {
    spin_ = spin;
}
void Particle::flip() {
    spin_ = -spin_;
}

void Particle::print() {
    std::cout << "Index: " << index_ << ", Spin: " << spin_ << std::endl;
    std::cout << "North: " << north->spin_ << ", South: " << south->spin_ << ", West: " << west->spin_ << ", East: " << east->spin_ << std::endl;
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

int Particle::get_magnetization_contribution(){
    /* Return the total energy contribution from this particle in a lattice. */
    return abs(spin_);
}


