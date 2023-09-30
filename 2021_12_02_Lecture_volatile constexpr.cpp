/*
Volatile functions in C++
An object declared with the 'volatile' qualifier can be changed
implicitly in the program – without using explicitly specified
commands. The keyword 'volatile' informs the compiler that the
value of a variable in the program can be changed implicitly
(interrupt processing program, background process, etc.).

*/

#include <iostream>
using namespace std;

class C {
public:

    void f() {
        std::cout << "f()\n";
    }

    void f() const {
        std::cout << "f() const\n";
    }

    void f() volatile {
        std::cout << "f() volatile\n";
    }

    void f() const volatile {
        std::cout << "f() const volatile\n";
    }

};

int main() {





    C c1;
    c1.f();

    const C c2;
    c2.f();

    volatile C c3;
    c3.f();

    const volatile C c4;
    c4.f();


    volatile int Limit{ 100 };
    //The following  is an infinite loop
    //To run this code, need to remove it.
    //It is designed to explain the concept of keyword volatile

    while (Limit == 100) {
        //the keyword volatile tells the compilier that the value Limit can be UNCONTROLLABLY
        //modified by environment.
        //It in turn tells the compiler that don't assume the value of Limit will always be 100.
        //Therefore, the compiler will not attempt to optimize the while loop.

            //do something
    }
    /*
    Without the keyword volatile, many compilers will optimize the while loop into the
    followng form.

    while (true){
    //do something
    }

    */

    const int i5{ 50 };


    //const can delay the value initialization until run time.
    //constexpr always initializes values in compile time.
    constexpr float x = 42.0;
    constexpr float y{ 108 };
    constexpr float z = max(x, y);
    // constexpr int i; // Error! Not initialized
    int j = 0;
    // constexpr int k = j + 1; //Error! j not a constant expression
    //constexpr float p = max(j, x);//Errof J not a constant expression
     //...



    //j becomes 100

    const int j1{ j + 1 };//j1 is 101 




}