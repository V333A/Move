#include <iostream>
#include "MyString.h"
#include "MyArray.h"

using namespace std;

int main()
{
    MyString s1("Hello");
    MyString s2 = s1;               // copy constructor
    MyString s3 = MyString("World"); // move constructor

    cout << "s1: " << s1 << endl;
    cout << "s2: " << s2 << endl;
    cout << "s3: " << s3 << endl;

    MyString s4;
    s4 = s1; // copy assignment
    cout << "s4: " << s4 << endl;

    MyString s5;
    s5 = MyString("Move test"); // move assignment
    cout << "s5: " << s5 << endl;

    MyArray a1(5);
    for (int i = 0; i < a1.GetSize(); i++)
    {
        a1[i] = i + 1;
    }

    MyArray a2 = a1;          // copy constructor
    MyArray a3 = MyArray(3);  // move constructor

    cout << "\na1:\n" << a1 << endl;
    cout << "\na2:\n" << a2 << endl;
    cout << "\na3:\n" << a3 << endl;

    MyArray a4;
    a4 = a1; // copy assignment
    cout << "\na4:\n" << a4 << endl;

    MyArray a5;
    a5 = MyArray(4); // move assignment
    cout << "\na5:\n" << a5 << endl;

    return 0;
}