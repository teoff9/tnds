CXXFLAGS = -g3 -Wall --pedantic -std=c++23

esercizio3.0: esercizio3.0.o lib3.0/vect.h lib3.0/tests.h lib3.0/stats.h 
	g++ esercizio3.0.o -o esercizio3.0 $(CXXFLAGS)

esercizio3.0.o: esercizio3.0.cpp
	g++ -c esercizio3.0.cpp -o esercizio3.0.o $(CXXFLAGS)

clean:
	rm *.o esercizio3.0

