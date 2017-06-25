//
//  sphere.cpp
//  motionByConservationOfEnergy
//
//  Created by OSAWASatoru on 6/25/17.
//
//

#include "sphere.h"

void Sphere::setup() {
  speed_ = 0.0;
  mass_ = 1.0;
}

void Sphere::addForce(float force, float displacement) {
  float work = culculateWork(force, displacement);
  speed_ = culculateSpeedFromWork(work, mass_, speed_);
}

float Sphere::culculateSpeedFromWork(const float &work,
                                    const float &mass,
                                    const float &speed) {
  float sFinal;
  sFinal = work + culculateKineticEnergy(mass, speed);
  sFinal *= 2.0 / mass;
  sFinal = sqrt(sFinal);
  return sFinal;
}

float Sphere::culculateWork(const float &force, const float &displacement) {
  return displacement * force;
}

float Sphere::culculateKineticEnergy(const float &mass, const float &speed) {
  return 0.5 * mass * speed * speed;
}

