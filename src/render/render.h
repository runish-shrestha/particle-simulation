/**
 * @brief Rendering module which handles rendering for the particular simulator
 */
#ifndef RENDER_H
#define RENDER_H

#include "particle/particle.h"
#include "raylib.h"

// == UTILITY ==

/**
 * @brief Cast a Vec2 vector to Vector2 for rendering
 *
 * _Warning_ Vector2 stores coordiantes in floats so this shouldn't be used for
 * computation!
 *
 * @param vector   Vec2 vector to be casted
 * @return vector_cast Vector2 vector cast from vector
 *
 */
Vector2 Vector2_cast(Vec2 vector);

// == PARTICLE RENDER OBJ ==

/**
 * @brief Handles rendering of the particle object
 *
 * @param fill_color      the fill color of the particle
 * @param outline_color   the outline color of the particle
 * @param opacity         the opacity of the particle
 */
typedef struct {
  Color fill_color;
  Color outline_color;
  float opacity;
} Particle_Render_Obj;

/**
 * @brief Creates a particle render object
 *
 * @param fill_color      the fill color of the particle
 * @param outline_color   the outline color of the particle
 * @param opacity         the opacity of the particle
 */
Particle_Render_Obj Particle_Render_Obj_create(Color fill_color,
                                               Color outline_color,
                                               float opacity);

/**
 * @brief Changes a particle render object's fill_color
 *
 * @param render_obj      the render_obj that needs to be changed
 * @param new_fill_color  the new fill color
 */
void Particle_Render_Obj_set_fill_color(Particle_Render_Obj *render_obj,
                                        Color new_fill_color);

/**
 * @brief Changes a particle render object's outline_color
 *
 * @param render_obj          the render_obj that needs to be changed
 * @param new_outline_color   the new outline color
 */
void Particle_Render_Obj_set_outline_color(Particle_Render_Obj *render_obj,
                                           Color new_outline_color);

/**
 * @brief Changes a particle render object's opacity
 *
 * @param render_obj          the render_obj that needs to be changed
 * @param new_opacity         the new opactiy
 */
void Particle_Render_Obj_set_opacity(Particle_Render_Obj *render_obj,
                                     float new_opacity);

// == RENDERING ENGINE

/**
 *
 * @brief Draws the particle to the screen
 *
 * @param particle      the particle to be drawn on the screen
 * @param render_obj    render object for how the particle should be drawn
 */
void Particle_draw(const Particle *particle,
                   const Particle_Render_Obj *render_obj);

#endif
