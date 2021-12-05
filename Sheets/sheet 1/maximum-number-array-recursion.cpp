#include <iostream> 

/*
Write a program that recursively finds the maximum value of an array of integers.
*/
using namespace std; 

// returns the index of the maximum number
int findMax(int arr[] , int start , int end) {
	int maxIndex = 0;
	int max = arr[0];

	if (arr[start] > max) {
		max = arr[start];
		maxIndex = start; 
	}
	if (start == end) {
		return maxIndex;
	}
	int index = findMax(arr, start + 1, end); 
	maxIndex = max > arr[index] ? maxIndex : index;

}
int main() {
	int arr[] = { 1 , 2 , 10 , 15 , 5 , 6 };
	cout << arr[findMax(arr, 0, 5)];
}