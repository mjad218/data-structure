#include <iostream>
#include <vector>
#include <stdc++.h>
using namespace std;
/*
 * Complete the 'missingNumbers' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY arr
 *  2. INTEGER_ARRAY brr
 */

vector<int> missingNumbers(vector<int> arr, vector<int> brr) {
	sort(arr.begin(), arr.end()); // nlogn
	sort(brr.begin(), brr.end()); // nlogn
	vector<int> result;
	int freq[100];
	for (int i = 0; i < 100; i++) {
		freq[i] = 0;
	}
	for (int i = 0; i < brr.size(); i++) {
		freq[brr[i] - brr[0]] += +1; 
	}
	for (int i = 0; i < arr.size(); i++) {
		freq[arr[i] - brr[0]] += -1;
	}

	for (int i = 0; i < 100; i++) {
		if (freq[i] != 0) {
			result.push_back(i + brr[0]);
		}
	}
	return result;
}


int main() {

	vector<int> arr = missingNumbers({ 11, 4, 11, 7 ,13, 4, 12,11 ,10, 14 }, { 11, 4, 11, 7, 3, 7 ,10, 13, 4, 8, 12, 11, 10, 14, 12 });

	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << '\t';
	}
	cout << endl;

	return 0;
}