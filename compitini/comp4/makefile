
main: main.o lib/bisection_tests.h lib/integral_tests.h lib/functions.h
	g++  -o main main.o   

main.o: main.cpp
	g++  -std=c++20 -c main.cpp

clean:
	rm main main.o
