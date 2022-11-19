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


