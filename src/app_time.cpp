//
//  app_time.cpp
//  motionByConservationOfEnergy
//
//  Created by OSAWASatoru on 6/25/17.
//
//

#include "./app_time.h"

AppTime::AppTime() {
  reset();
}

void AppTime::reset() {
  elapsed_time_ = ofGetElapsedTimeMillis();
  last_elapsed_time_ = elapsed_time_;
}

void AppTime::update() {
  last_elapsed_time_ = elapsed_time_;
  elapsed_time_ = ofGetElapsedTimeMillis();
}
