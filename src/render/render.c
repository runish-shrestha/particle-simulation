#include "render/render.h"

Vector2 Vector2_cast(const Vec2 vector) {

  Vector2 vector_cast = {
    .x = (float)vector.x_coordinate,
    .y = (float)vector.y_coordinate,
  };

  return vector_cast;
}

void Particle_draw(const Particle *particle) {
  // will be verbose

  Vector2 particle_position = Vector2_cast(particle->position);
  float radius = particle->radius;
  Color particle_color = particle->color;
  
  DrawCircleV(particle_position, radius, particle_color);
}
