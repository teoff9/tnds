//23.12.24 by Matteo Fava

#pragma once

//interp lineare
double interp(double x0, double y0, double x1, double y1, double y) {
  return x0 + (x0 - x1) / (y0 - y1) * (y - y0);
}
