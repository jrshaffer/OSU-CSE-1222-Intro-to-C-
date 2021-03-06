/*
  File: bodes_law.cpp
  Created by: Joseph Shaffer
  Creation Date: October 21, 2016
  Synopsis:
	Computes the distances of planets Earth, Saturn, and Neptune from the sun in
	astronomical units, miles, and meters
*/

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
 
int main()
{
	const double au_to_miles(93000000); // converts astronomical units to miles
	const double miles_to_meters(1609.344); // converts miles to meters
		
	/* variables of type double respresenting the distance to earth,
	   saturn and neptune from the sun in astronomical units, miles,
	   and meters */
	double dist_au_earth(0.0), dist_au_saturn(0.0), dist_au_neptune(0.0);
	double dist_miles_earth(0.0), dist_miles_saturn(0.0), dist_miles_neptune(0.0);
	double dist_meters_earth(0.0), dist_meters_saturn(0.0), dist_meters_neptune(0.0);
	
	/* Initialize the values of distance from sun to earth, saturn, and neptune in
	   astronomical units through given equation and calculation with
	   values for n given */
	dist_au_earth = (4 + 3 * pow(2, 3 - 2)) / 10;
	dist_au_saturn = (4 + 3 * pow(2, 6 - 2)) / 10;
	dist_au_neptune = (4 + 3 * pow(2, 8 - 2)) / 10;
	
	/* Initialize the variables for the distance from sun to earth, saturn, and neptune
	   in miles by converting from astronomical units to miles */
	dist_miles_earth = dist_au_earth * au_to_miles;
	dist_miles_saturn = dist_au_saturn * au_to_miles;
	dist_miles_neptune = dist_au_neptune * au_to_miles;

	/* Initialize the variables for the distance from sun to earth, saturn, and neptune
	   in meters by converting from miles to meters */
	dist_meters_earth = dist_miles_earth * miles_to_meters;
	dist_meters_saturn = dist_miles_saturn * miles_to_meters;
	dist_meters_neptune = dist_miles_neptune * miles_to_meters;	
	
	// Print out headers of tables
	cout << endl << "Planet  Astro Units (est.)  Miles (est.)  Meters (est.)" << endl ;

	// print out line under headers
	cout << "-------------------------------------------------------" << endl;

	// Long cout lines instead of separate lines to change format from fixed and scientific, and change precision because iomanip allows this and made it easy to copy and paste

	/* First set width to 8 and format to left for row header or name of planet
	  Set format to fixed, to the right, a precision of 3 and width to 11 for distance in au
	  Set format to scientific with precision of 2 and width of 21 for distance in miles
	  Format already scientific with precision of 3 and width of 15 for distance in meters */

	// First line prints out row for earth
	cout << setw(8) << left << "Earth" << fixed << right << setprecision(3) << setw(11) << dist_au_earth << scientific << setprecision(2) << setw(21) << dist_miles_earth << setprecision(3) << setw(15) << dist_meters_earth << endl ;

	// Second line prints out row for saturn
	cout << setw(8) << left << "Saturn" << fixed << right << setprecision(3) << setw(11) << dist_au_saturn << scientific << setprecision(2) << setw(21) << dist_miles_saturn << setprecision(3) << setw(15) << dist_meters_saturn << endl ;

	// Third line prints out row for neptune
	cout << setw(8) << left << "Neptune" << fixed << right << setprecision(3) << setw(11) << dist_au_neptune << scientific << setprecision(2) << setw(21) << dist_miles_neptune << setprecision(3) << setw(15) << dist_meters_neptune << endl; 
	
	
	return 0;
}  
