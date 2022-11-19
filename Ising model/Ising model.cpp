// Ising model.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "Particle.hpp"

using namespace std;

int main()
{
    int spin = 1;
    Particle p1 = Particle(spin);
    Particle p2 = Particle(spin);
    Particle p3 = Particle(spin);
    Particle p4 = Particle(spin);
    p1.add_neighbor(&p2, 'E');
    cout << p1.east->to_string() << endl;
}
