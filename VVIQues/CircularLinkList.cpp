// C++ code to find the luckiest person
#include <iostream>
using namespace std;

// Node structure
struct Node {
	int data;
	struct Node* next;
};

Node *newNode(int data)
{
Node *node = new Node;
node->data = data;
node->next = NULL;
return node;
}

// Function to find the luckiest person
int alivesol(int Num)
{
	if (Num == 1)
		return 1;

	// Create a single node circular
	// linked list.
	Node *last = newNode(1);
	last->next = last;
	
	for (int i = 2; i <= Num; i++) {
		Node *temp = newNode(i);
		temp->next = last->next;	 
		last->next = temp;
		last = temp;	 
	}

	// Starting from first soldier.
	Node *curr = last->next;

	// condition for evaluating the existence
	// of single soldier who is not killed.
	Node *temp;
	while (curr->next != curr) {
		temp = curr;
		curr = curr->next;
		temp->next = curr->next;

		// deleting soldier from the circular
		// list who is killed in the fight.
		delete curr;
		temp = temp->next;
		curr = temp;
	}

	// Returning the Luckiest soldier who
	// remains alive.
	int res = temp->data;
	delete temp;
	
	return res;
}

// Driver code
int main()
{
	int N = 15;
	cout << alivesol(N) << endl;
	return 0;
}
