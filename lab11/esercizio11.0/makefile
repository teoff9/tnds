ARG0 := -std=c++20

esercizio11.0: esercizio11.0.o lib11.0/experiments.h lib11.0/test_random.h lib11.0/test_stats.h lib11.0/gplot++.h lib11.0/test_geom.h
	g++ $(ARG0) -o esercizio11.0 esercizio11.0.o     

esercizio11.0.o: esercizio11.0.cpp
	g++  $(ARG0) -c esercizio11.0.cpp

clean:
	rm esercizio11.0 esercizio11.0.o
