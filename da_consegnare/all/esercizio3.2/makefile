LIBS := `root-config --libs`
CXXFLAGS := -g3 -Wall --pedantic -std=c++23 `root-config --cflags`

esercizio3.2: esercizio3.2.cpp lib3.2/iofunctions.h
	g++ -o esercizio3.2 esercizio3.2.cpp  $(CXXFLAGS) $(LIBS)

clean:
	rm esercizio3.2
