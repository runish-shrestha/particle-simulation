/**
 * @file particle.h
 * @brief defines the particle structure and methods
 *
 * This module defines the basic workings of the particle. How they are defined and how they are manipulated.
 *
 * This module _doesn't_ handle rendering of particles.
 *
*/

#ifndef PARTICLE_H 
#define PARTICLE_H

#include "vector/vec.h" 
#include <stdbool.h>

/** 
 * @brief Represents a 2D Particle. 
 *
 * @param position                      a Vec2 vector which stores the position of the particle
 * @param velocity                      a Vec2 vector which stores the velocity of the particle
 * @param mass                          a double which stores the mass of th particle
 * @param coefficient_of_restitution    a double which stores the coefficient of restitution
 * @param radius                        a float which stores the radius of the particle
 * 
 * @param force                         a Vec2 vector that stores the force on the particle.
*/
typedef struct {
  Vec2 position;
  Vec2 velocity;
  double mass;
  double coefficient_of_restitution;
  float radius;
  Vec2 force;
} Particle;

// == CONSTRUCTOR AND SETTERS ==

/**
 * @brief Creates a particle struct. 
 * 
 * _Notes_ It sets mass and coefficient_of_restitution to 1
 *
 * @param initial_position_vector           initial position vector
 * @param initial_velocity_vector           initial velocity vector
 * @param initial_radius                    radius of the particle
 *
 * @return particle                         particle struct with the given values
*/
Particle Particle_create(Vec2 initial_position_vector, Vec2 initial_velocity_vector, float initial_radius);

/**
 * @brief Sets the particle's mass
 *
 * @param particle    particle whose mass is to be set
 * @param mass        new mass
*/
void Particle_set_mass(Particle *particle, double mass);

/**
 * @brief Sets the particle's coefficient of restitution
 *
 * @param particle                      particle whose coefficient of restitution is to be set
 * @param coefficient_of_restitution    coefficient of restitution 
*/
void Particle_set_coefficient_of_restitution(Particle *particle, double coefficient_of_restitution);

/**
 * @brief Changes the radius of the particle
 *
 * @param particle    particle whose radius is to be changed
 * @param new_radius  new radius
*/
void Particle_set_radius(Particle *particle, float new_radius);

// == PHYSICS MEASUREMENT

/**
 * @brief Returns the particle's current kinetic energy
 *
 * @param particle            the particle whose kinetic is measured
 * 
 * @return kinetic_energy     the kinetic energy possessed by the particle at the time of measurement
*/
double Particle_kinetic_energy(const Particle *particle);

/**
 * @brief Returns the particle's current momentum
 *
 * @param particle            the particle whose kinetic is measured
 * 
 * @return momentum     the momentum possessed by the particle at the time of measurement
*/
Vec2 Particle_momentum(const Particle *particle);

// == PHYSICS UPDATES ==

/**
 * @breif Applies a force to the particle
 *
 * @param particle        the particle on which the force is applied
 * @param force_vector    the force vector acting on the particle 
*/
void Particle_apply_force(Particle *particle, Vec2 force_vector); 

/**
 * @brief Clears the force acting on the particle
 *
 * @param particle    the particle whose forces need to be cleared
*/
void Particle_clear_force(Particle *particle);

/**
 * @brief Changes the position of the particle based on its velocity and given time step
 *
 * @param particle    the particle to update
 * @param time_step   time step 
*/
void Particle_drift(Particle *particle, double time_step);

/**
 * @brief Changes the velocity of the particle based on the acceleration vector and the given time step
 *
 * @param particle              the particle to update
 * @param acceleration_vector   acceleration vector
 * @param time_step             time_step
*/
void Particle_kick(Particle *particle, Vec2 acceleration_vector, double time_step);


#endif

