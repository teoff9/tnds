//05.11.24 by Matteo Fava

#pragma once
#include <functional>
#include <cstdlib>
#include <iostream>
#include <cmath>
using namespace std;

//Classe virtuale Integral
class Integral {
    public:
        Integral() : a{0}, b{0}, h{0}, sign{0} {};
        double integrate(double _a, double _b, int n_steps, function<double (double)> f){
            check_interval(_a, _b);
            return sign * calculate(n_steps, f);
        }
    
    protected:
        void check_interval(double _a, double _b){
            a = min(_a,_b);
            b = max(_a, _b);
            if (_a < _b ) sign = 1;
            else sign = -1;
        }
        //Metodi da fare override
        virtual double calculate(int, function<double (double)>) = 0;
        
        double a, b;
        double sign;
        double h;

};

//Integrale Midpoint
class MidPoint : public Integral {
    public:
        MidPoint() : Integral() {};
    private:
        virtual double calculate(int N, function<double (double)> f) override {
            if (N < 0) {
                cerr << "N steps can't be less than 0!\n";
                exit(-1);
            }
            //Step size
            h = (b-a)/N;
            //Accumulate
            double acc{0};
            for (int i = 0; i < N; i++) {
                acc += f( a + h*(i + 0.5) );
            }

            //Return integral
            return h*acc;
        }
};

//Integrale Simpson
class Simpson : public Integral {
    public:
        Simpson() : Integral() {};
    
    private:
        virtual double calculate(int N, function<double (double)> f) {
            //FUNZIONA SOLO CON N PARI
            if (N%2 == 1) N = N+1;

            h = (b-a)/N;
            double acc{ f(a) + f(b) };
            for (int i = 1; i< N; i++) {
                acc += 2.0* (1.0 + i%2)*f( a + i * h );
            }
            return h * acc / 3.0;
        }
};

//Trapezi
class Trapezoid : public Integral {
    public:
        Trapezoid() : Integral() {};
        double integrate_prec(double _a, double _b, double prec, function<double (double)> f) {
            check_interval(_a,_b);
            //stima N
            double N{2};
            prev_approx = (f(a) +f(b))/2;
            approx = prev_approx + f( a + (b-a)/2 );
            while (4.0*fabs(approx-prev_approx)/3.0 > prec) {
                N *= 2;
                prev_approx = approx;
                approx = calculate(N, f);
            }
    
            //calcola integrale
            return sign * approx;
        }

    private:    
        virtual double calculate(int N, function<double (double)> f) override {
            h = (b-a)/N;
            double acc{ 0.5*( f(a) + f(b) ) };
            for (int i = 1; i<N; i++) {
                acc += f(a + i * h);
            }
            return h*acc;
        }
        double prev_approx, approx;
};