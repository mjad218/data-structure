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

int binarrySearch(int value, int start, int end, vector<int> arr) {
	if (arr[start] == value) {
		return start;
	}
	if (start <= end) {
		int mid = (start + end) / 2;

		if (arr[mid] == value) {
			return mid;
		}
		if (arr[mid] > value) {
			return binarrySearch(value, start, mid - 1, arr);
		}
		if (arr[mid] < value) {
			return binarrySearch(value, mid + 1, end, arr);
		}
	}
	return -1;
}


int calculateFreq(int value, vector<int> arr) {
	int freq = 0;
	int index = binarrySearch(value, 0, arr.size(), arr); // logn
	if (index == -1) return freq;
	freq++;
	arr.erase(arr.begin() + index);
	return freq + calculateFreq(value, arr);
}
// A non optimized solution
// Time Complexity : nlogn + nlogn + nlogn = O(nlogn) 
// No Space Complexity
vector<int> missingNumbers(vector<int> arr, vector<int> brr) {
	sort(arr.begin(), arr.end()); // nlogn
	sort(brr.begin(), brr.end()); // nlogn
	vector<int> result; 
	for (int i = 0; i < (int)brr.size() - 1; i++) {
		int index = binarrySearch(brr[i], 0, arr.size(), arr); // logn

		if (index != -1 ) {
			int freq1 = calculateFreq(brr[i], brr);
			int freq2 = calculateFreq(arr[index], arr);
			if (freq1 != freq2) {
				result.push_back(brr[i]);
			}
		}
		else 
		result.push_back(brr[i]);
	}
	for (int i = 0; i < (int)result.size() - 1; i++) {
		if (result[i] == result[i + 1]) {
			result.erase( result.begin() + i );
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

	cout << calculateFreq( 4, arr);
	cout << endl;
	return 0;
}