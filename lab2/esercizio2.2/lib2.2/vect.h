//01/10/2024 by Matteo Fava
//Libreria di vettore 

#pragma once

//classe vettore di double: n = size vettore, v = array allocato dinamicamente
class Vect {
    public:
        Vect(); //costruttore "vuoto"
        Vect(int); //costruttore
        ~Vect(); //distruttore
        Vect(const Vect&); //costruttore da elemento
        Vect(Vect&& V); //move constructor

        double& operator[](int i) const;
        Vect& operator=(const Vect&);

        int size() const; //restituisce n
        void set_element(int, double); //set di un elemento
        double get_element(int) const; //restituisci un elemento
        void swap(int, int); //swap di due elementi

    private:
        int n; //size di v
        double* v; //array allocato dinamicamente
        void crash_if_invalid_index(int) const; //check per validita di un index
};