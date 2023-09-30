
//HW3 by XXXXXXXX


//HW3 Due: 11:59, Friday, Oct. 8
//Note that I removed the member functions print_inO, print_preO, and print_postO for tree class.
//You need to overload operator<< to allow cout for a tree, in which you will implement in-order traversal.
//In additon you need to overload *= for tree and linkedList (see the included main function).


#include <iostream>
using namespace std;

template <class T> class ThreeD {
public:
	T ht;
	T wid;
	T dep;
	ThreeD(T i, T j, T k) :ht(2 * i), wid(2 * j), dep(2 * k) {};
	ThreeD() { ht = wid = dep = 0; }
	void operator*=(int k);
};


template <class T> void ThreeD<T>::operator*=(int k) {
	this->ht *= k;
	this->wid *= k;
	this->dep *= k;
	//return *this;
}


template <class T> ostream& operator<<(ostream& str, const ThreeD<T>& t1) {
	str << "(" << t1.ht << ", " << t1.wid << ", " << t1.dep << ")";
	return str;
}


/*implement for the following class LInkedList , constructor, copy constructor, initializer_list, copy assighment,
destructor, move constructor, move assignment, ThreeTimes.  in addition, you need to overload operator<< for tree class.
For all of them, print a statement such as "copy Assignment LL" */

template <class T> class node {
public:
	T value;
	node* next;
	node(T i) : value(i), next(nullptr) {}
	node() : next(nullptr) {}
};



template <class T> class Node {
public:
	T value;
	Node<T>* l_child, * r_child;
	Node(T i) : value{ i }, l_child{ nullptr }, r_child{ nullptr }{};
	Node() {  }
};


template<class T> class LinkedList {
public:
	node<T>* head;
	LinkedList() : head(nullptr) {} // constructor

	LinkedList(const LinkedList<T>& L); // copy constructor
	LinkedList(const initializer_list<T>& I); // initializer list
	LinkedList<T> operator=(const LinkedList<T>& L); // copy assignment
	~LinkedList(); // destructor ??? remove <T>
	LinkedList(LinkedList<T>&& L); // move constructor
	LinkedList<T> operator=(LinkedList<T>&& L); // move assignment
	LinkedList<T> ThreeTimes();

	void operator*=(int k); // overload operator *=
};

template<class T> ostream& operator<<(ostream& str, const LinkedList<T>& L) {
	str << "{ ";
	node<T>* p1 = L.head;
	while (p1) {
		str << p1->value << " ";
		p1 = p1->next;
	}
	str << "}";
	return str;
}


template<class T> LinkedList<T>::LinkedList(const LinkedList<T>& L) :LinkedList() {
	node<T>* p1 = L.head;
	while (p1 != nullptr) {
		node<T>* p2 = new node<T>();
		p2->next = head;
		head = p2;
		p1 = p1->next; // node* p3 = p1->next; p1 = p3;
	}
	p1 = L.head;
	node<T>* p2 = head;
	while (p1 != nullptr) {
		p2->value = p1->value;
		p1 = p1->next;
		p2 = p2->next;
	}
	cout << "Copy Constructor LL" << endl;
}



template<class T> LinkedList<T>::LinkedList(const initializer_list<T>& I) {
	head = nullptr;
	auto it = I.end() - 1;
	while (it != I.begin() - 1) {
		node<T>* p = new node<T>(*it);
		p->next = head;
		head = p;
		--it;
	}
	cout << "Initializer List LL" << endl;
}


template<class T> LinkedList<T> LinkedList<T>::operator=(const LinkedList<T>& L) {
	// delete current one
	while (head) {
		node<T>* p1 = head->next;
		delete head;
		head = p1;
	}

	// build new one with same length
	node<T>* p1 = L.head;
	while (p1 != nullptr) {
		node<T>* p2 = new node<T>();
		p2->next = head;
		head = p2;
		p1 = p1->next;
	}
	// copy values to new one
	p1 = L.head;
	node<T>* p2 = head;
	while (p1 != nullptr) {
		p2->value = p1->value;
		p1 = p1->next;
		p2 = p2->next;
	}
	cout << "Copy Assignment LL" << endl;
	return *this;
}


