//05.11.24 by Matteo Fava

#pragma once
#include <functional>
#include <cstdlib>
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
        //Metodo da fare override
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