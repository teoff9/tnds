//29.10.24 by Matteo Fava

#pragma once
#include "functions.h"
#include <cmath>
#include <iostream>
using namespace std;


double sign(double x) {
    if (x<0.0) return -1;
    else if (x>0.0) return 1;
    else return 0;
}

class Solver {
    public:
        Solver() : a{}, b{}, prec{}, n_max{}, n{} {}
        int get_n_iter() const {return n;}
        void set_a(double new_a) {a = new_a;}
        void set_b(double new_b) {b = new_b;}
        void set_prec(double new_prec) {prec = new_prec;}
        void set_max_n(double new_max) {n_max = new_max;}
        virtual double  find_root(Function &f, double x_min, double x_max, double _prec, int _n_max) =0;

    protected:
        double a, b; //[a,b]
        double prec; //precision
        int n_max; //maximum number of iterations
        int n; //actual number of iterations

};

class Bisection : public Solver {
    public: 
        Bisection() : Solver{} {}
        // -1 : intervallo sbagliato
        // -2 : n ha superato n max
        double find_root(Function &f, double x_min, double x_max, double _prec, int _n_max) override;
};

double Bisection::find_root(Function &f, double x_min, double x_max, double _prec = 1e-3, int _n_max=100) {
    if (sign(f(x_min)*sign(x_max) > 0)) {
        throw -1;
    }
    n_max = _n_max;
    a = x_min;
    b = x_max;
    prec = _prec;
    double c{};
    int n = 0;
    
    while (abs(b-a) > prec) {
        if (n > n_max) throw -2;
        else {
            n++;
            c = (b+a)/2;
            if ( sign(f(a)) * sign(f(c)) <= 0.0) {
                b = c;
            } else if ( sign(f(b)) * sign(f(c)) <= 0.0 ) {
                a = c;
            } else return 0.0;
        }
    }
    return 0.5*(b+a);
}