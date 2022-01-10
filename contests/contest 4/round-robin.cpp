#include <stdc++.h>
#include <string> 
#include <vector> 

using namespace std;

int main()
{
	int noOfProcesses = 0, cpuTime = 0; 
	cin >> noOfProcesses >> cpuTime;
	vector<string> orderOfProcesses;
	vector<string> processes;
	vector<int> processesTime;

	for (int i = 0; i < noOfProcesses; i++) {
		string process; 
		int processTime; 
		cin >> process >> processTime; 
		processes.push_back(process);
		orderOfProcesses.push_back(process);
		processTime - cpuTime > 0 ?
			processesTime.push_back(processTime - cpuTime) :
			processesTime.push_back(0);
	}
	unsigned int isDone = 1;
	while (isDone < noOfProcesses) {
		isDone = 1;
		for (unsigned int i = 0; noOfProcesses; i++) {
			if (processesTime[i] == 0) {
				isDone++;
				continue;
			}
			if (processesTime[i] < cpuTime) {
				orderOfProcesses.push_back(processes[i]);
				continue;
			}
			if (processesTime[i] >= cpuTime) {
				orderOfProcesses.push_back(processes[i]);
				processesTime[i] = processesTime[i] - cpuTime;
				continue;
			}
		}
	}
	string str; 
	for (unsigned int i = 0; i < orderOfProcesses.size(); i++) {
		str += orderOfProcesses[i];
	}
	cout << str;
	return 0;
}
