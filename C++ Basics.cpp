
/*
Data Types:
Primitive Built-in types:  bool, char, int, float, double, void, wchar_t, size_t
Modifier: singed, unsigned, long, short


Type				Typical Bit Width	Typical Range
char				1byte				-127 to 127 or 0 to 255
unsigned char		1byte				0 to 255
signed char			1byte				-127 to 127
int					4bytes				-2147483648 to 2147483647
unsigned int		4bytes				0 to 4294967295
signed int			4bytes				-2147483648 to 2147483647
short int			2bytes				-32768 to 32767
unsigned short int	2bytes				0 to 65,535
signed short int	2bytes				-32768 to 32767
long int			8bytes				-2,147,483,648 to 2,147,483,647
signed long int		8bytes				same as long int
unsigned long int	8bytes				0 to 4,294,967,295
long long int		8bytes				-(2^63) to (2^63)-1
unsigned long long int	8bytes			0 to 18,446,744,073,709,551,615
float				4bytes
double				8bytes
long double			12bytes
wchar_t				2 or 4 bytes	1 wide character


Derived type: function, array, pointer, reference

User-defined type: class, struct, enum, union, typedef








*/



#include <iostream>//For now, let's always add these two statements.
using namespace std;//Will explain what they mean later in the semester.



int main() {
	//primitive types and size
	{
		int i{ 25 };



		cout << "Size of char : " << sizeof(char) << endl;
		cout << "Size of int : " << sizeof(int) << endl;
		cout << "Size of short int : " << sizeof(short int) << endl;
		cout << "Size of long int : " << sizeof(long int) << endl;
		cout << "Size of float : " << sizeof(float) << endl;
		cout << "Size of double : " << sizeof(double) << endl;
		cout << "Size of wchar_t : " << sizeof(wchar_t) << endl;

	}

	//cout << i << endl; i is undefined.




	//int

	int i;
	i = 100;
	int j{ 1000 };//Declare j to be an int variable and initialize its value to 1000.
	//int j = 1000; //will also work 
	//int j(1000); //will also work

//enum
	enum weekdays { Sunday = 4, Monday, Tuesday, Wednesday, Thrusday = 10, Friday, Saturday };
	weekdays day{ Monday };  //will print 5
	cout << day << endl; //will print value "\n" is faster than endl
	day = Wednesday;
	switch (day) {
	case Sunday: cout << "Sunday" << endl; break;
	case 6: cout << "Wednesday" << endl; break;
	default: break;
	}



	//Pointer

	int* p1;//Declare p1 as a pointer to an int object.
	p1 = &i; //Assign address of i to p1. & operator returns address of an object or variable.
	//Pointer is a variable type  whose value is memory address
	//Address are 4(or 8 ?) bytes in 8 hexadecimal number, such as 45CA679F.
	//Each hexadecimal number has 4 bits (i.e., half a byte).

	cout << i << " " << *p1 << endl;//endl: end of line keyword
	//* operator returns the object whose address is carried in p1.
	// * operator is also referred to as dereference function

	i = 200;
	*p1 = 400;//i becomes 400  the same as i = 400;
	cout << p1 << endl;//Will print the address carried by p1, which is the address of variable i

	//When a pointer carries the address of an object, we say this pointer is pointing to this object.

	//cin >> i;//Program execution will pause here, waiting for you to enter an int value and assign it to i. 


	cout << i << endl;

	int k; // the value of k is undefined and cannot be used without assigning value to it.
	//cout <<k <<endl; Error!  the value of k is undefined.

//array

	int A[5]{ 10,20,30,40,50 };//Declare an array of 5 int elements:  A[0] ... A[4]

	cout << *A << endl;//Will print 10
	//For 1-D arrays, array name without subscript (such as A here) is the address of first element of the array
	//i.e., A the same as &A[0] .
	//*A is the same as A[0]

	cout << A << "  " << A + 2 << endl;//print &A[0] and address of &A[2]
	//Address arithmetic is logical 

	//A[3] will be converted by compiler to *(A+3)

	cout << 3[A] << " " << A[3] << endl;//3[A] will be converted by *(3+A) and A[3] will be
	//converted to *(A+3).  They will give the same result.


	cout << A[25] << endl; //A[25] will be converted by compiler to *(A+25)
	//No error reported.  C++ compiler does not check out-of-bound error!

	cout << sizeof(int) << " " << sizeof(double) << " " << sizeof(char) << " " << sizeof(short) << endl;
	//Print the number of bytes for various data type

//multi-deminsion arrays
	int B[3][5]{ {1,2,3,4,5},{6,7,8,9,10}, {11,12,13,14,15} };

	cout << B[1][3] << " " << *(B[1] + 3) << " " << *(*(B + 1) + 3) << " "
		<< *(&B[0][0] + 5 * 1 + 3) << endl;


	return 0;
}