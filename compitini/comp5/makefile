
main: main.o lib/functions.h lib/gplot++.h lib/test_random.h lib/test_stats.h lib/experiments.h
	g++  -o main main.o     

main.o: main.cpp
	g++  -std=c++20 -c main.cpp

clean:
	rm main main.o
