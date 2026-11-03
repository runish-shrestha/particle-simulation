#include "vector/vec.h"

Vec2 Vec2_create(const double x_coordinate, const double y_coordinate) {

  Vec2 vector = {
    .x_coordinate = x_coordinate,
    .y_coordinate = y_coordinate,
  };

  return vector;
}

Vec2 Vec2_add(const Vec2 a, const Vec2 b) {

  Vec2 sum = {
    .x_coordinate = a.x_coordinate + b.x_coordinate,
    .y_coordinate = a.y_coordinate + b.y_coordinate,
  };

  return sum;
}

Vec2 Vec2_scale(const Vec2 a, const double s) {

  Vec2 scaled_vector = {
    .x_coordinate = s * a.x_coordinate,
    .y_coordinate = s * a.y_coordinate,
  };

  return scaled_vector;
}

double Vec2_dot(const Vec2 a, const Vec2 b) {

  double dot_product = a.x_coordinate * b.x_coordinate + a.y_coordinate * b.y_coordinate;

  return dot_product;
}



