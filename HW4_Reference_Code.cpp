//HW4 by **************
//SU Net ID: ***************

#include <iostream>
#include <memory>
#include <list>

using namespace std;

ostream& operator<<(ostream& str, const list<shared_ptr<int>>& L) {
    //Your code
    str << "( ";
    for (const auto &item: L) {
        str << *item << " ";
    }
    str << ")";
    return str;
}
class node {
public:
	shared_ptr < list<shared_ptr<int>> > Value;
	shared_ptr<node> South;
	weak_ptr<node> East;
	node() {
		Value = make_shared<list<shared_ptr<int>>>();
	}
    //~node()
    //{
    //    cout << "delete "<< *Value << endl;
    //}
};


class TwoD {//rectangle
public:
	int Rows;//Number of Rows
	int Cols;//Number of Columns
	shared_ptr<node> head;
	//TwoD(int i, int j);
	TwoD() : Rows{ 0 }, Cols{ 0 } {}


	//*********************
	//Implement all the following member functions.
	TwoD(int r, int c);//constructor
	TwoD(const initializer_list<initializer_list<initializer_list<int>>>& I);
	TwoD(const TwoD& T);//copy constructor
	TwoD operator=(const TwoD& T); //copy assignment
	~TwoD();//destructor
	TwoD(TwoD&& T);//move constructor
	TwoD operator=(TwoD&& T);//move assignment
	TwoD Times(int k) const;//Return a TwoD object with all values being k times of those in *this .
	void DeleteR(int r); //Delete row r
	void DeleteC(int c); //Delete column c
};







ostream& operator<<(ostream& str, const TwoD&& T) {//Print in column-major order
    auto p = T.head;
    for (int i = 0; i < T.Cols; i++) {
        for (int j = 0; j < T.Rows; j++) {
            str << *p->Value << " ";
            p = p->South;
        }
        str << endl;
    }
    return str;
}


ostream& operator<<(ostream& str, const TwoD& T) {//Print in row-major order
//Your code
    auto rowStart = T.head;
    if (rowStart!=nullptr)
    {
        for (int i = 0; i < T.Rows; ++i) {
            auto p = rowStart;
            for (int j = 0; j < T.Cols; ++j) {
                str << *p->Value << " ";
                p = p->East.lock();
            }
            str << endl;
            rowStart = rowStart->South;
        }
    }
    
    return str;

}



int main() {
    TwoD T1{ { {1,1,1}, {2,2}, {3,3,3}}, {{4,4}, {5,5, 5,5}, {6,6}},
        {{7, 7, 7},{8,8}, {9}}, {{10,10,10,10}, {11,11}, {12,12,12,12,12}} };//4 rows, 3 columns
    cout << T1 << endl;
    TwoD T2(T1);
    cout << T2 << endl;
    T2 = T1.Times(4);
    cout << T2 << endl;
    T1.DeleteR(3);
    cout << T1 << endl;
    cout << move(T1) << endl;
    T2.DeleteC(2);
    cout << T2 << endl;
    cout << move(T2) << endl;
    return 0;
}

TwoD::TwoD(int r, int c) {
	Rows = r;
	Cols = c;
    if (r==0||c==0)
    {
        return;
    }
    // shared ptr
	head = make_shared<node>();
	auto p = head;
	for (int i =0;i<Rows*Cols-1;i++) {
        p->South = make_shared<node>();
        p = p->South;
	}
    p->South = head;
    //weak_ptr
    auto source = head;
    for (int i = 0; i < Rows * Cols; ++i) {
        auto target = source;
        for (int j = 0; j < Rows; ++j) {
            target = target->South;
        }
        source->East = target;
        source = source->South;
    }



}

TwoD::TwoD(const initializer_list<initializer_list<initializer_list<int>>> &I): TwoD(I.size(), I.begin()->size()) {
    cout << "Initializer List" << endl;
    auto rowStart = head;
    for (const auto &i: I) {
        auto p = rowStart;
        for (const auto &j: i) {
            for (const auto &k: j) {
                p->Value->emplace_back(make_shared<int>(k));
            }
            p = p->East.lock();
        }
        rowStart = rowStart->South;
    }

}

TwoD::TwoD(const TwoD &T):TwoD(T.Rows, T.Cols) {
    // copy constructor
    cout << "Copy Constructor" << endl;
    auto rowStart = head;
    auto TrowStart = T.head;
    for (int i = 0; i < Rows*Cols; ++i) {
        for (const auto& item: *TrowStart->Value) {
            rowStart->Value->emplace_back(make_shared<int>(*item));
        }
        //rowStart->Value = TrowStart->Value;
        rowStart = rowStart->South;
        TrowStart = TrowStart->South;
    }

}

TwoD TwoD::operator=(const TwoD &T) {
    cout << "Copy Assignment" << endl;
    TwoD temp{T};
    if (head)
    {
        head->South.reset();
        head.reset();
    }

    head = temp.head;
    Rows = temp.Rows;
    Cols = temp.Cols;
    temp.head.reset();
    return *this;

}

TwoD::~TwoD() {
    // destructor
    cout << "Destructor" << endl;
    if (head) {
        head->South.reset();
        head.reset();
    }

}
TwoD::TwoD(TwoD &&T) {
    // move constructor
    cout << "Move Constructor" << endl;
    head = T.head;
    Rows = T.Rows;
    Cols = T.Cols;
    T.head.reset();
    T.Rows = 0;
    T.Cols = 0;
}

