
compile:
	g++ -std=c++17 -o main.out main.cpp Lattice.cpp Particle.cpp funcs.cpp

writeTexts:
	./main.out 0 20 1.0 10000
	./main.out 1 20 1.0 10000
	./main.out 0 20 2.4 10000 
	./main.out 1 20 2.4 10000 

plot:
	python3 simple_lattice_plot.py mcmc.txt

clean: 
	-rm -f *.o **.txt

