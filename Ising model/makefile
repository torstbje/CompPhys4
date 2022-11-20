
compile:
	g++ -std=c++17 -o main.out main.cpp Lattice.cpp Particle.cpp funcs.cpp

writeTexts:
	./main.out 0 1 10000
	./main.out 1 1 10000
	./main.out 0 2.4 10000
	./main.out 1 2.4 10000 

plot:
	python3 simple_lattice_plot.py cmcm.txt

clean: 
	-rm -f *.o **.txt

