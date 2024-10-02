es012: es012.o lib012/stats/stats.o lib012/sorting/sorting.o 
	g++ es012.o lib012/stats/stats.o lib012/sorting/sorting.o  -o es012

es012.o: es012.cpp
	g++ -c es012.cpp -o es012.o
lib012/stats/stats.o: lib012/stats/stats.cpp
	g++ -c lib012/stats/stats.cpp -o lib012/stats/stats.o
lib012/sorting/sorting.o: lib012/sorting/sorting.cpp
	g++ -c lib012/sorting/sorting.cpp -o lib012/sorting/sorting.o

clean:
	rm lib012/stats/stats.o lib012/sorting/sorting.o 
	rm *.o es012

