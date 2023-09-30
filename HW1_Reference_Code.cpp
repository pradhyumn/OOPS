//HW1 by ***********

#include <iostream>
using namespace std;

class Node {
public:
	int value;
	Node* next;
	Node* previous;
	Node(int i) { value = i; next = previous = nullptr; }
	Node() { next = previous = nullptr; }//default constructor
};

class DoublyLinkedList {
public:
	Node* head;
	Node* tail;
	DoublyLinkedList() { head = tail = nullptr; }
	void makeList(int n, int m);//create an n-node linked list with random values in 0 ... m-1
	void print_F();
	void print_B();
	void bubbleSort();
	//2 3 1 6 8 5 9 6 2 5 7 7 4 2 becomes
	//1 2 2 2 3 4 5 5 6 6 7 7 8 9 

	//In case multiple nodes have the same min value, the
	//first of them will be swapped with the node pointed by head.
	//In case multiple nodes have the same max value, the
	//last of them will be swapped with the node pointed by tail.
	//For example,    6 5 3 7 3 7 5 4 will become 3 5 6 7 3 4 5 7





	//You only can modify next and previous of nodes, but not value of nodes.
	//You are required to directly work on the linked list.

	//You are not allowed to use any external structures such as arrays
	// to perform operations and copy the results back to the linked list.

	//You are not allowed to create additional functions.
	//You can use while loop, but not for loop.



	void minMax();//swap the node of min value with the first node; 
	//swap the node of max value with the last node

	// 14 5 6 2 17 9 8
	// 2 5 6 14 8 9 17

	//In case multiple nodes have the same min value, the
	//first of them will be swapped with the node pointed by head.
	//In case multiple nodes have the same max value, the
	//last of them will be swapped with the node pointed by tail.
	//For example,    6 5 3 7 3 7 5 4 will become 3 5 6 7 3 4 5 7

	//Similar constraints apply as repeatedly stated below.
	//You only can modify next and previous of nodes, but not value of nodes.
	//You are required to directly work on the linked list.

	//You are not allowed to use any external structures such as arrays
	// to perform operations and copy the results back to the linked list.

	//You are not allowed to create additional functions.
	//You can use while loop, but not for loop.


};


void DoublyLinkedList::minMax() {

	//Your code
	if (!tail || !(tail->previous)) return; // 0 or 1 node
	int min{ head->value };
	Node* minNode{ head };
	Node* curs{ head };
	while (curs) {
		if (curs->value < min) {
			min = curs->value;
			minNode = curs;
		}
		curs = curs->next;
	}
	if (minNode != head) {
		Node* p;
		if (head->next == minNode) {//if the minNode is next to the head
			p = head;
			head->next = minNode->next;
			head->previous = minNode;
			minNode->previous = nullptr;
		}
		else {
			minNode->previous->next = head;
			head->next->previous = minNode;
			p = head->next;
			head->next = minNode->next;
			head->previous = minNode->previous;
			minNode->previous = nullptr;

		}

		if (minNode != tail) {//if the minNode is not the tail
			minNode->next->previous = head;
			minNode->next = p;
		}
		else {
			minNode->next = p;
			tail = head;
		}

		head = minNode;
	}

	int max{ tail->value };
	Node* maxNode{ tail };
	curs = tail;
	while (curs->previous) {
		if (curs->value > max) {
			max = curs->value;
			maxNode = curs;
		}
		curs = curs->previous;
	}

	if (maxNode != tail) {
		Node* p;
		if (tail->previous == maxNode) {
			p = tail;
			tail->previous = maxNode->previous;
			tail->next = maxNode;
			maxNode->next = nullptr;
		}
		else {
			maxNode->next->previous = tail;
			tail->previous->next = maxNode;
			p = tail->previous;
			tail->previous = maxNode->previous;
			tail->next = maxNode->next;
			maxNode->next = nullptr;

		}
		maxNode->previous->next = tail;
		maxNode->previous = p;
		tail = maxNode;
	}

}

void DoublyLinkedList::bubbleSort() {

	//Your code
	if (!tail || !(tail->previous)) return; // 0 or 1 node
	Node* p2{ head }; 
	while (p2 != tail) {
		Node* p1{ tail };
		while (p1 != p2) {
			Node* p3{ p1->previous };
			if (p1->value < p3->value) {

				p1->previous = p3->previous;
				p3->next = p1->next;
				p3->previous = p1;
				p1->next = p3;

				if (p1 == tail && p3 == head) {
					tail = p3;
					head = p1;
				}
				else if (p1 == tail && p3 != head) {
					p1->previous->next = p1;
					tail = p3;
				}
				else if (p1 != tail && p3 == head) {
					p3->next->previous = p3;
					head = p1;
				}
				else {
					p3->next->previous = p3;
					p1->previous->next = p1;
				}

				if (p3 == p2) {
					p2 = p1;
				}
			}
			else {
				p1 = p3;
			}
		}
		p2 = p2->next;
	}

}


void DoublyLinkedList::makeList(int n, int m) {
	for (int i = 0; i < n; ++i) {
		Node* p1{ new Node{rand() % m} };
		if (!head) { head = tail = p1; }//currently empty linked list
		else {
			tail->next = p1;
			p1->previous = tail;
			tail = p1;
		}
	}
}
void DoublyLinkedList::print_F() {
	Node* p1{ head };
	while (p1) {
		cout << p1->value << " ";
		p1 = p1->next;
	}
	cout << endl;
}
void DoublyLinkedList::print_B() {
	Node* p1{ tail };
	while (p1) {
		cout << p1->value << " ";
		p1 = p1->previous;
	}
	cout << endl;
}

int main() {
	DoublyLinkedList L1;
	L1.makeList(19, 15);
	L1.print_F();
	L1.print_B();
	L1.minMax();
	L1.print_F();
	L1.print_B();

	DoublyLinkedList L2;
	L2.makeList(25, 30);
	L2.bubbleSort();
	L2.print_F();
	L2.print_B();
	return 0;
}