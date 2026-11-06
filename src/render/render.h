/**
 * @brief Rendering module which handles rendering for the particular simulator
*/
#ifndef RENDER_H
#define RENDER_H

#include "particle/particle.h"
#include "raylib.h"

/**
 *
 * @brief Cast a Vec2 vector to Vector2 for rendering
 *
 * _Warning_ Vector2 stores coordiantes in floats so this shouldn't be used for computation!
 * 
 * @param vector   Vec2 vector to be casted
 * @return vector_cast Vector2 vector cast from vector
 *
*/
Vector2 Vector2_cast(Vec2 vector);

/**
 *
 * @brief Draws the particle to the screen
 *
 * @param particle  the particle to be drawn on the screen
*/
void Particle_draw(const Particle *particle);

#endif
