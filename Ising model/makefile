
compile:
	g++ -std=c++17 -o main.out main.cpp Lattice.cpp Particle.cpp func.cpp

writeTexts:
	./main.out 0 20 1 10000
	./main.out 1 20 1 10000 
	./main.out 0 20 2.4 10000 
	./main.out 1 20 2.4 10000 

plot:
	python3 simple_lattice_plot.py cmcm.txt

clean: 
	-rm -f *.o **.txt

