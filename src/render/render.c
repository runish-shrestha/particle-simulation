#include "render/render.h"
#include <raylib.h>

// == UTILITY ==

Vector2 Vector2_cast(const Vec2 vector) {

  Vector2 vector_cast = {
      .x = (float)vector.x_coordinate,
      .y = (float)vector.y_coordinate,
  };

  return vector_cast;
}

// == PARTICLE RENDER OBJECT

Particle_Render_Obj Particle_Render_Obj_create(Color fill_color,
                                               Color outline_color,
                                               float opacity) {

  Particle_Render_Obj particle_render_obj = {
      .fill_color = fill_color,
      .outline_color = outline_color,
      .opacity = opacity,
  };

  return particle_render_obj;
}

void Particle_Render_Obj_set_fill_color(Particle_Render_Obj *render_obj,
                                        Color new_fill_color) {

  render_obj->fill_color = new_fill_color;
}

void Particle_Render_Obj_set_outline_color(Particle_Render_Obj *render_obj,
                                           Color new_outline_color) {

  render_obj->outline_color = new_outline_color;
}

void Particle_Render_Obj_set_opacity(Particle_Render_Obj *render_obj,
                                     float new_opacity) {

  render_obj->opacity = new_opacity;
}

// == RENDER ENGINE ==

void Particle_draw(const Particle *particle,
                   const Particle_Render_Obj *render_obj) {

  Vector2 position = Vector2_cast(particle->position);
  Color particle_color = Fade(render_obj->fill_color, render_obj->opacity);
  DrawCircleV(position, particle->radius, particle_color);
  DrawCircleLinesV(position, particle->radius * 0.05f,
                   render_obj->outline_color);
}