template<class T> LinkedList<T>::~LinkedList() {
	while (head != nullptr) {
		node<T>* p1 = head->next;
		delete head;
		head = p1;
	}
	cout << "Destructor LL" << endl;
}


template<class T> LinkedList<T>::LinkedList(LinkedList<T>&& L) {
	head = L.head;
	L.head = nullptr;
	cout << "Move Constructor LL" << endl;
}


template<class T>LinkedList<T> LinkedList<T>::operator=(LinkedList<T>&& L) {
	// delete current one
	while (head) {
		node<T>* p1 = head->next;
		delete head;
		head = p1;
	}

	head = L.head;
	L.head = nullptr;

	cout << "Move Assignment LL" << endl;
	return *this;
}


template<class T> LinkedList<T> LinkedList<T>::ThreeTimes() {
	LinkedList<T> temp = *this;
	node<T>* p1 = temp.head;
	while (p1 != nullptr) {
		p1->value *= 3;
		p1 = p1->next;
	}
	cout << "ThreeTimes LL" << endl;
	return temp;
}


template <class T> void LinkedList<T>::operator*=(int k) {
	node<T>* p1 = head;
	while (p1) {
		p1->value *= k;
		p1 = p1->next;
	}
	//return *this;
}


/*implement for the fo llowing class tree, constructor, copy constructor, initializer_list, copy assignment,
destructor, move constructor, move assignment, ThreeTimes, print_inO, print_preO, print_postO.  in addition, you need to overload operator<< for tree class.
For all of them, print a statement such as "copy Assignment tree" .   You might need to overload additional things for handling ThreeTimes..
*/
template <class T> class tree {
public:
	Node<T>* root;
	tree(int k) { }//constructor; k is level
	tree() : root{ nullptr } {}
	//function help_c for constructor

	tree(const initializer_list<T>& I);//initializer_list
	//help_il
	Node<T>* help_il(const initializer_list<T>& I, Node<T>* root_temp, int i, int len);

	tree(const tree<T>& T1);//copy constructor
	//help_cc
	Node<T>* help_cc(Node<T>* old_root, Node<T>* new_root);

	tree operator=(const tree<T>& T1); // Copy Assignment

	~tree(); // destructor
	void help_d(Node<T>* root);

	tree ThreeTimes();
	Node<T>* help_tt(Node<T>* root);

	tree(tree<T>&& T1);//Move Constructor
	tree operator=(tree<T>&& T1);//Move Assignment

	void operator*=(int i); // overload *=
	Node<T>* help_muti(Node<T>* root, int i);

};


template <class T> void tree<T>::operator*=(int i) {
	root = help_muti(root, i);
	//return *this;
}


template<class T> Node<T>* tree<T>::help_muti(Node<T>* root, int i) {
	if (root != nullptr) {
		root->value *= i;
		help_muti(root->l_child, i);
		help_muti(root->r_child, i);
	}
	return root;
}



template<class T> tree<T>::tree(const initializer_list<T>& I) {
	int i = 0;
	int len = I.size();
	root = help_il(I, root, i, len);
	//cout << endl;
	cout << "Initializer List tree" << endl;
}


template<class T> Node<T>* tree<T>::help_il(const initializer_list<T>& I, Node<T>* root_temp, int i, int len) {
	if (i < len) {
		auto it = I.begin();

		root_temp = new Node<T>();
		root_temp->value = *next(it, i);

		// left
		root_temp->l_child = help_il(I, root_temp->l_child, 2 * i + 1, len);
		// right
		root_temp->r_child = help_il(I, root_temp->r_child, 2 * i + 2, len);
	}
	return root_temp;
}



