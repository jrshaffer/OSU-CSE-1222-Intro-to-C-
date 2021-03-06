// File: fallDist.cpp
// Created by: Joseph Shaffer
// Created on: September 9, 2016

/* Compute the distance an object falls */

#include <iostream>
using namespace std;

int main()
{ 
  double g = 32.185;      // 32.185 feet per second^2
  double t;               // time (in seconds)
  double velocity;        // velocity after time t
  double distance;        // distance after time t

  cout << "Enter the time: ";
  cin >> t;

  // Compute the velocity and distance
  velocity = g * t;
  distance = velocity * 0.5 * t;

  cout << "After " << t << " seconds, the velocity is " << velocity << " feet per second." << endl;
  cout << "After " << t << " seconds, the falling distance is " << distance << " feet." << endl;

  return(0);
}
