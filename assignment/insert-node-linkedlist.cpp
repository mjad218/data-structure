#include <iostream> 

using namespace std;
struct Link {
	int data;
	Link* next;
};
class LinkedList2 {
	Link* head;
	Link* tail;
public:
	LinkedList2() : head(NULL), tail(NULL)
	{
	}
	Link* insert(Link * node, int pos) {
		// running time O(pos)
		if (head == NULL) {
			return node; 
		}
		Link* current = head;

		for (int i = 0; i < pos - 1; i++) {
			current = current->next; 
		}
		Link* temp = current->next; 
		current->next = node; 
		node->next = temp; 
		return head;
	}
	void add(int item) {
		Link* link = new Link;
		link->data = item;

		if (head == NULL && tail == NULL) {
			link->next = head; // = NULL
			head = link;
		}
		else {
			tail->next = link;
			link->next = NULL;
		}
		tail = link;
	}

	void display() {
		Link* current = head;
		while (1) {
			cout << current->data << endl;
			if (current->next == NULL)
				break;

			current = current->next;
		}
	}
};

int main() {

	// linklist 2
	cout << "Link list 2" << endl;
	LinkedList2 linkedList2;

	linkedList2.add(10);
	linkedList2.add(5);
	linkedList2.add(6);
	linkedList2.add(7);
	linkedList2.add(5);
	linkedList2.add(547);
	Link* node = new Link;
	node->data = 99999;
	linkedList2.insert(node, 1);
	linkedList2.display();

	return 0;
}