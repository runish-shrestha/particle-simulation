#include "particle.h"
#include "vector/vec_math.h"
#include "raylib.h" 

// == CONSTRUCTOR AND SETTERS ==

Particle Particle_create(const Vec2 initial_position_vector, const Vec2 initial_velocity_vector, const float initial_radius, const Color initial_color) {

  Particle particle = {
    .position = initial_position_vector,
    .velocity = initial_velocity_vector,
    .radius = initial_radius,
    .color = initial_color,
  };

  return particle;
}

void Particle_set_mass(Particle *particle, const double mass) {

  particle->mass = mass;
}

void Particle_set_coefficient_of_restitution(Particle *particle, const double coefficient_of_restitution) {

  particle->coefficient_of_restitution = coefficient_of_restitution;
}

void Particle_set_radius(Particle *particle, const float new_radius) {

  particle->radius = new_radius;
}

void Particle_set_color(Particle *particle, const Color new_color) {
  
  particle->color = new_color;
}

// == PHYSICS MEASUREMENT

double Particle_kinetic_energy(const Particle *particle) {

  double particle_velocity_squared = Vec2_norm_squared(particle->velocity);
  double kinetic_energy = 0.5 * particle->mass * particle_velocity_squared;

  return kinetic_energy;
}

double Particle_momentum(const Particle *particle) {

  double momentum = particle->mass * Vec2_norm(particle->velocity);
  return momentum;
}

// == PHYSICS UPDATES

void Particle_apply_force(Particle *particle, const Vec2 force_vector) {

  particle->force = force_vector;
}

void Particle_clear_force(Particle *particle) {

  particle->force = Vec2_create(0, 0);
}

void Particle_drift(Particle *particle, const double time_step) {
  particle->position = Vec2_add(particle->position, Vec2_scale(particle->velocity, time_step));
}

void Particle_kick(Particle *particle, const Vec2 acceleration_vector, const double time_step) {
  
  particle->velocity = Vec2_add(particle->velocity, Vec2_scale(acceleration_vector, time_step));
}

