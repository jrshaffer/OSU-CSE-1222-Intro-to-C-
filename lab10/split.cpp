/* File: split.cpp
   Created By: Joseph Shaffer
   Created on: November 13, 2016
   Synopsis: This program will create an array
   of a size determined by the user and will add
   the number of negative and non-negative integers
   to the array that are given to the user. The program
   will take this array, count the number of negative
   integers and count the number of non-negative integers,
   and create two new arrays by these counts. The program
   will output two arrays, one containing the negative
   integers from the original array, and one outputting 
   the non-negative integers from the original array.
*/

#include <iostream>
#include <cstdlib>
using namespace std;

/* Any parameters passed as constant by reference, is to limit
   copying the value to another place in memory
*/

/* Procedure count has no return value and is thus void.
   The procedure takes in a pointer to an array, a constant value
   for the number of elements of the array, and two integers by reference
   to count the number of negative and non-negative elements of the array.
   The procedure counts the number of negative integers and non-negative
   integers of the given array and given size.
*/
void count(int *array, const int n, int &negCount, int &nonnegCount);

/* Procedure split takes in 6 parameters and returns nothing. It takes in three pointers
   to three different arrays and the size of each of those array as constants. 
   The procedure will traverse the first array and for every negative integer found, that value will be copied
   and put into the second array, while for every non-negative integer found in the first array
   that value will be copied and be put into the third array. The program will print an error if
   the number copied to the second array or third array does not equal the size of the second or third
   array, because that would mean the program as a whole failed to count the number of negative or non-
   negative integers stored in the original array.
*/
void split(int *array, const int n, int *neg, const int negCount, int *nonneg, const int nonnegCount);

/* procedure print_array takes in a pointer to an array and the size of the array as a constant
   and has no return value. The procedure simply prints out the contents of the given array with
   each element of the array being separated by a space for aesthetic reasons.
*/
void print_array(int *array, const int n);

int main() {

	/* declare and initialize the integers for the size of the original array,
           the size of the negative array, and the size of the non-negative array
 	   to be 0
	*/
	int n(0), negCount(0), nonnegCount(0);
	
	/* declare 3 pointers to integers that will point to the 3 separate arrays
	   of integers 
	*/
	int *allInts;
	int *neg;
	int *nonneg;
	
	// ask user for the number of elements of the original array
	cout << "Enter number of elements: ";
	// initialize n to be the number of elements
	cin >> n;
	
	// allocate the original array to the size of the number of elements
	allInts = new int[n];
	
	// Ask user for the elements of the array
	cout << "Enter list: " << endl;
	
	// Initialize the values of the elements to the user's input.
	for (int i = 0; i < n; i++) {
		cin >> allInts[i];
	}
	
	// Use count to find the number of negative elements
        // and non-negative elements of the array
	count(allInts, n, negCount, nonnegCount);

	// Allocate neg array to size of count of negative elements
	neg = new int[negCount];

	// Allocate non-neg array to size of count of non-negative elements
	nonneg = new int[nonnegCount];

	/* Copy non-negative elements from original array to non-negative array
	   and copy negative elements from original array to negative array
	*/
	split(allInts, n, neg, negCount, nonneg, nonnegCount);


	// Output negative values of original array from negative array
	cout << "Negative elements: " << endl;
	print_array(neg, negCount);

	// Ouput non-negative values of original array from non-negative array.
	cout << "Non-negative elements: " << endl;
	print_array(nonneg, nonnegCount);


	delete []allInts; // free up memory allocated to array
	delete []neg;		// free up memory allocated to array
	delete []nonneg;	// free up memory allocated to array
	
	return 0;		// end program

}


/* Procedure count has no return value and is thus void.
   The procedure takes in a pointer to an array, a constant value
   for the number of elements of the array, and two integers by reference
   to count the number of negative and non-negative elements of the array.
   The procedure counts the number of negative integers and non-negative
   integers of the given array and given size.
*/
void count(int *array, const int n, int &negCount, int &nonnegCount) {
	// traverse array, add to negative or non-negative count
	for (int i = 0; i < n; i++) {
		if (array[i] < 0) {
			negCount++;
		} else {
			nonnegCount++;
		}
	}
}

/* Procedure split takes in 6 parameters and returns nothing. It takes in three pointers
   to three different arrays and the size of each of those arrays by constants. The procedure
   will traverse the first array and for every negative integer found, that value will be copied
   and put into the second array, while for every non-negative integer found in the first array
   that value will be copied and be put into the third array. The program will print an error if
   the number copied to the second array or third array does not equal the size of the second or third
   array, because that would mean the program as a whole failed to count the number of negative or non-
   negative integers stored in the original array.
*/
void split(int *array, const int n, int *neg, const int negCount, int *nonneg, const int nonnegCount) {
	int j(0); // for index of negative array / count of copied to negative array
	int k(0); // for index of non-negative array/ count of copied to non-negative array
	
	// traverse original array
	for (int i = 0; i < n; i++) {
		// if true copy to negative array and update index/count
		if (array[i] < 0) {
			neg[j] = array[i];
			j++;
			
		} else { // if false copy to non-negative array and update index/count
			nonneg[k] = array[i];
			k++;
		}
	}
	/* if array size for either negative array or non-negative array does not equal
           the amount copied to that array, then print out an error message and exit the program
	*/
	if (negCount != j) {
		cerr << "Error: Number of negative integers does not match array size: " << j << " != " << negCount << endl;
		exit(10);
	} else if (nonnegCount != k) {
		cerr << "Error: Number of non-negative integers does not match array size: " << k << " != " << nonnegCount << endl;
		exit(20);
	}
			
}

/* procedure print_array takes in a pointer to an array and the size of the array as a constant
   and has no return value. The procedure simply prints out the contents of the given array with
   each element of the array being separated by a space for aesthetic reasons.
*/
void print_array(int *array, const int n) {
	// traverse given array and print out contents
	for (int i = 0; i < n; i++) {
		cout << " " << array[i];
	}
	cout << endl; // new line
}


