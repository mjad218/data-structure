#include <iostream> 
#include <stack>
using namespace std;
// Enqueue(x) : add a new element to the end of the queue.
// Dequeue() : remove the element from the front of the queue and return it.
// getFront() : Print the element at the front of the queue.
class MyQueue {
	stack<string> s1;
	stack<string> s2;
public:
	void enqueue(string s) {
		s1.push(s);
	}
	void dequeue() {
		while (!s1.empty()) {
			s2.push(s1.top());
			s1.pop();
		}
		s2.pop();
		while (!s2.empty()) {
			s1.push(s2.top());
			s2.pop();
		}
	}

	string getFront() {
		while (!s1.empty()) {
			s2.push(s1.top());
			s1.pop();
		}
		string str = s2.top(); 
		while (!s2.empty()) {
			s1.push(s2.top());
			s2.pop();
		}
		return str;
	}
};
int main() {

	return 0;
}