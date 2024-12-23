// 22.10.24 by Matteo Fava
// Point3D
#pragma once
#include <cmath>
using namespace std;

class Point3D {
public:
  // costruttori
  Point3D();
  Point3D(double, double, double);

  // methods
  double get_x() const;
  double get_y() const;
  double get_z() const;
  double get_r() const;
  double get_phi() const;
  double get_theta() const;
  double get_rho() const;
  double distance_from(const Point3D &p) const;

private:
  double x;
  double y;
  double z;
};

Point3D::Point3D() : x{0.0}, y{0.0}, z{0.0} {}

Point3D::Point3D(double new_x, double new_y, double new_z)
    : x{new_x}, y{new_y}, z{new_z} {}

double Point3D::get_x() const { return x; }

double Point3D::get_y() const { return y; }

double Point3D::get_z() const { return z; }

double Point3D::get_r() const {
  Point3D zero{0.0, 0.0, 0.0};
  return distance_from(zero);
}
double Point3D::get_phi() const { return atan2(y, x); }

double Point3D::get_theta() const { return acos(z / get_r()); }
double Point3D::get_rho() const { return sqrt(x * x + y * y); }
double Point3D::distance_from(const Point3D &p) const {
  return sqrt(pow(get_x() - p.get_x(), 2) + pow(get_y() - p.get_y(), 2) +
              pow(get_z() - p.get_z(), 2));
}