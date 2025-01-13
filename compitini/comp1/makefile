
main: main.o lib/integral/integral_tests.h lib/gplot++.h lib/functions.h
	g++  -o main main.o   

main.o: main.cpp
	g++  -std=c++20 -c main.cpp

ex: clean main
	./main

clean:
	rm main main.o
