// Ising model.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>
#include <cassert>
#include "omp.h"



#include "Particle.hpp"
#include "Lattice.hpp"
#include "funcs.hpp"


#define ERR_MISSING_PARAMS 1
#define ERR_INVALID_LATTICE 2

// Contains the free functions of this project.
using namespace ising;
using namespace std;

int main(const int argc, const char *argv[])
{
    // Random seed
    srand(time(NULL));

    if (argc < 8) {
        std::cout << "\nMissing input parameters! (" << argc - 1 << " parameters was included.) \n"
            "Necessary parameters:\n"
            "- Aligned spins ('1'/'0') \n"
            "- L: length of lattice \n"
//            "- T: Temperature (double, unit [J/k_B]) \n"
            "- Number of cycles (integer) \n"
            "- Min temp \n"
            "- Max temp \n"
            "- Filename"
            "- Number of steps for temperature run";
            
        return ERR_MISSING_PARAMS;
    }
//
    std::string bjelland = argv[1];
    bool aligned = atoi(argv[2]);
    int dim = atoi(argv[3]);
//    double temperature = std::stod(argv[3]);
    int cycles = atoi(argv[4]);
//    std::string filename = argv[5];
    double min_temp = atof(argv[5]);
    double max_temp = atof(argv[6]);
    int n_steps = atoi(argv[7]);

    int n_particles = dim * dim;
    
    std::string filename1, filename2;
    std::string a = argv[1], b = argv[2], c = argv[3], d = argv[4], e = argv[5];
    std::string f = argv[6], g = argv[7];
    filename1 = a + b + c + d + e + "-1.txt";
    filename2 = a + b + c + d + e + "-2.txt";
    filename1 = "textfiles/" + b + "-" + c + "-" + d +".txt";
    filename2 = "textfiles/t-cv-chi-" +b+ "-"+c+ "-"+d+ "-"+e+ "-"+f+ "-"+g+ ".txt";
    
    std::vector<Particle> particles(0);
    fill_particle_list(n_particles,particles,aligned);


//    Lattice lattice(dim,particles,temperature);

    
//    if (!lattice.test_lattice()) {
//        return ERR_INVALID_LATTICE;
//    }
    
//    mcmc_calculate(lattice,cycles,filename1);
    
//    double min_temp = 2.0, max_temp = 2.5;
    double curr_temp = min_temp, dtemp = (max_temp - min_temp)/double(n_steps);
   
    
    std::cout << "======================== temperature ========================" << std::endl;
    
    std::ofstream outfile;
    outfile.open(filename2);
    assert(outfile);
    std::cout << filename2 << std::endl;
   
    
    #pragma omp parallel for

    for (int i=0;i<n_steps;i++) {
        double values[4];
        values[0] = -999;
        values[1] = -999;
        values[2] = -999;
        values[3] = -999;

        std::cout << i << std::endl;
        Lattice lattice(dim,particles,curr_temp);
        assert(lattice.test_lattice());
        mc_phase(lattice, cycles, 100, values);
        outfile << curr_temp << "," << values[0] << "," << values[1] << "," << values[2] << "," << values[3] << endl;
        #pragma omp atomic
        curr_temp += dtemp;
    }
    outfile.close();
    
//        double values[4];
//        values[0] = -999;
//        values[1] = -999;
//        values[2] = -999;
//        values[3] = -999;
//    for (int i=0;i<n_steps;i++) {
//        std::cout << i << std::endl;
//        Lattice lattice(dim,particles,curr_temp);
//        if (!lattice.test_lattice()) {
//            return ERR_INVALID_LATTICE;
//        }
//        mc_phase(lattice, cycles, 100, values);
//        outfile << curr_temp << "," << values[0] << "," << values[1] << "," << values[2] << "," << values[3] << endl;
//
//        curr_temp += dtemp;
//    }
//    outfile.close();
}
