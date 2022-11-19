#include <string>
#include "Particle.hpp"

Particle::Particle(int spin) {
    /*
    Initializer for Particle class
    */
    spin_ = spin;
    north = east = west = south = nullptr;
}
void Particle::flip() {
    spin_ = -spin_;
}

bool Particle::evaluate_flip() {
    return true;
}

std::string Particle::to_string() {
    return "It worked!";
}

void Particle::add_neighbor(Particle* neighbor, const char direction) {
    switch (direction) {
        case 'N':
            north = neighbor;
        case 'S':
            south = neighbor;
        case 'E':
            east = neighbor;
        case 'W':
            west = neighbor;
    }
}


