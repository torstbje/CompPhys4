// Ising model.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>
#include <cassert>
#include <fstream>
#include "omp.h"


#include "Particle.hpp"
#include "Lattice.hpp"
#include "funcs.hpp"


#define ERR_MISSING_PARAMS 1
#define ERR_INVALID_LATTICE 2

// Contains the free functions of this project.
using namespace ising;
using namespace std;

int main(const int argc, const char* argv[])
{
    // Random seed
    srand(time(NULL));

    if (argc < 4) {
        // These parameters are needed for all program runs
        std::cout << "\nMissing input parameters! (" << argc - 1 << " parameters was included.) \n"
            "All calls of this program should include the following parameters:\n"
            "- Run time instruction: ('simple' / 'burn' / 'distribution' / 'critical' )\n"
            "- Aligned spins ('1'/'0') \n"
            "- Number of cycles (integer) \n";
        return ERR_MISSING_PARAMS;
    }

    std::string instruction = argv[1];
    bool aligned = atoi(argv[2]);
    int cycles = atoi(argv[3]);

    if (instruction == "distribution") {
        if (argc < 5) {
            std::cout << "\nMissing input parameters! (" << argc - 1 << " parameters was included.) \n";
            wrong_cmd_input("distribution");
            return ERR_MISSING_PARAMS;
        }
        double temperature = atof(argv[4]);
        int dim = 20;

        int n_particles = dim * dim;
        std::vector<Particle> particles(0);
        fill_particle_list(n_particles, particles, aligned);

        Lattice lattice(dim, particles, temperature);
        std::string filename = make_filename(instruction, aligned, temperature);

        int burn_cycles = 300;
        mc_dist(lattice, cycles,burn_cycles, filename);
    }


    if (instruction == "np_critical") {
        if (argc < 8) {
            std::cout << "\nMissing input parameters! (" << argc - 1 << " parameters was included.) \n";
            wrong_cmd_input("critical");
            return ERR_MISSING_PARAMS;
        }
        int dim = atoi(argv[4]);
        double t_min = atof(argv[5]);
        double t_max = atof(argv[6]);
        int n_steps = atoi(argv[7]);
        double t_step = (t_max - t_min) / (n_steps+1.0);

        std::string filename = make_filename(instruction, dim);

        std::ofstream outfile;
        outfile.open(filename);
        for (double temperature = t_min; temperature < t_max; temperature += t_step) {
            std::vector<Particle> particles(0);
            fill_particle_list(dim*dim, particles, aligned);
            Lattice lattice(dim, particles, temperature);
            double values[4];
            mc_phase(lattice, cycles, 1000, values);


            for (int i = 0; i < 4; i++) {
                outfile << values[i] << " , ";
            }
            outfile << temperature << endl;

        }
        outfile.close();

    }

    if (instruction == "simple") {
        double t_min = 1.0;
        double t_max = 3;
        double t_step = 0.1;
        std::ofstream outfile;
        outfile.open("textfiles/simple.txt");
        for (double temperature = t_min; temperature < t_max; temperature += t_step) {
            std::vector<Particle> particles(0);
            fill_particle_list(4, particles, aligned);

            Lattice lattice(2, particles, temperature);

            double values[4];
            mc_phase(lattice, cycles, 100, values);


            for (int i = 0; i < 4; i++) {
                outfile << values[i] << " , ";
            }
            outfile << temperature << endl;

        }
        outfile.close();

    }
    if (instruction == "burn") {
        // Checks if the temperature is included as well.
        if (argc < 6) {
            std::cout << "\nMissing input parameters! (" << argc - 1 << " parameters was included.) \n";
            wrong_cmd_input(instruction);
            return ERR_MISSING_PARAMS;
        }

        int dim = std::atoi(argv[4]);
        double temperature = std::stod(argv[5]);

        int n_particles = dim * dim;
        std::vector<Particle> particles(0);
        fill_particle_list(n_particles, particles, aligned);

        Lattice lattice(dim, particles, temperature);
        std::string filename = make_filename(instruction, aligned, temperature);
        mc_find_burn(lattice, cycles, filename);
    }

    if (instruction == "critical") {
        if (argc < 8) {
            std::cout << "\nMissing input parameters! (" << argc - 1 << " parameters was included.) \n";
            wrong_cmd_input(instruction);
            return ERR_MISSING_PARAMS;
        }
//        int cycles = atoi(argv[3]);
        int dim = atoi(argv[4]);
        double min_temp = atof(argv[5]);
        double max_temp = atof(argv[6]);
        int n_steps = atoi(argv[7]);

        int n_particles = dim * dim;

        std::string filename1, filename2;
        std::string a = argv[1], b = argv[2], c = argv[3], d = argv[4], e = argv[5];
        std::string f = argv[6], g = argv[7];

        filename2 = "textfiles/t-cv-chi " + b + " " + c + " " + d + " " + e + " " + f + " " + g + ".txt";
        std::cout << filename2 << std::endl;

//        std::vector<Particle> particles(0);
//        fill_particle_list(n_particles, particles, aligned);

        double curr_temp = min_temp, dtemp = (max_temp - min_temp) / double(n_steps);

        std::cout << "======================== temperature ========================" << std::endl;

        std::ofstream outfile;
        outfile.open(filename2);
        assert(outfile);
//        std::cout << filename2 << std::endl;
        
        std::cout << cycles << std::endl;
#pragma omp parallel for

        for (int i = 0; i < n_steps; i++) {
            double values[4];
            values[0] = -999;
            values[1] = -999;
            values[2] = -999;
            values[3] = -999;

            std::vector<Particle> particles(0);
            fill_particle_list(dim*dim, particles, aligned);
            Lattice lattice(dim, particles, curr_temp);
            assert(lattice.test_lattice());
//            double values[4];
            mc_phase(lattice, cycles, 10000, values);
            
//            Lattice lattice(dim, particles, curr_temp);
//            assert(lattice.test_lattice());
//            mc_phase(lattice, cycles, 100, values);
//            std::cout << values[2] << std::endl;
            outfile << curr_temp << "," << values[0] << "," << values[1] << "," << values[2] << "," << values[3] << endl;
#pragma omp atomic
            curr_temp += dtemp;
        }
        outfile.close();
    }
}


