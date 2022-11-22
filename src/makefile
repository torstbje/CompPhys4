
all: compile simple burn distribution crit clean

<<<<<<< Updated upstream
allbeta: beta4 beta6 beta8 beta0 critical
=======
all-mac: compile-mac wsimple burn distribution crit clean

all-c: compile simple burn distribution crit

all-comp: compile-mac crit plot-crit np_crit plot-np-crit
all-crit: compile-mac crit plot-crit 
>>>>>>> Stashed changes

compile:
	g++ -std=c++17 -o main.out main.cpp Lattice.cpp Particle.cpp funcs.cpp -fopenmp

compile-mac:
	g++-12 -std=c++17 -o main.out main.cpp Lattice.cpp Particle.cpp funcs.cpp -fopenmp


<<<<<<< Updated upstream
beta4:
	./main.out "beta" 0 10000 40 2.1 2.4 30

beta6:
	./main.out "beta" 0 10000 60 2.1 2.4 30

beta8:
	./main.out "beta" 0 10000 80 2.1 2.4 30

beta0:
	./main.out "beta" 0 10000 100 2.1 2.4 30

critical:
	python3 critical.py
=======
np_crit:
	time ./main.out "np_critical" 0 10000 20 2.2 2.4 10
	time ./main.out "np_critical" 0 10000 40 2.2 2.4 10
	time ./main.out "np_critical" 0 10000 60 2.2 2.4 10
	time ./main.out "np_critical" 0 10000 80 2.2 2.4 10
	time ./main.out "np_critical" 0 10000 100 2.2 2.4 10

plot-np-crit:
	python3 np_critical.py
>>>>>>> Stashed changes

simple:
	./main.out "simple" 0 10000
	python3 simple.py

distribution:
	./main.out "distribution" 1 10000 1.0
	./main.out "distribution" 1 10000 2.4
	python3 distribution.py

burn:
	./main.out "burn" 0 10000 20 1
	./main.out "burn" 1 10000 20 1
	./main.out "burn" 0 10000 20 2.4
	./main.out "burn" 1 10000 20 2.4
	python3 burnin.py
	
crit: # args: <is_aligned> <cycle> <L> <min_T> <max_T> <n_steps>
	time ./main.out "critical" 0 10000 40 2.2 2.4 30 -fopenmp
	time ./main.out "critical" 0 10000 60 2.2 2.4 30 -fopenmp
	time ./main.out "critical" 0 10000 80 2.2 2.4 30 -fopenmp
	time ./main.out "critical" 0 10000 100 2.2 2.4 30 -fopenmp

plot-crit: # <L> <min_T> <max_T> <n_steps>
	python3 critical.py "0 10000 40 2.2 2.4 30" "0 10000 60 2.2 2.4 30" "0 10000 80 2.2 2.4 30" "0 10000 100 2.2 2.4 30"

clean:
	-rm -f *.out textfiles/*.txt *.txt

clean-plots:
	-rm -f plots/*.pdf *pdf
 
