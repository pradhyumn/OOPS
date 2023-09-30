//HW5 by ************
//SU Net ID: ****************

#include <iostream>
#include <map>
#include <list>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class myCompareClass {
    //For all comparisons, compare the sums of all int objects in the structures.
public:
    bool operator()(int *p1, int *p2) const; //set<int *>
    bool operator()(list<set<int *, myCompareClass> *> *p1, list<set<int *, myCompareClass> *> *p2) const;

    bool operator()(const map<list<set<int *, myCompareClass> *> *, vector<int *> *, myCompareClass> &M1,
                    const map<list<set<int *, myCompareClass> *> *, vector<int *> *, myCompareClass> &M2) const;
};


class myHashEqualClass {
    //For Hashing function use h(sums int in the structure), where hash<int> h;
    //For Hashing, the sum = 2*odd numbers + even numbers
public:
    bool operator()(const map<list<set<int *, myCompareClass> *> *, vector<int *> *, myCompareClass> &M1,
                    const map<list<set<int *, myCompareClass> *> *, vector<int *> *, myCompareClass> &M2) const;

    size_t operator()(const map<list<set<int *, myCompareClass> *> *, vector<int *> *, myCompareClass> &M) const;
};


//The following is a suggestion. You can implement the overloaded operator<< differently.
template<class T>
ostream &operator<<(ostream &str, const list<T *> &L);

template<class T>
ostream &operator<<(ostream &str, const set<T *, myCompareClass> &S);

template<class T>
ostream &operator<<(ostream &str, const vector<T *> &V);

template<class T>
ostream &operator<<(ostream &str, const vector<T> &V);

template<class T1, class T2>
ostream &operator<<(ostream &str, const map<T1 *, T2 *, myCompareClass> &M);

template<class T1, class T2>
ostream &operator<<(ostream &str, const map<T1, T2, myCompareClass> &M);

template<class T>
ostream &operator<<(ostream &str, const set<T, myCompareClass> &S);

template<class T1, class T2>
ostream &operator<<(ostream &str, const unordered_map<T1, T2, myHashEqualClass, myHashEqualClass> &M);


