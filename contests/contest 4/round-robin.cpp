#include <stdc++.h>
#include <string> 

using namespace std;

int main()
{
	int noOfProcesses, cpuTime, i, processTime;
	string str = "";
	char process;
	cin >> noOfProcesses >> cpuTime;
	queue<char> processes;
	queue<int> time;
	for (i = 0; i < noOfProcesses; i++) {
		cin >> process >> processTime;
		str += process;
		processTime -= cpuTime;
		if (processTime > 0) {
			processes.push(process);
			time.push(processTime);
		}
	}
	while (!processes.empty()) {
		str += processes.front();
		processTime = time.front() - cpuTime;
		if (processTime > 0) {
			processes.push(processes.front());
			time.push(processTime);
		}
		processes.pop();
		time.pop();
	}
	cout << str;
	return 0;
}
