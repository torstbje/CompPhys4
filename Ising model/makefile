
all: compile writeTexts plot burn-in clean
compile:
	g++ -std=c++17 -o main.out main.cpp Lattice.cpp Particle.cpp funcs.cpp

writeTexts:
	./main.out 0 1 100000 "textfiles/nonalign-1-10000.txt"
	./main.out 1 1 100000 "textfiles/align-1-10000.txt"
	./main.out 0 2.4 100000 "textfiles/nonalign-2.4-10000.txt"
	./main.out 1 2.4 100000 "textfiles/align-2.4-10000.txt"

this:
	./main.out 0 2.4 100000 "textfiles/align-2.4-10000.txt"

plot burn-in:
	nython3 burn-in.py "textfiles/nonalign-1-10000.txt"
	python3 burn-in.py "textfiles/align-1-10000.txt"
	python3 burn-in.py "textfiles/nonalign-2.4-10000.txt"
	python3 burn-in.py "textfiles/align-2.4-10000.txt"


clean: 
	-rm -f *.out textfiles/*.txt

