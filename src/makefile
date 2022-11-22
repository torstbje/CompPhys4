all: compile writeTexts plot-56 clean
all-mac: compile-mac writeTexts plot-56 clean
all-c: compile writeTexts plot-56

all-temp: compile-mac tempRun tempPlot clean

compile:
	g++ -std=c++17 -o main.out main.cpp Lattice.cpp Particle.cpp funcs.cpp -fopenmp

compile-mac:
	g++-12 -std=c++17 -o main.out main.cpp Lattice.cpp Particle.cpp funcs.cpp -fopenmp

#writeTexts:
#	./main.out 0 20 1 10000 "textfiles/nonalign-1-10000.txt" -fopenmp
#	./main.out 1 20 1 10000 "textfiles/align-1-10000.txt" -fopenmp
#	./main.out 0 20 2.4 10000 "textfiles/nonalign-2.4-10000.txt" -fopenmp
#	./main.out 1 20 2.4 10000 "textfiles/align-2.4-10000.txt" -fopenmp
#
# tempRun: # args: <is_aligned> <L> <T> <n_cycle> <min_T> <max_T> <n_steps>
# 	time ./main.out "bastard" 0 40 1000 2.1 2.4 10 -fopenmp
# 	time ./main.out "bastard" 0 60 1000 2.1 2.4 10 -fopenmp
# 	time ./main.out "bastard" 0 80 1000 2.1 2.4 10 -fopenmp
# 	time ./main.out "bastard" 0 100 1000 2.1 2.4 10 -fopenmp
#
# tempPlot: # <L> <min_T> <max_T> <n_steps>
# 	python3 plot-temp.py "0-40-1000-2.35-2.45-10"
# 	python3 plot-temp.py "0-60-1000-2.35-2.45-10"
# 	python3 plot-temp.py "0-80-1000-2.35-2.45-10"
# 	python3 plot-temp.py "0-100-1000-2.35-2.45-10"
	
tempRun: # args: <is_aligned> <L> <T> <n_cycle> <min_T> <max_T> <n_steps>
	time ./main.out "bastard" 0 40 1000 2.1 2.4 10 -fopenmp
	time ./main.out "bastard" 0 60 1000 2.1 2.4 10 -fopenmp
	time ./main.out "bastard" 0 80 1000 2.1 2.4 10 -fopenmp
	time ./main.out "bastard" 0 100 1000 2.1 2.4 10 -fopenmp
#
tempPlot: # <L> <min_T> <max_T> <n_steps>
	python3 plot-temp.py "0-40-1000-2.1-2.4-10" "0-60-1000-2.1-2.4-10" "0-80-1000-2.1-2.4-10" "0-100-1000-2.1-2.4-10"
#

this:
	./main.out 0 20 2.4 100000 "textfiles/align-2.4-10000.txt" -fopenmp

plot-56:
	python3 burn-in.py "textfiles/nonalign-1-10000.txt"
	python3 burn-in.py "textfiles/align-1-10000.txt"
	python3 burn-in.py "textfiles/nonalign-2.4-10000.txt"
	python3 burn-in.py "textfiles/align-2.4-10000.txt"

clean:
	-rm -f *.out textfiles/*.txt *.txt

clean-plots:
	-rm -f plots/*.pdf *pdf
 
