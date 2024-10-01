esercizio2.1: esercizio2.1.o ../esercizio2.2/lib2.2/vect.o 
	g++ esercizio2.1.o ../esercizio2.2/lib2.2/vect.o  -o esercizio2.1

esercizio2.1.o: esercizio2.1.cpp
	g++ -c esercizio2.1.cpp -o esercizio2.1.o
../esercizio2.2/lib2.2/vect.o: ../esercizio2.2/lib2.2/vect.cpp
	g++ -c ../esercizio2.2/lib2.2/vect.cpp -o ../esercizio2.2/lib2.2/vect.o

clean:
	rm ../esercizio2.2/lib2.2/vect.o 
	rm *.o esercizio2.1

