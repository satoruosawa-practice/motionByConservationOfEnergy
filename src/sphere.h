//
//  sphere.h
//  motionByConservationOfEnergy
//
//  Created by OSAWASatoru on 6/25/17.
//
//

#pragma once

#include "ofMain.h"
#include "./global_definition.h"
#include "./app_time.h"

class Sphere {
 public:
  Sphere() = default;
  explicit Sphere(const AppTime &app_time);
  void reset();
  void update();
  void draw();
  void drawParameters();
  void doWork(float work);
  // getter
  float getSpeed() { return speed_; }
  float getMass() { return mass_; }

 private:
  void updatePos();
  float culculateEnergyFromSpeed(const float &speed,
                                 const float &mass);
  float culculateSpeedFromEnergy(const float &energy,
                               const float &mass);
  const AppTime * app_time_;
  float speed_;  // m/s
  float position_;  // m
  float mass_;  // kg
  float radius_;  // m
};
