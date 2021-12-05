#include <iostream> 
#include <stdc++.h>
/*
We are given an array that contains N numbers. We want to determine if there are two numbers
whose sum equals a given number K. For instance, if the input is 8, 4, 1, 6, and K is 10, then the answer
is yes (4 and 6). A number may be used twice. Do the following:
a. Give an O(N2) algorithm to solve this problem.
b. Give an O(N logN) algorithm to solve this problem. (Hint: Sort the items first. After that is done, you
can solve the problem in linear time.)
c. Code both solutions and compare the running times of your algorithms.
*/

using namespace std; 

bool includesSum(int arr[], int size, int givenNum) {
	
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (arr[i] + arr[j] == givenNum) {
				return true; 
			}
		}
	}
	return false; 
}


// Great Resource : https://www.geeksforgeeks.org/given-an-array-a-and-a-number-x-check-for-pair-in-a-with-sum-as-x/ 

bool includesSum(int arr[], int size, int givenNum , bool useSort) {
	if (!useSort) return  includesSum(arr, size, givenNum);

	sort(arr , arr + size);
	int j = size - 1 , i = 0; 
	while (i < j) {
		if (arr[i] + arr[j] == givenNum) return true;
		else if (arr[i] + arr[j] > givenNum) j--;
		else i++;
	}
	return false;
}

int main() {

	int arr[] = {1 , 5, 8 ,10 , 8};
	int size = sizeof(arr) / sizeof(arr[0]); 
	cout << (includesSum(arr, size, 10, true) ? "yes, it does" : "no, it does not"); 

	return 0; 
}