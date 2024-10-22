//22.10.24 by Matteo Fava

#pragma once
#include "mat_point.h"
#include "field.h"

const double epsilon_zero = 8.8541878188e-12;
const double pi = 3.14159265359;

VectorField electric_field(MaterialPoint& mp, Point3D pos) {
    double f = mp.get_charge() / (4*pi*epsilon_zero*pow(pos.distance_from(Point3D{mp}), 3));

    return VectorField{ pos,
                        f * (pos.get_x() - mp.get_x()), 
                        f * (pos.get_y() - mp.get_y()), 
                        f * (pos.get_z() - mp.get_z())};
}