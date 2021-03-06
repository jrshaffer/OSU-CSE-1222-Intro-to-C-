/*
  File: array_traverse.cpp
  Created by: Joseph Shaffer
  Creation Date: November 4, 2016
  Synopsis: Program reads in an 
  array of positive integers from the 
  user and prints out the array, 
  computes the average, and prints out
  all values of the array that are even
  and equal to or below the average value
*/

#include <iostream>
#include <iomanip>

using namespace std;

const int SIZE(10); // global constant for max size of array
  
// Function prototypes

// reads in array of integers from user
void read_list(int a[], int & num_elements);

// prints out array of integers
void print_array(const int a[], const int num_elements);

//computes and returns average of array
double compute_average(const int a[], const int num_elements);

//prints out elements that are even and below and equal to a certain value
void print_evens_below(const int a[], const int num_elements, const double val);

int main()
{
  // number of elements inputted into array
  int num_elements(0);
  // computed average of elements in array
  double avg(0.0);
  // initialize array to global constant
  int array[SIZE];

  // prompt user for positive integers and initialize array elements to 
  // inputted values
  read_list(array, num_elements);
	
  if (num_elements > 0)
  {
	// Display original list
	cout << endl << "You entered the list:" << endl;
	print_array(array, num_elements);
	
	// Compute average
	avg = compute_average(array, num_elements);
	cout << "Average = " << avg << endl;
	
	// Display list values less than the average
	cout << endl << "Even values at or below the average:" << endl; 
	print_evens_below(array, num_elements, avg);
  }
  else {
	cout << "The list is empty." << endl;
  }
  
  return 0;
}

// INSERT FUNCTIONS HERE
// reads in the list of postive integers from user
void read_list(int a[], int & num_elements) {
	cout << "Enter up to 10 positive numbers (ints) terminated by 0" << endl;
	cin >> a[num_elements];
	while (num_elements < SIZE && a[num_elements] != 0) {
		num_elements++;
		cin >> a[num_elements];	
	}	
}

// prints the array of integers
void print_array(const int a[], const int num_elements) {
	for (int i = 0; i < num_elements; i++) {
		cout << a[i] << " ";
	}
	cout << endl;	
}

// computes the average as type double of the array of integers
double compute_average(const int a[], const int num_elements) {
	double sum = 0.0;
	for (int i = 0; i < num_elements; i++) {
		sum += a[i];
	}
	return (sum / num_elements);
}


// prints all values of the array that are even and below or equal to a certain value
void print_evens_below(const int a[], const int num_elements, const double val) {
	for (int i = 0; i < num_elements; i++) {
		if (a[i] <= val && a[i] % 2 == 0) {
			cout << a[i] << " ";
		}
	}
	cout << endl;
}




