#include <stdc++.h>
#include <string> 
#include <vector> 

using namespace std;

bool isMatching(char& parenthesis, stack<char>& parentheses) {
	if(parenthesis == ')') {
		return parentheses.top() == '(' ? true : false;
	}
	if (parenthesis == '}') {
		return parentheses.top() == '{' ? true : false; 
	}
	if (parenthesis == ']') {
		return parentheses.top() == '[' ? true : false;
	}
	return false;
}

string isBalanced(string s) {
	// first i have a string of parentheses
	// second i need to check if they are balanced or not
	// what i have is the array of characters or a string 
	// i can just loop through the string and push every character to a stack
	// when i push a new character i should check the top of the stack is they are matched pop the top of the stack
	// when the loop ends check if the stack is not empty => they are not balanced
	stack<char> parentheses;
	for (char c : s) {
		if (!parentheses.empty()) {
			if (isMatching(c, parentheses)) {
				parentheses.pop();
			} else {
				parentheses.push(c);
			}
		}
		else {
			parentheses.push(c);
		}
	}
	return parentheses.empty() ? "YES" : "NO"; 
}

int main()
{
	cout << isBalanced("{[()]}");
	return 0;
}
