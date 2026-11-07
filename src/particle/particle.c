#include "particle/particle.h"
#include "vector/vec_math.h"

// == CONSTRUCTOR AND SETTERS ==

Particle Particle_create(const Vec2 initial_position_vector,
                         const Vec2 initial_velocity_vector,
                         const float initial_radius) {

  Particle particle = {
      .position = initial_position_vector,
      .velocity = initial_velocity_vector,
      .mass = 1,
      .coefficient_of_restitution = 1,
      .radius = initial_radius,
  };

  return particle;
}

void Particle_set_mass(Particle *particle, const double mass) {

  particle->mass = mass;
}

void Particle_set_coefficient_of_restitution(
    Particle *particle, const double coefficient_of_restitution) {

  particle->coefficient_of_restitution = coefficient_of_restitution;
}

void Particle_set_radius(Particle *particle, const float new_radius) {

  particle->radius = new_radius;
}

// == PHYSICS MEASUREMENT

double Particle_kinetic_energy(const Particle *particle) {

  double particle_velocity_squared = Vec2_norm_squared(particle->velocity);
  double kinetic_energy = 0.5 * particle->mass * particle_velocity_squared;

  return kinetic_energy;
}

Vec2 Particle_momentum(const Particle *particle) {

  Vec2 momentum = Vec2_scale(particle->velocity, particle->mass);
  return momentum;
}

// == PHYSICS UPDATES

void Particle_apply_force(Particle *particle, const Vec2 force_vector) {

  particle->force = Vec2_add(particle->force, force_vector);
}

void Particle_clear_force(Particle *particle) {

  particle->force = Vec2_create(0, 0);
}

void Particle_drift(Particle *particle, const double time_step) {
  particle->position =
      Vec2_add(particle->position, Vec2_scale(particle->velocity, time_step));
}

void Particle_kick(Particle *particle, const Vec2 acceleration_vector,
                   const double time_step) {

  particle->velocity =
      Vec2_add(particle->velocity, Vec2_scale(acceleration_vector, time_step));
}
