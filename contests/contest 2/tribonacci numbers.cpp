#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int tribonacci(int n)
{

    int result = 0 ; 
    if ( n > 2) {
        result += tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);
    }
    else if ( n == 2 || n == 1)  {
        return 1; 
    }
    else if(n == 0) {
        return 0; 
    }
    return result;

}

int main() {
    int n;
    cin >> n;
    cout << tribonacci(n);
    return 0;
}