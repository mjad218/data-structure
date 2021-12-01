#include <stdc++.h>
#include <string> 
#include <vector> 

using namespace std;

string ltrim(const string&);
string rtrim(const string&);
vector<string> split(const string&);

int runningTime(vector<int> arr) {
    int shifts = 0;
    for (int i = 0; i < arr.size(); i++) {
        for (int j = i; j >= 0; j--) {
            if (j >= 1 && arr[j] < arr[j-1]) {
                int temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
                shifts++;
            }
        }
    }
    return shifts;
}

int main()
{
    
    cout << runningTime({ 2, 1, 3, 1, 2 });
}
