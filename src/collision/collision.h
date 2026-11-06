/**
 * Handles collision between particles
 */

#ifndef COLLISION_H
#define COLLISION_H

#include "particle/particle.h"
#include <stdbool.h>
#include <stdlib.h>

/**
 * @brief Checks whether particle is beyond theh x bound
 *
 * @param particle    a pointer to the particle to be bound checked
 * @param x_min       minimum x bound
 * @param x_max       maximum x bound
 *
 * @return is_bounded   whether the particle is bounded
 */
bool Particle_is_within_bound_x(const Particle *particle, size_t x_min,
                                size_t x_max);

/**
 * @brief Checks whether particle is beyond the y bound
 *
 * @param particle    a pointer to the particle to be bound checked
 * @param y_min       minimum y bound
 * @param y_max       maximum y bound
 *
 * @return is_bounded   whether the particle is bounded
 */
bool Particle_is_within_bound_y(const Particle *particle, size_t y_min,
                                size_t y_max);

/**
 * @brief Checks whether particle is beyond bound.
 *
 * @param particle    a pointer to the particle to be bound checked
 * @param x_min       minimum x bound
 * @param x_max       maximum x bound
 * @param y_min       minimum y bound
 * @param y_max       maximum y bound
 *
 * @return is_bounded   whether the particle is bounded
 */

/**
 * @brief Clamps particle's x-coordinate in a bounded axis defined by the user
 *
 * @param particle          a pointer to the particle that needs to be bounded
 * @param x_min             minimum x value of the bounding box
 * @param x_max             minimum y value of the bounding box
 */
void Particle_clamp_x(Particle *particle, size_t x_min, size_t x_max);

/**
 * @brief Clamps particle's y-coordinate in a bounded axis defined by the user
 *
 * @param particle            a pointer to the particle that needs to be bounded
 * @param y_min               minimum y value of the bounding box
 * @param y_max               maximum y value of the bounding box
 */
void Particle_clamp_y(Particle *particle, size_t y_min, size_t y_max);

/**
 * @brief Clamps particle into a bounded box defined by the user
 *
 * @param particle          a pointer to the particle that needs to be bounded
 * @param x_min             minimum x value of the bounding box
 * @param x_max             minimum y value of the bounding box
 * @param y_min             minimum y value of the bounding box
 * @param y_max             maximum y value of the bounding box
 */
void Particle_clamp(Particle *particle, size_t x_min, size_t x_max,
                    size_t y_min, size_t y_max);

/**
 * @brief Handles wall collision
 *
 * @param particle    particle that's colliding with the wall
 *
 * @param x_min             minimum x value of the wall
 * @param x_max             minimum y value of the wall
 * @param y_min             minimum y value of the wall
 * @param y_max             maximum y value of the wall
 */
void Particle_wall_collision(Particle *particle, size_t x_min, size_t x_max,
                             size_t y_min, size_t y_max);

#endif
