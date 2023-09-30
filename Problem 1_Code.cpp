
#include <iostream>
#include <list>
#include <vector>
using namespace std;



template <class T> ostream& operator<<(ostream& str, const vector<T>& V);
template <class T> ostream& operator<<(ostream& str, const vector<T*>& V);
template <class T> ostream& operator<<(ostream& str, const list<T>& L);
template <class T> ostream& operator<<(ostream& str, const list<T*>& L);
void DB1_to_DB2(vector<list<int>>& DB1, list<vector<int>*>& DB2);
void DB2_to_DB3(list<vector<int>*>& DB2, list<list<int*>*>& DB3);
void DB4_to_DB5(vector<vector<list<int>*>>& DB4, list<list<list<int*>*>* >& DB5);
int main() {

	vector<list<int>> DB1{ {1,2,3}, {4,5}, {6,7,8,9} };
	cout << DB1 << endl;

	list<vector<int>*>  DB2;
	DB1_to_DB2(DB1, DB2);
	cout << DB2 << endl;

	list<list<int*>*> DB3;
	DB2_to_DB3(DB2, DB3);
	cout << DB3 << endl;

	vector<vector<list<int>*>> DB4{ {new list<int> {1,2}, new list<int> {3,4,5} },
		{new list<int> {5,6,7,8}, new list<int> {9,10}  } };
	list<list<list<int*>*>* > DB5;
	cout << DB4 << endl;
	DB4_to_DB5(DB4, DB5);
	cout << DB5 << endl;

	return 0;
}


void DB2_to_DB3(list<vector<int>*>& DB2, list<list<int*>*>& DB3) {
	for (auto& i : DB3) {
		for (auto& j : *i) {
			delete j;
		}
		delete i;
	}
	DB3.clear();
	for (auto& i : DB2) {
		list<int*>* p1{ new list<int*> };
		for (auto& j : *i) {
			p1->push_back(new int(j));
		}
		DB3.push_back(p1);
	}
}

void DB4_to_DB5(vector<vector<list<int>*>>& DB4, list<list<list<int*>*>* >& DB5) {
	for (auto& i : DB5) {
		for (auto &j : *i) {
			for (auto &k : *j) {
				delete k;
			}
			delete j;
		}
		delete i;
	}
	DB5.clear();
	for (auto& i : DB4) {
		list < list<int*>*>* p1{ new list<list<int*>*> };
		for (auto& j : i) {
			list<int*>* p2{ new list<int*> };
			for (auto& k : *j) {
				p2->push_back(new int{ k });
			}
			p1->push_back(p2);
		}
		DB5.push_back(p1);
	}

}

void DB1_to_DB2(vector<list<int>>& DB1, list<vector<int>*>& DB2) {

	for (auto& i : DB2) {
		delete i;
	}
	DB2.clear();
	for (auto& i : DB1) {
		vector<int>* p1{ new vector<int> };
		//vector<int> V1; 
		for (auto& j : i) {
			p1->push_back(j);
			//V1.push_back(j);
		}
		DB2.push_back(p1);
		//DB2.push_back(&V1);
	}
}


template <class T> ostream& operator<<(ostream& str, const vector<T>& V) {
	str << "[ ";
	for (auto& i : V) { str << i << " "; }
	str << "]";
	return str;
}
template <class T> ostream& operator<<(ostream& str, const vector<T*>& V) {

	str << "[ ";
	for (auto& i : V) { str << *i << " "; }
	str << "]";
	return str;
}
template <class T> ostream& operator<<(ostream& str, const list<T>& L) {

	str << "< ";
	for (auto& i : L) { str << i << " "; }
	str << ">";
	return str;

}



template <class T> ostream& operator<<(ostream& str, const list<T*>& L) {

	str << "< ";
	for (auto& i : L) { str << *i << " "; }
	str << ">";
	return str;

}