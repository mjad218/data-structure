#include <iostream> 

using namespace std; 
/*
* Create a C/C++ function that takes an array of integers and returns whether it has repeated items
* or not. Determine the big O of your solution.
* Repeat if the array is sorted.
*/

bool hasRepeatedItems(int arr[], int size, bool sorted = false) {
	// if sorted O(n) 
	if (sorted) {
		for (int i = 0; i < size; i++) {
			if (arr[i] == arr[i + 1]) {
				return true;
			}
		}
		return false; 
	}

	// if not sorted O(n2) Quadratic time 
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (arr[i] == arr[j] && i != j) {
				return true;
			}
		}
	}
	return false; 
} 

int main() {

	int arr[] = { 1 , 2  , 3 , 4 }; 
	int size = sizeof(arr) / sizeof(arr[0]);
	cout << (hasRepeatedItems(arr, size, true) ? "yep, it has repeated items" : "no, it does not");
}