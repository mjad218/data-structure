#include <stdc++.h>
#include <string> 
#include <vector> 

using namespace std;
struct Node {
	int data;
	Node* left;
	Node* right;
};

bool checkBST(Node* root) {
	// i try solving this problem using recursion
	// first i will check if the root node has children or not
	// second check if the right node is greater than the parent
	// check if the left is less than the root
	// has childs invoke a recursive call twice to the function with the left and right nodes
	if (root == NULL)
		return true;
	if (root->left != NULL && root->right != NULL) {
		if (root->right->data <= root->data) {
			return false;
		}
		if (root->left->data >= root->data) {
			return false;
		}
		if (root->left->data == root->right->data) {
			return false;
		}
		return (checkBST(root->left) && checkBST(root->right) );
	}	
	if (root->right != NULL) {
		if (root->right->data <= root->data) {
			return false;
		}
		return checkBST(root->right);
	}
	if (root->left != NULL) {
		if (root->left->data >= root->data) {
			return false;
		}
		return checkBST(root->left);
	}
	return true;
}

int main()
{
	return 0;
}
