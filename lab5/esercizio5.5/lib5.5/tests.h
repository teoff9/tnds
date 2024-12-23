// 22.10.24 by Matteo Fava

#pragma once
#include "field.h"
#include "mat_point.h"
#include "physics.h"
#include "point.h"
#include <cassert>
#include <iostream>
using namespace std;

// Funzione che controlla se un numero n e' a meno di delta da m
bool is_close(double n, double m, double delta = 1e-7) {
  return ((double)fabs(n - m) < delta);
}

void test_coordinates() {
  Point3D p{1, 2, 3};

  assert(is_close(p.get_x(), 1));
  assert(is_close(p.get_y(), 2));
  assert(is_close(p.get_z(), 3));

  assert(is_close(p.get_r(), 3.7416573867739));
  assert(is_close(p.get_phi(), 1.1071487177941));
  assert(is_close(p.get_theta(), 0.64052231267943));
  assert(is_close(p.get_rho(), 2.2360679774998));

  cout << "Point3D works correctly. All tests passed!\n";
}

void test_electric_field() {
  MaterialPoint p1{0.0, 5e-7, 5, 3, -2};
  Point3D pos{-2, 4, 1};
  VectorField v{electric_field(p1, pos)};

  assert(is_close(v.get_fx(), -69.41150052142065));
  assert(is_close(v.get_fy(), 9.915928645917235));
  assert(is_close(v.get_fz(), 29.747785937751708));

  cerr << "Electric field works correctly. All tests passed!\n";
}