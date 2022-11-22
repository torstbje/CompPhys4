# Computational Physics Project 4: The Ising model



## Prerequisites
Check that you have g++-12 the GNU compiler installed if you are on macOS by running
```sh
g++-12 --version
```
if not, install by running
```sh
brew install gcc@12
```
Check also that you have Python3 installed by running
```sh
python3
```


# DESCRIPTION

    The project simulates a physical material in the form of a lattice, and the distribution of it's state at different temperatures.
    It uses the markov chain monte carlo algorithm for findin the statistical distribution of states
    The simulation is written in object oriented C++ code.
    Plotting is written in python3.
    A makefile is used to compile the code, and perform predetermined executions.

PRODUCE RESULTS

    The code is run from 'src' folder
    make compile: Compiles the c++ program.
    make all: produces all the relevant results
    The separate runs to produce results are:
    make simple: a 2*2 lattice
    make burn: Evuales the burn-in time
    make distribution: Produced a histogram of measured states
    make crit, followed by make plot-crit: A parallellized program for evaluating the critical temperature

GENERAL PROCESS FOR HOW THE CODE RUNS

    src/: Premade makefile commands are run to start program.
    makefile: comiles c++ program.
    makefile: executes c++ code with arguments for which type of simulation to run (i.e. cycles,points).
    c++: (Object) Lattice is made and filled with instances of (Object) Particle.
    c++: Simulation is performed, with description of system written to txt files at every time step.
    c++: txt files are saved to 'textfiles' folder.
    makefile: executes python functions with specific commands to use the files from the simulation.
    python: txt files are read and relevant data is collected.
    python: data is used for producing figures, or for comparing with analytical solutions.
    python: Figures are saved to 'plots' folder.

CODE STRUCTURE

    The code contains two classes Particle and Lattice.

    The particle class contains a few values memory pointers to all of it's neighbors'

    Lattice contains methods for evolving the system, by flipping spins

    when the Lattice is initialized, it takes an array of Particle-pointers, and assigns neighbors with continuous boundaries

CONVENTIONS:

    snake_case (lower case letters separated by an underscore) is used for most variable- and function-names.
    PascalCase (first letter of every word is capitalized, including the very first word) is used for class names.
