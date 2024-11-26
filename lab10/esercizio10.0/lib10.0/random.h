//26.11.2024 by Matteo Fava

#pragma once
#include <cmath>
using namespace std;

//RandomGen: x(j+1) = (a*x(j)+b)mod(m)
class RandomGen {
    public:
        RandomGen() : a{1664525}, c{1013904223}, m{(unsigned int)pow(2,31)} {};
        RandomGen(unsigned int seed_) : seed{seed_}, a{1664525}, c{1013904223}, m{(unsigned int)pow(2,31)}{};
        void set_a(unsigned int a_) {a = a_;};
        void set_c(unsigned int c_) {c = c_;};
        void set_m(unsigned int m_) {m = m_;};
        void reset_seed(unsigned int new_seed_) {seed = new_seed_;};
        double rand();
        double unif(double x_min, double x_max);
        double expo(double mean);
        double gauss(double mean, double sigma);
        double gauss_aer(double mean, double sigma);

    private:
        unsigned int seed, a, c, m;
};

//Generate random double between 0 and 1 (not included)
double RandomGen::rand() {
    seed = (a*seed + c)%m;
    return (double)seed/m;
}

//Uniform distribution
double RandomGen::unif(double x_min, double x_max){
    return x_min+(x_max-x_min)*rand();
}

//Exponential distribution
double RandomGen::expo(double mean) {
    return -log(1-rand());
}

//Gaussian distribution with Box-Muller method
double RandomGen::gauss(double mean, double sigma){
    return mean + sigma*sqrt( -2.*log(rand()) )*cos(2*M_PI*rand());
}

//Gaussian distribution with Accet&Reject method
double RandomGen::gauss_aer(double mean, double sigma){
    double ans{}, x{};
    do {
        x = unif(-5., 5.);
        ans = rand();
    } while (ans >= exp(-x*x/2));
    return mean+x*sigma;
}