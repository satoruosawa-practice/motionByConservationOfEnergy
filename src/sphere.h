//
//  sphere.h
//  motionByConservationOfEnergy
//
//  Created by OSAWASatoru on 6/25/17.
//
//

#pragma once

#include "ofMain.h"

class Sphere {
 public:
  void setup();
  // getter
  float getSpeed() { return speed_; }
  float getMass() { return mass_; }
  void addForce(float force, float displacement);

 private:
  float culculateSpeedFromWork(const float &work,
                               const float &mass,
                               const float &speed);
  float culculateWork(const float &force,
                      const float &displacement);
  float culculateKineticEnergy(const float &mass,
                               const float &speed);
  float speed_;
  float mass_;
};
