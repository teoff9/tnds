// 22.10.24 by Matteo Fava

#pragma once
#include "field.h"
#include "particle.h"
#include "point.h"

class MaterialPoint : public Particle, public Point3D {
public:
  // constructor
  MaterialPoint(double _mass, double _charge, double x, double y, double z)
      : Particle{_mass, _charge}, Point3D{x, y, z} {};
  MaterialPoint(double x, double y, double z, Particle p)
      : Particle{p}, Point3D{x, y, z} {};
};