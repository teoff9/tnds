ARG0 := -std=c++20

esercizio10.2: esercizio10.2.o lib10.2/test_random.h lib10.2/integral_mc.h lib10.2/test_integral_mc.h
	g++ $(ARG0) -o esercizio10.2 esercizio10.2.o     

esercizio10.2.o: esercizio10.2.cpp
	g++  $(ARG0) -c esercizio10.2.cpp

histo: histo.o 
	g++ $(ARG0) histo.o -o histo
	./histo

histo.o: histo.cpp lib10.2/gplot++.h
	g++ $(ARG0) -c histo.cpp

clean:
	rm esercizio10.2 esercizio10.2.o
	rm histo.o histo
clean_all:
	rm data/*.txt
	rm esercizio10.2 esercizio10.2.o
	rm histo.o histo