int main() {
    //For each STL container, at least three elements are required.
    set<map<list<set<int *, myCompareClass> *> *, vector<int *> *, myCompareClass>, myCompareClass> S1{
            {
                    /*map1*/{/*list1*/new list<set<int *, myCompareClass> *>{/*set1*/
                    new set<int *, myCompareClass>{new int(13), new int(5), new int(7)},/*set2*/
                    //new set<int *, myCompareClass>{new int(21), new int(25), new int((38))},/*set3*/
                    new set<int*, myCompareClass>{new int(21), new int(25), new int((38))},
                    new set<int *, myCompareClass>{new int(3), new int(62), new int(11)}},/*vector1*/new vector<int *>{
                    new int(7), new int(11), new int(3)}},
                    /*map2*/{/*list1*/new list<set<int *, myCompareClass> *>{/*set1*/
                    new set<int *, myCompareClass>{new int(3), new int(35), new int(17)},/*set2*/
                    new set<int *, myCompareClass>{new int(32), new int(5), new int((8))},/*set3*/
                    new set<int *, myCompareClass>{new int(1), new int(43), new int(6)}},/*vector1*/new vector<int *>{
                    new int(4), new int(14), new int(3)}},
                    /*map3*/{/*list1*/new list<set<int *, myCompareClass> *>{/*set1*/
                    new set<int *, myCompareClass>{new int(3), new int(41), new int(5)},/*set2*/
                    new set<int *, myCompareClass>{new int(2), new int(53), new int((18))},/*set3*/
                    new set<int *, myCompareClass>{new int(2), new int(62), new int(13)}},/*vector1*/ new vector<int *>{
                    new int(5), new int(11), new int(13)}}

            },//159
            {
                    /*map1*/{/*list1*/new list<set<int *, myCompareClass> *>{/*set1*/
                    new set<int *, myCompareClass>{new int(53), new int(61), new int(13)},/*set2*/
                    new set<int *, myCompareClass>{new int(32), new int(4), new int((5))},/*set3*/
                    new set<int *, myCompareClass>{new int(3), new int(9), new int(11)}},/*vector1*/new vector<int *>{
                    new int(14), new int(14), new int(3)}},
                    /*map2*/{/*list1*/new list<set<int *, myCompareClass> *>{/*set1*/
                    new set<int *, myCompareClass>{new int(15), new int(7), new int(13)},/*set2*/
                    new set<int *, myCompareClass>{new int(11), new int(11), new int((15))},/*set3*/
                    new set<int *, myCompareClass>{new int(13), new int(62), new int(8)}},/*vector1*/new vector<int *>{
                    new int(25), new int(12), new int(3)}},
                    /*map3*/{/*list1*/new list<set<int *, myCompareClass> *>{/*set1*/
                    new set<int *, myCompareClass>{new int(3), new int(43), new int(13)},/*set2*/
                    new set<int *, myCompareClass>{new int(32), new int(53), new int((12))},/*set3*/
                    new set<int *, myCompareClass>{new int(2), new int(13), new int(16)}},/*vector1*/new vector<int *>{
                    new int(51), new int(17), new int(2)}}
            },
            {
                    /*map1*/{/*list1*/new list<set<int *, myCompareClass> *>{/*set1*/
                    new set<int *, myCompareClass>{new int(3), new int(5), new int(71)},/*set2*/
                    new set<int *, myCompareClass>{new int(42), new int(35), new int((28))},/*set3*/
                    new set<int *, myCompareClass>{new int(23), new int(16), new int(11)}},/*vector1*/new vector<int *>{
                    new int(71), new int(19), new int(13)}},
                    /*map2*/{/*list1*/new list<set<int *, myCompareClass> *>{/*set1*/
                    new set<int *, myCompareClass>{new int(3), new int(25), new int(17)},/*set2*/
                    new set<int *, myCompareClass>{new int(3), new int(51), new int((8))},/*set3*/
                    new set<int *, myCompareClass>{new int(12), new int(31), new int(6)}},/*vector1*/new vector<int *>{
                    new int(42), new int(14), new int(13)}},
                    /*map3*/{/*list1*/new list<set<int *, myCompareClass> *>{/*set1*/
                    new set<int *, myCompareClass>{new int(13), new int(74), new int(13)},/*set2*/
                    new set<int *, myCompareClass>{new int(1), new int(21), new int((15))},/*set3*/
                    new set<int *, myCompareClass>{new int(16), new int(16), new int(20)}},/*vector1*/new vector<int *>{
                    new int(45), new int(19), new int(4)}}
            }//182

/*set2*/

            /*set1*/
//198
            /*set3*/
    };


    cout << S1 << endl;


    //For each STL container, at least three elements are required.
    unordered_map<map<list<set<int *, myCompareClass> *> *, vector<int *> *, myCompareClass>, vector<int>, myHashEqualClass, myHashEqualClass>
            H1{
/*uo2*/{
               {
                       /*map1*/{/*list1*/new list<set<int *, myCompareClass> *>{/*set1*/
                       new set<int *, myCompareClass>{new int(1114), new int(5), new int(2)},/*set2*/
                       new set<int *, myCompareClass>{new int(2), new int(8), new int((8))},/*set3*/
                       new set<int *, myCompareClass>{new int(3), new int(6), new int(5)}},/*vector1*/new vector<int *>{
                       new int(7), new int(11), new int(3)}},
                       /*map2*/{/*list1*/new list<set<int *, myCompareClass> *>{/*set1*/
                       new set<int *, myCompareClass>{new int(20), new int(5), new int(9)},/*set2*/
                       new set<int *, myCompareClass>{new int(3), new int(6), new int((8))},/*set3*/
                       new set<int *, myCompareClass>{new int(3), new int(31), new int(6)}},/*vector1*/new vector<int *>{
                       new int(4), new int(14), new int(3)}},
                       /*map3*/{/*list1*/new list<set<int *, myCompareClass> *>{/*set1*/
                       new set<int *, myCompareClass>{new int(3), new int(14), new int(5)},/*set2*/
                       new set<int *, myCompareClass>{new int(2), new int(25), new int((18))},/*set3*/
                       new set<int *, myCompareClass>{new int(2), new int(16), new int(13)}},/*vector1*/new vector<int *>{
                       new int(5), new int(11), new int(13)}}

               },/*vector*/{21, 2, 13}//336
       },
       {
               {
                       /*map1*/{/*list1*/new list<set<int *, myCompareClass> *>{/*set1*/
                       new set<int *, myCompareClass>{new int(55), new int(36), new int(13)},/*set2*/
                       new set<int *, myCompareClass>{new int(3), new int(24), new int((5))},/*set3*/
                       new set<int *, myCompareClass>{new int(13), new int(9), new int(11)}},/*vector1*/new vector<int *>{
                       new int(14), new int(14), new int(3)}},
                       /*map2*/{/*list1*/new list<set<int *, myCompareClass> *>{/*set1*/
                       new set<int *, myCompareClass>{new int(5), new int(7), new int(13)},/*set2*/
                       new set<int *, myCompareClass>{new int(13), new int(11), new int((15))},/*set3*/
                       new set<int *, myCompareClass>{new int(32), new int(6), new int(81)}},/*vector1*/new vector<int *>{
                       new int(52), new int(12), new int(3)}},
                       /*map3*/{/*list1*/new list<set<int *, myCompareClass> *>{/*set1*/
                       new set<int *, myCompareClass>{new int(36), new int(44), new int(13)},/*set2*/
                       new set<int *, myCompareClass>{new int(12), new int(5), new int((4))},/*set3*/
                       new set<int *, myCompareClass>{new int(24), new int(13), new int(16)}},/*vector1*/new vector<int *>{
                       new int(5), new int(17), new int(42)}}
               },/*vector*/{1311, 45, 27}//290
       },
               {
               {
                       /*map1*/{/*list1*/new list<set<int*, myCompareClass>*>{/*set1*/
                       new set<int*, myCompareClass>{new int(55), new int(36), new int(13)},/*set2*/
                       new set<int*, myCompareClass>{new int(3), new int(24), new int((5))},/*set3*/
                       new set<int*, myCompareClass>{new int(13), new int(9), new int(11)}},/*vector1*/new vector<int*>{
                       new int(14), new int(14), new int(3)}},
                       /*map2*/{/*list1*/new list<set<int*, myCompareClass>*>{/*set1*/
                       new set<int*, myCompareClass>{new int(5), new int(7), new int(13)},/*set2*/
                       new set<int*, myCompareClass>{new int(13), new int(11), new int((15))},/*set3*/
                       new set<int*, myCompareClass>{new int(32), new int(6), new int(81)}},/*vector1*/new vector<int*>{
                       new int(52), new int(12), new int(3)}},
                       /*map3*/{/*list1*/new list<set<int*, myCompareClass>*>{/*set1*/
                       new set<int*, myCompareClass>{new int(36), new int(44), new int(13)},/*set2*/
                       new set<int*, myCompareClass>{new int(12), new int(5), new int((4))},/*set3*/
                       new set<int*, myCompareClass>{new int(24), new int(13), new int(16)}},/*vector1*/new vector<int*>{
                       new int(5), new int(17), new int(42)}}
               },/*vector*/{131, 45, 27}//290
       },
       {
               {
                       /*map1*/{/*list1*/new list<set<int *, myCompareClass> *>{/*set1*/
                       new set<int *, myCompareClass>{new int(42), new int(5), new int(7)},/*set2*/
                       new set<int *, myCompareClass>{new int(2), new int(42), new int((8))},/*set3*/
                       new set<int *, myCompareClass>{new int(3), new int(6), new int(11)}},/*vector1*/new vector<int *>{
                       new int(7), new int(19), new int(13)}},
                       /*map2*/{/*list1*/new list<set<int *, myCompareClass> *>{/*set1*/
                       new set<int *, myCompareClass>{new int(3), new int(42), new int(17)},/*set2*/
                       new set<int *, myCompareClass>{new int(3), new int(5), new int((42))},/*set3*/
                       new set<int *, myCompareClass>{new int(1), new int(3), new int(6)}},/*vector1*/new vector<int *>{
                       new int(4), new int(14), new int(3)}},
                       /*map3*/{/*list1*/new list<set<int *, myCompareClass> *>{/*set1*/
                       new set<int *, myCompareClass>{new int(1), new int(7), new int(13)},/*set2*/
                       new set<int *, myCompareClass>{new int(42), new int(42), new int((15))},/*set3*/
                       new set<int *, myCompareClass>{new int(6), new int(16), new int(42)}},/*vector1*/new vector<int *>{
                       new int(5), new int(19), new int(4)}}

               },/*vector*/{17, 8, 29}//256
       }


    };

    cout << H1 << endl;


    return 0;
}

