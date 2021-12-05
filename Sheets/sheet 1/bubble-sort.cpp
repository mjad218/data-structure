#include <iostream> 
using namespace std;
/*
Sort an array using bubble sort where you compare each two consecutive numbers and swap
them if they are not in an ascending order. You may run your operations in a number of paths
equal to the array size or if all array elements are in ascending order stop!
*/

void bubbleSort(int arr[] , int size) {
	// O(n2) quadratic time
	for (int i = 0; i < size; i++ ) {
		bool isSorted = false;
		if (isSorted) break; 
		for (int j = i + 1; j < size; j++) {
			if (arr[i] > arr[j]) {
				int temp = arr[i]; 
				arr[i] = arr[j]; 
				arr[j] = temp;
			}
			else {
				isSorted = true; 
			}
		}
	}
}
int main() {
	int arr[] = {1 , 4 , 3 , 2  ,5 , 8 , 6 , 7 , 2 , 0 , 1}; 
	int size = sizeof(arr) / sizeof(arr[0]);
	bubbleSort(arr, size);
	for (int i = 0; i < size; i++) {
		cout << arr[i] << endl; 
	}
	return 0;
 }