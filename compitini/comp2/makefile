
main: main.o lib/test_diff_eq.h lib/test_geom.h lib/test_stats.h lib/test_random.h lib/gplot++.h lib/functions.h
	g++  -o main main.o      

main.o: main.cpp
	g++  -std=c++20 -c main.cpp

clean:
	rm main main.o
