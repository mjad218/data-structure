#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string reverse_string(string s, int n)
{
    static string reversedStr = "";
    int size = n;
    if (size > 1) {
        size--;
        reversedStr += s.at(size);
        reverse_string(s.substr(0, size), size);
    }
    else if (size == 1) {
        reversedStr += s.at(0);
        return reversedStr;
    }
    return reversedStr;

}

int main() {
    string s;
    cin >> s;
    cout << reverse_string(s, s.length()) << endl;
    return 0;
}