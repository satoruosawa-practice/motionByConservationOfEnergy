//
//  sphere.cpp
//  motionByConservationOfEnergy
//
//  Created by OSAWASatoru on 6/25/17.
//
//

#include "sphere.h"

Sphere::Sphere(const AppTime &app_time) {
  app_time_ = &app_time;
  reset();
}

void Sphere::reset() {
  speed_ = 0.0;
  position_ = 1.0;
  mass_ = 1.0;
  radius_ = 0.1;
}

void Sphere::update() {
  updatePos();
}

void Sphere::updatePos() {
  position_ += speed_ * app_time_->getDeltaTimeS();
}

void Sphere::draw() {
  ofDrawCircle(position_ * PX_PER_METER,
               ofGetHeight() * 0.5,
               radius_ * PX_PER_METER);
}

void Sphere::drawParameters() {
  ofDrawBitmapString("mass: " + ofToString(mass_, 1) +
                     " kg", 10, 40);
  ofDrawBitmapString("speed: " +
                     ofToString(speed_, 2) +
                     " m/s", 10, 60);
  ofDrawBitmapString("position: " +
                     ofToString(position_, 2) +
                     " m", 10, 80);
}

void Sphere::doWork(float force, float displacement) {
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
