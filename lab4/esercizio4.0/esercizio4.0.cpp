// 15.10.24 by Matteo Fava

#include "lib4.0/file_io.h"
#include "lib4.0/gplot++.h"
#include "lib4.0/stats.h"
#include "lib4.0/tests.h"
#include <format>
using namespace std;

int main() {
  //tests
  test_statistics_with_stride();

  //setup the plot
  Gnuplot plt;
  plt.redirect_to_png("plot.png");
  const int stride{7};

//loop through the years and calc m ans std with stride
  for (int y{1941}; y < 2024; y++) {
    vector<double> data =
        file_to_vect<double>(format("TemperatureMilano/{}.txt", y));
    double m = average<double>(data, stride);
    double std = std_dev<double>(data, stride);
    cout << format("{} : {} +- {}\n", y, m, std);
    plt.add_point_yerr(y, m, std);
  }
  plt.plot_yerr();
  plt.show();

  cout << " => Created 'plot.png'\n";

  return 0;
}