es012.x: ../../lib/sorting/sorting.o ../../lib/stats/stats.o es012.o
	g++ ../../lib/sorting/sorting.o ../../lib/stats/stats.o es012.o -o es012.x

es012.o: es012.cpp
	g++ -c es012.cpp -o es012.o

../../lib/sorting/sorting.o: ../../lib/sorting/sorting.cpp
	g++ -c ../../lib/sorting/sorting.cpp -o ../../lib/sorting/sorting.o

../../lib/stats/stats.o: ../../lib/stats/stats.cpp
	g++ -c ../../lib/stats/stats.cpp -o ../../lib/stats/stats.o

clean:
	rm *.o *.x
