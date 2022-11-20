#include<iostream>
#include<vector>

#include "Particle.hpp"
#include "Lattice.hpp"

using namespace std;

namespace ising {
	void mcmc_calculate(Lattice& lattice, int cycles) {
		/* Does multiple monte carlo cycles over the lattice, collecting the energy and magnetization for each state */

		vector<int> magnetization(cycles);
		vector<int> energy(cycles);
		for (int i = 0; i < cycles; i++) {
			magnetization[i] = lattice.total_magnetization;
			energy[i] = lattice.total_energy;
			lattice.monte_carlo_cycle();
		}

		for (int i = 0; i < cycles; i++) {
			cout << "Cycles: " << i << ", Energy: " << energy[i] << ", Magnetization: " << magnetization[i] << endl;
		}
	}
}
