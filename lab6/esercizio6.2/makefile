ARG0 := -std=c++20

esercizio.6.2: esercizio.6.2.o 
	g++ -o esercizio.6.2 esercizio.6.2.o $(ARG0)

esercizio.6.2.o: esercizio.6.2.cpp lib6.2/math.h lib6.2/functions.h lib6.2/tests.h
	g++ -c esercizio.6.2.cpp $(ARG0)

clean:
	rm esercizio.6.2 esercizio.6.2.o
