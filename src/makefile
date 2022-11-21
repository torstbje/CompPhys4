
all: compile writeTexts plot-56 clean
all-c: compile writeTexts plot-56
compile:
	g++ -std=c++17 -o main.out main.cpp Lattice.cpp Particle.cpp funcs.cpp

writeTexts:
	./main.out 0 20 1 10000 "textfiles/nonalign-1-10000.txt"
	./main.out 1 20 1 10000 "textfiles/align-1-10000.txt"
	./main.out 0 20 2.4 10000 "textfiles/nonalign-2.4-10000.txt"
	./main.out 1 20 2.4 10000 "textfiles/align-2.4-10000.txt"

this:
	./main.out 0 20 2.4 100000 "textfiles/align-2.4-10000.txt"

plot-56:
	python3 burn-in.py "textfiles/nonalign-1-10000.txt"
	python3 burn-in.py "textfiles/align-1-10000.txt"
	python3 burn-in.py "textfiles/nonalign-2.4-10000.txt"
	python3 burn-in.py "textfiles/align-2.4-10000.txt"


clean: 
	-rm -f *.out textfiles/*.txt

