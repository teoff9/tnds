esercizio2.2: esercizio2.2.o lib2.2/vect.o lib2.2/stats.o lib2.2/tests.o lib2.2/iofunctions.o 
	g++ esercizio2.2.o lib2.2/vect.o lib2.2/stats.o lib2.2/tests.o lib2.2/iofunctions.o  -o esercizio2.2

esercizio2.2.o: esercizio2.2.cpp
	g++ -c esercizio2.2.cpp -o esercizio2.2.o
lib2.2/vect.o: lib2.2/vect.cpp
	g++ -c lib2.2/vect.cpp -o lib2.2/vect.o
lib2.2/stats.o: lib2.2/stats.cpp
	g++ -c lib2.2/stats.cpp -o lib2.2/stats.o
lib2.2/tests.o: lib2.2/tests.cpp
	g++ -c lib2.2/tests.cpp -o lib2.2/tests.o
lib2.2/iofunctions.o: lib2.2/iofunctions.cpp
	g++ -c lib2.2/iofunctions.cpp -o lib2.2/iofunctions.o

clean:
	rm lib2.2/vect.o lib2.2/stats.o lib2.2/tests.o lib2.2/iofunctions.o 
	rm *.o esercizio2.2

