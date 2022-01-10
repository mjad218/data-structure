#include <stdc++.h>
#include <string> 
#include <vector> 

using namespace std;
class Node {
public:
	int data;
	Node* left;
	Node* right;
	Node(int d) {
		data = d;
		left = NULL;
		right = NULL;
	}
};

Node* insert(Node* root, int data) {

    if (!root)
    {
        return new Node(data);
    }

    if (data > root->data)
    {
        root->right = insert(root->right, data);
    }
    else
    {
        root->left = insert(root->left, data);
    }
	return root;
}
int main()
{
	return 0;
}
