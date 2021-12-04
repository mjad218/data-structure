#include <iostream>
/*
Create a dynamic array of float numbers, the size of the array is determined by the user through
cin, each element in the array holds a value of 1/(index)! i.e a[i]=1.0/i!, run your program and
compute the sum of the array elements (which value the sum tends to ?)
*/

using namespace std;
float fact(int i) {
	if (i <= 2)
		return i; 

	return i * fact(i - 1);
}
int main() {

	cout << "Enter the size of the array : "; 
	int size; 
	cin >> size; 

	float * arr = new float[size];

	float sum = 0; 
	for (int i = 0; i < size; i++) {
		if (i == 0) {
			arr[i] = 1;
		}
		else {
			arr[i] = (float)1 / fact(i);
		}
		sum += arr[i];
	}
	cout << "The sum is  :" << sum << endl; 
	return 0;

}