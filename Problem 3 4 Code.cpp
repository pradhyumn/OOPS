
#include <iostream>
using namespace std;

class Node {
public:
	int* pValue;
	Node* next;
	Node* previous;
	Node(int i) { pValue = new int{ i }; next = previous = nullptr; }
	Node() { pValue = nullptr; next = previous = nullptr; }//default constructor
};

class DLL {//DLL stands for DoublyLinkedList
public:
	Node* head;
	Node* tail;
	DLL() { head = tail = nullptr; }
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





	DLL(const DLL& L);//copy constructor
	
	DLL operator=(const DLL& L);//copy assignment
	~DLL();//destructor
	DLL(const initializer_list<int>& I);//initializer_list
	DLL(DLL&& L);//move constructor
	DLL operator=(DLL&& L);//move assignment
	DLL ThreeTimes();//ThreeTimes

	void reverse();
	void removeAll(int k);//remove all node with *pValue = k




};

void DLL::removeAll(int k) {
	if (!head) return;
	Node* p1{ head };
	while (p1) {
		Node* p2 = p1->next;
		if (*(p1->pValue) == k) {
			if (p1->next) {
				p1->next->previous = p1->previous;
			}
			if (p1->previous) {
				p1->previous->next = p1->next;
			}
			if (p1 == head) head = p1->next;
			if (p1 == tail) tail = p1->previous;
			delete p1->pValue;
			delete p1;
		}
		p1 = p2;
	}

}

void DLL::reverse() {
	if (!head || !head->next) return;
	Node* p1{ head };
	while (p1) {
		Node* p2{ p1->next };
		swap(p1->next, p1->previous);
		p1 = p2;
	}
	swap(head, tail);
}


DLL DLL::ThreeTimes() {
	DLL temp{ *this };
	Node* p1{ head };
	while (p1) {
		*(p1->pValue) *= 3;
		p1 = p1->next;
	}
	return temp;
}
DLL DLL::operator=(DLL&& L) {
	if (this == &L) { cout << "No operations" << endl; return *this; }
	while (head) {
		Node* p1{ head->next };
		delete head->pValue;
		delete head;
		head = p1;
	}
	head = L.head;
	tail = L.tail;
	L.head = L.tail = nullptr;
	return *this;
}

DLL::DLL(DLL&& L) {//move constructor
	head = L.head;
	tail = L.tail;
	L.head = L.tail = nullptr;
}

DLL::DLL(const initializer_list<int>& I) {//initializer_list
	head = tail = nullptr;
	auto it{ I.begin() };
	while (it != I.end()) {
		Node* p1{ new Node(*it) };
		if (!head) head = tail = p1;
		else {
			tail->next = p1;
			p1->previous = tail;
			tail = p1;
		}
		++it;
	}
}


DLL::~DLL() {
	while (head) {
		Node* p1{ head->next };
		delete head->pValue;
		delete head;
		head = p1;
	}
}

DLL::DLL(const DLL& L) {//copy constructor
	head = tail = nullptr;
	Node* p1{ L.head };
	while (p1) {
		Node* p2{ new Node(*(p1->pValue)) };
		if (!head) { head = tail = p2; }
		else {
			tail->next = p2;
			p2->previous = tail;
			tail = p2;
		}
		p1 = p1->next;
	}
}

DLL DLL::operator=(const DLL& L) {//copy assignment
	if (this == &L) { cout << "No need to copy" << endl;  return *this; }
	while (head) {
		Node* p1{ head->next };
		delete head->pValue;
		delete head;
		head = p1;
	}
	Node* p1{ L.head };
	while (p1) {
		Node* p2{ new Node(*(p1->pValue)) };
		if (!head) head = tail = p2;
		else {
			tail->next = p2;
			p2->previous = tail;
			tail = p2;
		}
		p1 = p1->next;
	}
	return *this;

	//Your code

}


void DLL::makeList(int n, int m) {
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
void DLL::print_F() {
	Node* p1{ head };
	while (p1) {
		cout << *(p1->pValue) << " ";
		p1 = p1->next;
	}
	cout << endl;
}
void DLL::print_B() {
	Node* p1{ tail };
	while (p1) {
		cout << *(p1->pValue) << " ";
		p1 = p1->previous;
	}
	cout << endl;
}

ostream& operator<<(ostream& str, const DLL& L) {

	str << "{ ";
	Node* p1{ L.head };
	while (p1) {
		str << *(p1->pValue) << " ";
		p1 = p1->next;
	}
	str << "}";
	return str;
}

ostream& operator<<(ostream& str, const DLL&& L) {

	str << "{ ";
	Node* p1{ L.tail };
	while (p1) {
		str << *(p1->pValue) << " ";
		p1 = p1->previous;
	}
	str << "}";
	return str;
}


int main() {
	DLL L1{ 9,5,6,4,8,3,1,2,7 };
	//DLL L1;
	//L1.makeList(19, 15);
	cout << L1 << endl;
	cout << move(L1) << endl;

	DLL L2;
	L2 = L1;
	cout << L2 << endl;
	cout << move(L2) << endl;

	L2 = L1.ThreeTimes();
	cout << L2 << endl;
	cout << move(L2) << endl;

	L2.reverse();
	cout << L2 << endl;
	cout << move(L2) << endl;


	DLL L3;
	L3.makeList(19, 10);
	cout << L3 << endl;
	cout << move(L3) << endl;
	L3.removeAll(1);
	cout << L3 << endl;
	cout << move(L3) << endl;

	L3.removeAll(7);
	cout << L3 << endl;
	cout << move(L3) << endl;


	L3 = L3;
	cout << L3 << endl;

	L3 = move(L3);
	cout << L3 << endl;


	/*DoublyLinkedList L1;
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
	L2.print_B();*/
	return 0;
}