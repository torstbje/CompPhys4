all: compile writeTexts plot-56 clean
all-mac: compile-mac writeTexts plot-56 clean
all-c: compile writeTexts plot-56

all-temp: compile-mac tempRun tempPlot clean

allbeta: beta4 beta6 beta8 beta0 critical

compile:
	g++ -std=c++17 -o main.out main.cpp Lattice.cpp Particle.cpp funcs.cpp -fopenmp

compile-mac:
	g++-12 -std=c++17 -o main.out main.cpp Lattice.cpp Particle.cpp funcs.cpp -fopenmp


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

simple:
	./main.out "simple" 0 10000
	python3 simple.py

distribution:
	./main.out "distribution" 1 10000 1.0
	./main.out "distribution" 1 10000 2.4
	python3 distribution.py

burn:
	./main.out "burn" 0 1000 20 1
	./main.out "burn" 1 1000 20 1
	./main.out "burn" 0 1000 20 2.4
	./main.out "burn" 1 1000 20 2.4
	python3 burnin.py

	

#writeTexts:
#	./main.out 0 20 1 10000 "textfiles/nonalign-1-10000.txt" -fopenmp
#	./main.out 1 20 1 10000 "textfiles/align-1-10000.txt" -fopenmp
#	./main.out 0 20 2.4 10000 "textfiles/nonalign-2.4-10000.txt" -fopenmp
#	./main.out 1 20 2.4 10000 "textfiles/align-2.4-10000.txt" -fopenmp

# tempRun: # args: <is_aligned> <L> <T> <n_cycle> <min_T> <max_T> <n_steps>
# 	time ./main.out "bastard" 0 40 1000 2.35 2.45 10 -fopenmp
# 	time ./main.out "bastard" 0 60 1000 2.35 2.45 10 -fopenmp
# 	time ./main.out "bastard" 0 80 1000 2.35 2.45 10 -fopenmp
# 	time ./main.out "bastard" 0 100 1000 2.35 2.45 10 -fopenmp
	
# tempPlot: # <L> <min_T> <max_T> <n_steps>
# 	python3 plot-temp.py "0-40-1000-2.35-2.45-10"
# 	python3 plot-temp.py "0-60-1000-2.35-2.45-10"
# 	python3 plot-temp.py "0-80-1000-2.35-2.45-10"
# 	python3 plot-temp.py "0-100-1000-2.35-2.45-10"
	
#tempRun: # args: <is_aligned> <L> <T> <n_cycle> <min_T> <max_T> <n_steps>
#	time ./main.out "bastard" 0 40 1000 2.1 2.4 10 -fopenmp
#	time ./main.out "bastard" 0 60 1000 2.1 2.4 10 -fopenmp
#	time ./main.out "bastard" 0 80 1000 2.1 2.4 10 -fopenmp
#	time ./main.out "bastard" 0 100 1000 2.1 2.4 10 -fopenmp
#
#tempPlot: # <L> <min_T> <max_T> <n_steps>
#	python3 plot-temp.py "0-40-1000-2.1-2.4-10"
#	python3 plot-temp.py "0-60-1000-2.1-2.4-10"
#	python3 plot-temp.py "0-80-1000-2.1-2.4-10"
#	python3 plot-temp.py "0-100-1000-2.1-2.4-10"
#

this:
	./main.out 0 20 2.4 10000 "textfiles/align-2.4-10000.txt" -fopenmp

plot-56:
	python3 burn-in.py "textfiles/nonalign-1-10000.txt"
	python3 burn-in.py "textfiles/align-1-10000.txt"
	python3 burn-in.py "textfiles/nonalign-2.4-10000.txt"
	python3 burn-in.py "textfiles/align-2.4-10000.txt"

clean:
	-rm -f *.out textfiles/*.txt *.txt

clean-plots:
	-rm -f plots/*.pdf *pdf
 
