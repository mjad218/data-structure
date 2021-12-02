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


vector<int> missingNumbers(vector<int> a, vector<int> b) {
    long long n = a.size(), m = b.size();
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    long long i = 0, j = 0;
    while (i < n && j < m) {
        if (a[i] == b[j]) {
            i++; j++;
            b[j - 1] = 0;
        }
        else if (a[i] > b[j])j++;
        else i++;
    }
    set<int> st;
    for (i = 0; i < m; i++) {
        if (b[i] != 0) st.insert(b[i]);
    }
    vector<int> v;
    v.assign(st.begin(), st.end());

    return v;

}
int main() {

    vector<int> arr = missingNumbers({ 11, 4, 11, 7 ,13, 4, 12,11 ,10, 14 }, { 11, 4, 11, 7, 3, 7 ,10, 13, 4, 8, 12, 11, 10, 14, 12 });

    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << '\t';
    }
    cout << endl;
    return 0;
}