TwoD TwoD::operator=(TwoD &&T) {
    //Move assignment
    cout << "Move Assignment" << endl;
    if (head) {
        head->South.reset();
        head.reset();
    }
    head = T.head;
    Rows = T.Rows;
    Cols = T.Cols;
    T.head.reset();
    T.Rows = 0;
    T.Cols = 0;
    return *this;

}

TwoD TwoD::Times(int k) const {

    TwoD temp{*this};
    cout << "Times" << endl;

    auto TrowStart = temp.head;
    for (int i = 0; i < Rows*Cols; ++i) {
        for (auto item: *TrowStart->Value) {
           *item*=k;
        }
        TrowStart = TrowStart->South;
    }
    return temp;
}

void TwoD::DeleteR(int r) {
    if (r==0 && r == Rows-1)
    {
        //delete the only row

        head->South.reset();
        head.reset();
        Cols = 0;
    }
    else if (r == 0 && r != Rows-1)
    {
        //delete the first row
        if (Rows-1 ==1)
        {
            //only on row left
            head = head->South;
            auto lastRow = head;
            for (int i = 0; i < Cols; ++i) {
                lastRow->South = lastRow->East.lock();
                lastRow = lastRow->East.lock();
            }
        }
        else{
            //more than one row left
            head = head->South;
            auto startRow = head;

            for (int i = 0; i < Cols; ++i) {
                auto p = startRow;

                for (int j = 0; j < Rows - 2; ++j) {
                    p = p->South;
                }
                startRow = startRow->East.lock();
                p->South = startRow;
//            cout << "StartRow: " << *startRow->Value << endl;
//            cout << "p: " << *p->Value << endl;
            }

        }


    }
    else if (r == Rows-1 && r!=0)
    {
        // delete last row
        if (Rows-1==1)
        {
            //only on row left
            auto firstRow = head;
            for (int i = 0; i < Cols; ++i) {
                firstRow->South = firstRow->East.lock();
                firstRow = firstRow->East.lock();
            }

        }
        else
        {
            //more than one row left
            auto startRow = head;

            for (int i = 0; i < Cols; ++i) {
                auto p = startRow;

                for (int j = 0; j < Rows - 2; ++j) {
                    p = p->South;
                }
                startRow = startRow->East.lock();
                p->South = startRow;
//            cout << "StartRow: " << *startRow->Value << endl;
//            cout << "p: " << *p->Value << endl;
            }
        }

    }
    else
    {
        //general delete row r
        auto startRow = head;
        for (int i = 0; i < r - 1; ++i) {
            startRow = startRow->South;

        }
        auto endRow = startRow->South->South;
        //cout << *startRow->Value << endl;

        for (int i = 0; i < Cols; ++i) {
            startRow->South = endRow;
            startRow = startRow->East.lock();
            endRow = endRow->East.lock();
//            cout << "StartRow: " << *startRow->Value << endl;
//            cout << "p: " << *p->Value << endl;
        }
    }
    Rows--;
}

void TwoD::DeleteC(int c) {
    if (c==0&& c == Cols - 1)
    {
        //delete last col
        head->South.reset();
        head.reset();
        Rows = 0;
        //Cols--;
        //return;
    }
    else if (c ==0 && c!= Cols - 1)
    {
        // delete first col
        if (Cols-1 == 1)
        {
            //only one col left
            auto lastCol = head->East.lock();
            auto lastEnd = lastCol;
            auto firstCol = head;
            for (int i = 0; i < Rows; ++i) {
                lastEnd->East = lastEnd;
                if (i==Rows-1)
                {
                    break;
                }
                lastEnd = lastEnd->South;
                firstCol = firstCol->South;
            }
            lastEnd->South = lastCol;
            head = lastCol;
        }
        else {
            //more than one col left
            head = head->East.lock();
            auto firstCol = head;
            auto lastCol = head;
            for (int i = 0; i < Cols - 2; ++i) {
                lastCol = lastCol->East.lock();
            }
            for (int i = 0; i < Rows; ++i) {

                lastCol->East = firstCol;
                if (i == Rows - 1)
                {
                    break;
                }
                firstCol = firstCol->South;
                lastCol = lastCol->South;
            }
            lastCol->South = head;
        }
        
    }
    else if ( c == Cols-1&&c!=0)
    {
        // delete last col
        if (Cols-1==1)
        {
            //only one col left

            auto firstCol = head;
            for (int i = 0; i < Rows; ++i) {
                firstCol->East = firstCol;
                if (i==Rows-1)
                {
                    break;
                }
                firstCol = firstCol->South;
            }
            firstCol->South = head;
        } else
        {
            auto firstCol = head;
            auto lastCol = head;
            for (int i = 0; i < Cols-2; ++i) {
                lastCol = lastCol->East.lock();
            }
            for (int i = 0; i < Rows; ++i) {

                lastCol->East = firstCol;
                if (i == Rows-1)
                {
                    break;
                }
                firstCol = firstCol->South;
                lastCol = lastCol->South;
            }
            lastCol->South = head;
        }


    }
    else
    {
        auto firstCol = head;

        for (int i = 0; i < c-1; ++i) {
            firstCol = firstCol->East.lock();
        }
        auto lastCol = firstCol->East.lock()->East.lock();
        auto lastColFirst = lastCol;
//        cout << *lastCol->Value << endl;
        for (int i = 0; i < Rows; ++i) {

            firstCol->East = lastCol;
            if (i == Rows-1)
            {
                break;
            }
            firstCol = firstCol->South;
            lastCol = lastCol->South;
        }
        firstCol->South = lastColFirst;
    }
    Cols--;
}

