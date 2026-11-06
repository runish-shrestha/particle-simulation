#include "vector/vec_math.h"
#include <math.h>

double Vec2_norm_squared(Vec2 a) {
  double vector_norm_squared = Vec2_dot(a, a);
  return vector_norm_squared;
}

double Vec2_norm(Vec2 a) {
  double vector_norm = sqrt(Vec2_norm_squared(a));
  return vector_norm;
}
