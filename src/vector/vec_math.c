#include "vector/vec_math.h"
#include <math.h>

Vec2 Vec2_sub(Vec2 vector1, Vec2 vector2) {
  Vec2 difference = Vec2_add(vector1, Vec2_scale(vector2, -1));
  return difference;
}

double Vec2_norm_squared(Vec2 a) {
  double vector_norm_squared = Vec2_dot(a, a);
  return vector_norm_squared;
}

double Vec2_norm(Vec2 a) {
  double vector_norm = sqrt(Vec2_norm_squared(a));
  return vector_norm;
}
