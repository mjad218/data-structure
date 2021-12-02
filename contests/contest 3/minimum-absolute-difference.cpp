#include <iostream>
#include <vector>
#include <stdc++.h>
using namespace std;


int minimumAbsoluteDifference(vector<int> arr) {
	sort(arr.begin(), arr.end()); 

	int min = abs(arr[0] - arr[1]);
	for (int i = 0; i < (int)arr.size()  - 1; i++) {
		int diff = abs(arr[i] - arr[i + 1]); 
		if (min > diff ) {
			min = diff;
		}

	}
	return min; 
}

int main() {

	cout << minimumAbsoluteDifference({1 ,2 ,2 ,3 ,8 , 91});
	return 0;
}