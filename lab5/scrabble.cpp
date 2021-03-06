// File: scrabble.cpp
// Created by: Joseph Shaffer
// Created on: September 28, 2016
/* Synopsis: This program takes in 
   a phrase from the user and counts
   the number of occurrences of the 
   letters a, g, m, f, k, and j, which
   each have different point values, 
   thus the program finds the point total
   for each letter based on its point value
   and number of occurrences and sums the
   point values of all these letters for
   an overall point total for the phrase given.
*/

#include <iostream>
#include <cmath>

using namespace std;

int main() {
	
	/* These integers will be updated to keep track of number of times
	   each of these letters appears in the phrase given. So it is the
	   count for each letter. Thus initialize each to 0
	*/
	int a_count(0), g_count(0), m_count(0), f_count(0), k_count(0), j_count(0);
	// Separated these variables to keep from having one long line of declarations
	
	/* These are the point values for each of the letters,
	   thus they are initialized to the given point values and won't change
	*/
	int a_value(1), g_value(2), m_value(3), f_value(4), k_value(5), j_value(8);
	// Integer equal to character value * character count
	// Break down program a little more and avoid long sum equation	
	int aPoints, gPoints, mPoints, fPoints, kPoints, jPoints;

	int totalPoints; // Will be the sum of all point values for each letter
	char input; // The inputted character from user

	cout << "Enter text: " << endl;
	cin >> input;
	cout << endl;

	// Keep looping if input character is not '.' or '!'
	// If either of those charecters are inputted then stop
	while (input != '.' && input != '!') {
		if (input == 'a' || input == 'A') // check if input is A
			a_count++;
		if (input == 'g' || input == 'G') // Check if input is G
			g_count++;
		if (input == 'm' || input == 'M') // Check if input is M
			m_count++; 
		if (input == 'f' || input == 'F') // check if input is f
			f_count++;
		if (input == 'k' || input == 'K') //check if input is k
			k_count++;
		if (input == 'j' || input == 'J') // check if input is j
			j_count++;
		cin >> input;
	}
	
	// Find point total for each character
	aPoints = a_value * a_count;
	gPoints = g_value * g_count;
	mPoints = m_value * m_count;
	fPoints = f_value * f_count;
	kPoints = k_value * k_count;
	jPoints = j_value * j_count;

	// Sum point totals for all characters
	totalPoints = aPoints + gPoints + mPoints + fPoints + kPoints + jPoints;

	// Print out count for each letter
	cout << "Number of a's (worth 1 point each) : " << a_count << endl;
	cout << "Number of g's (worth 2 points each) : " << g_count << endl;
	cout << "Number of m's (worth 3 points each) : " << m_count << endl;
	cout << "Number of f's (worth 4 points each) : " << f_count << endl;
	cout << "Number of k's (worth 5 points each) : " << k_count << endl;
	cout << "Number of j's (worth 8 points each) : " << j_count << endl;
	cout << endl;

	// Print out total score
	cout << "Total score: " << totalPoints;

	return 0;
}