bool myCompareClass::operator()(int *p1, int *p2) const {

    return *p1 < *p2;
}

bool myCompareClass::operator()(list<set<int *, myCompareClass> *> *p1, list<set<int *, myCompareClass> *> *p2) const {
    int sum1 = 0, sum2 = 0;
    for (const auto &i: *p1) {
        for (const auto &j: *i) {
            sum1 += *j;
        }
    }
    for (const auto &i: *p2) {
        for (const auto &j: *i) {
            sum2 += *j;
        }
    }
    return sum1 < sum2;
}

bool myCompareClass::operator()(const map<list<set<int *, myCompareClass> *> *, vector<int *> *, myCompareClass> &M1,
                                const map<list<set<int *, myCompareClass> *> *, vector<int *> *, myCompareClass> &M2) const {
    int sum1 = 0, sum2 = 0;
    for (const auto &i: M1) {
        for (const auto &j: *i.first) {
            //list
            for (const auto &k: *j) {
                sum1 += *k;
            }
        }
        for (const auto &m: *i.second) {
            //vector
            sum1 += *m;
        }
    }
    for (const auto &i: M2) {
        for (const auto &j: *i.first) {
            for (const auto &k: *j) {
                sum2 += *k;
            }
        }
        for (const auto &m: *i.second) {
            sum2 += *m;
        }
    }

    return sum1 < sum2;

}

