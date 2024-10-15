//15.10.24 by Matteo Fava

#include <format>
#include "lib4.0/gplot++.h"
#include "lib4.0/file_io.h"
#include "lib4.0/stats.h"
#include "lib4.0/tests.h"
using namespace std;

int main() {
    test_statistics_with_stride();
    Gnuplot plt;
    plt.redirect_to_png("plot.png");
    const int stride{7};

    for (int y{1941}; y<2024; y++){
        vector<double> data = file_to_vect<double>(format("TemperatureMilano/{}.txt", y));
        double m = average<double>(data, stride);
        double std = std_dev<double>(data, stride);
        cout << format("{} : {} +- {}\n", y, m, std);
        plt.add_point_yerr(y, m, std);
    }
    plt.plot_yerr();
    plt.show();

    return 0;
}