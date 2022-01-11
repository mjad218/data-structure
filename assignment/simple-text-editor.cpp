#include <iostream> 
#include <stack>
using namespace std;

class TextEditor {
	string str;
	stack<string> edits; 
		//- Append(W) : append string W to the end of S.
		//- Delete(k) : delete the last k characters of S.
		//- Print(k) : print the kth character of S.
		//- Undo() : Undo the last(no
public :
	void append(string w) {
		str += w;
		edits.push(str);
	}
	void deleteFromStr(int k) {
		string newStr; 
		for (int i = 0; i < str.length() - k; i++) {
			newStr += str[i];
		}
		str = newStr; 
		edits.push(str);
	}

	void print(int k){
		if (k > str.length()) k = str.length();
		for (int i = 0; i < k; i++) {
			cout << str[i];
		}
	}
	void undo(){
		edits.pop();
		str = edits.top();
	}
};
int main() {

	TextEditor simpleEditor; 

	simpleEditor.append("I am"); 
	simpleEditor.print(2);
	simpleEditor.print(4);
	simpleEditor.deleteFromStr(1);
	simpleEditor.print(4);
	simpleEditor.undo();
	simpleEditor.print(4);



	return 0;
}