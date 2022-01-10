#include <stdc++.h>
#include <string> 
#include <vector> 

using namespace std;
struct Node {
	int data;
	Node* left;
	Node* right;
};
vector<int> nodes;
void inOrderTraversal(Node* node) {
	if (node == NULL) {
		return;
	}
	inOrderTraversal(node->left);
	nodes.push_back(node->data);
	inOrderTraversal(node->right);
}
bool checkBST(Node* root) {
	inOrderTraversal(root);
	for (int i = 1; i < nodes.size(); i++) {
		if (nodes[i] <= nodes[i - 1]) {
			return false;
		}
	}
	return true;
}
int main()
{
	return 0;
}