template<class T> tree<T> ::tree(const tree<T>& T1) :tree() {
	root = help_cc(T1.root, root);
	cout << "Copy Constructor tree" << endl;
}


template<class T> Node<T>* tree<T>::help_cc(Node<T>* old_root, Node<T>* new_root) {
	if (old_root != nullptr) {
		new_root = new Node<T>();
		new_root->value = old_root->value;

		new_root->l_child = help_cc(old_root->l_child, new_root->l_child);
		new_root->r_child = help_cc(old_root->r_child, new_root->r_child);
	}
	return new_root;
}


template<class T> tree<T> tree <T>::operator=(const tree<T>& T1) {

	help_d(root);
	tree<int> temp{ T1 };
	root = temp.root;
	temp.root = nullptr;

	cout << "Copy Assignment tree" << endl;
	return *this;
}


template<class T> tree <T>::~tree() {
	help_d(root);
	cout << "Destructor tree" << endl;
}


template<class T> void tree<T>::help_d(Node<T>* root) {
	if (root != nullptr) {
		help_d(root->l_child);
		help_d(root->r_child);
		delete root;
	}
}


template<class T> tree<T> tree <T>::ThreeTimes() {
	tree<T> temp{ *this };

	temp.root = help_tt(temp.root);
	cout << "ThreeTimes tree" << endl;
	return temp;
}


template<class T> Node<T>* tree <T>::help_tt(Node<T>* root) {
	if (root != nullptr) {
		help_tt(root->l_child);
		help_tt(root->r_child);
		root->value *= 3;
	}
	return root;
}


template<class T> tree<T>::tree(tree<T>&& T1) {
	root = T1.root;
	T1.root = nullptr;
	cout << "Move Constructor tree" << endl;
}


template<class T> tree<T> tree<T>::operator=(tree<T>&& T1) {
	help_d(root);
	root = T1.root;
	T1.root = nullptr;

	cout << "Move Assignment tree" << endl;
	return *this;
}


template<class T> ostream& operator<<(ostream& str, const tree<T>& tree) {
	help_cout(str, tree.root);
	return str;
}


template<class T> ostream& help_cout(ostream& str1, Node<T>* root) {
	if (root != nullptr) {
		help_cout(str1, root->l_child);
		str1 << root->value << " ";
		help_cout(str1, root->r_child);
	}
	return str1;
}




int main() {


	tree<int> T1{ 0, 11, 2, 3, 4, 5, 6 };
	cout << T1 << endl;

	tree<int> T2{ T1 };
	cout << T2 << endl;

	tree<int> T3;
	T3 = T1;
	cout << T3 << endl;

	T3 = T1.ThreeTimes();
	cout << T3 << endl;


	tree<ThreeD<int>> T4{ {1,2,3}, {4,5,6}, {2,2,2}, {3,3,3}, {4,4,4}, {5,5,5}, {1,1,1} };
	cout << T4 << endl;

	tree<ThreeD<int>> T5{ {4,4,4}, {5,5,5}, {6,6,6} };
	cout << T5 << endl;

	tree<LinkedList<int>> T6{ {1} , { 4, 5, 6 }, { 7,8 } };
	cout << T6 << endl;

	tree < LinkedList<ThreeD<int>>> T7{ {{1,2,3}, {4,5,6}, {7,8,9}}, {{1,1,1}, {2,2,2}}, {{3,3,3},{4,4,4}, {5,5,5}} };
	cout << T7 << endl;

	T7 *= 4;
	cout << T7 << endl;
	tree < LinkedList<ThreeD<int>>> T8;
	T8 = T7.ThreeTimes();
	cout << T8 << endl;

	auto p3{ new tree < LinkedList<ThreeD<int>>> { {{1,2,3}, {4,5,6}, {7,8,9}}, {{1,1,1}, {2,2,2}}, {{3,3,3},{4,4,4}, {5,5,5}} } };
	delete p3;

	return 0;
}

