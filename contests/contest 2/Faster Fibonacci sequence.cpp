#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long fibonacci(int n) {
        long long fib[n+2]; 
        fib[0] = 0;
        fib[1] = 1;
        for(int i=2; i<=n; i++)
        {
            fib[i] = fib[i-1]+fib[i-2];
        }
        return fib[n];
    }
};

int main() {
    Solution sln; 
    int n;
  	cin>>n;
  	cout<<sln.fibonacci(n)<<endl;
    return 0;
}