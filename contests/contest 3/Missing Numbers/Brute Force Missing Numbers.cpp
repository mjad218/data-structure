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

// A non optimized solution
// Time Complexity : nlogn + nlogn + nlogn = O(nlogn) 
// No Space Complexity
vector<int> missingNumbers(vector<int> arr, vector<int> brr) {
	sort(arr.begin(), arr.end()); // nlogn
	sort(brr.begin(), brr.end()); // nlogn
	for (int i = 0; i < (int)arr.size(); i++) {
		int index = binarrySearch( arr[i], 0 , brr.size(), brr); // logn
		if (index == -1) continue;
		int freq1 = 1, freq2 = 1, k = 1;

		while ( i + k < (int)arr.size() && arr.at(i + k) == arr.at(i)) {
			freq1++;
			k++;
		}
		k = -1; 
		while (i + k > 0 && arr.at(i + k) == arr.at(i)) {
			freq1++;
			k--;
		}
		k = 1;
		while (index + k < (int)brr.size() && brr.at(index + k) == brr.at(index))  {
			freq2++;
			k++;
		}
		k = -1;
		while (index + k > 0 && brr.at(index + k) == brr.at(index)) {
			freq2++;
			k--;
			index--;
		}
		if (freq1 == freq2) {
			i += freq1 - 1;
			while (freq1 >= 1) {
				brr.erase(brr.begin() + index); 
				freq1--;
			}
		}
		else {
			while (freq2 > 1) {
				brr.erase(brr.begin() + index);
				freq2--;
			}
		}
	}
	return brr;
}

int main() {

	vector<int> arr =  missingNumbers({ 11, 4, 11, 7 ,13, 4, 12,11 ,10, 14 }, { 11, 4, 11, 7, 3, 7 ,10, 13, 4, 8, 12, 11, 10, 14, 12});

	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i]<< '\t';
	}
	cout << endl;
	return 0; 
}