bool myHashEqualClass::operator()(const map<list<set<int *, myCompareClass> *> *, vector<int *> *, myCompareClass> &M1,
                                  const map<list<set<int *, myCompareClass> *> *, vector<int *> *, myCompareClass> &M2) const {
    int sum1 = 0, sum2 = 0;


    for (const auto &i: M1) {
        for (const auto &j: *i.first) {
            for (const auto &k: *j) {
                sum1 += *k;
            }
        }
        for (const auto &m: *i.second) {
            sum1 += *m;
        }
    }
    for (const auto &i: M2) {
        for (const auto &j: *i.first) {
            for (const auto &k: *j) {
                sum2 += *k;
            }
        }
        for (const auto &m: *i.second) {
            sum2 += *m;
        }
    }

    return sum1 == sum2;
}

size_t myHashEqualClass::operator()(
        const map<list<set<int *, myCompareClass> *> *, vector<int *> *, myCompareClass> &M) const {
    int sum1 = 0;
    hash<int> h;
    ///hash    //For Hashing function use h(sums int in the structure), where hash<int> h;
    ///equal to    //For Hashing, the sum = 2*odd numbers + even numbers
    for (const auto &i: M) {
        for (const auto &j: *i.first) {
            for (const auto &k: *j) {
                if ((*k) % 2 == 0) {
                    //even
                    sum1 += *k;
                } else {
                    //odd
                    sum1 += ((*k) * 2);
                }

            }
        }
        for (const auto &m: *i.second) {
            if ((*m) % 2 == 0) {
                //even
                sum1 += *m;
            } else {
                //odd
                sum1 += ((*m) * 2);
            }
        }
    }
    return h(sum1);

}


/// output overload
template<class T>
ostream &operator<<(ostream &str, const list<T *> &L) {
    str << "[ ";
    for (const auto &i: L) {
        str << *i << " ";
    }
    str << "]";
    return str;
}

template<class T>
ostream &operator<<(ostream &str, const set<T *, myCompareClass> &S) {
    str << "< ";
    for (const auto &i: S) {
        str << *i << " ";
    }
    str << ">";
    return str;
}

template<class T>
ostream &operator<<(ostream &str, const vector<T *> &V) {
    str << "( ";
    for (const auto &i: V) {
        str << *i << " ";
    }
    str << ")";
    return str;
}


template<class T>
ostream &operator<<(ostream &str, const vector<T> &V) {
    str << "( ";
    for (const auto &i: V) {
        str << i << " ";
    }
    str << ")";
    return str;
}

template<class T1, class T2>
ostream &operator<<(ostream &str, const map<T1 *, T2 *, myCompareClass> &M) {
    str << endl << "{ ";
    for (const auto &i: M) {
        str << *(i.first) << " " << *(i.second) << " ";
    }
    str << "}";
    return str;
}


template<class T1, class T2>
ostream &operator<<(ostream &str, const map<T1, T2, myCompareClass> &M) {
    str << endl << "{ ";
    for (const auto &i: M) {
        str << (i.first) << " " << (i.second) << " ";
    }
    str << "}";
    return str;
}

template<class T>
ostream &operator<<(ostream &str, const set<T, myCompareClass> &S) {
    str << "< ";
    for (const auto &i: S) {
        str << i << " ";
    }
    str << endl << ">" << endl;
    return str;
}

template<class T1, class T2>
ostream &operator<<(ostream &str, const unordered_map<T1, T2, myHashEqualClass, myHashEqualClass> &M) {
    str << endl << "{ ";
    for (const auto &i: M) {
        str << (i.first) << " " << (i.second) << " ";
    }
    str << endl << "}";
    return str;
}