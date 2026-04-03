#pragma once
#include <iostream>
#include <initializer_list>

class MyString
{
private:
    char* str;
    int length;
    int capacity;

    static int objectCount;

    void initEmpty(int cap = 80);
    void copyFrom(const char* source);

public:
    MyString();                              // по умолчанию: строка длиной 80 символов
    explicit MyString(int size);             // произвольный размер
    MyString(const char* s);                 // от const char*
    MyString(const MyString& other);         // copy constructor
    MyString(std::initializer_list<char> il);// {'a','b','c'}
    MyString(MyString&& other) noexcept;     // move constructor
    ~MyString();

    MyString& operator=(const MyString& other);
    MyString& operator=(MyString&& other) noexcept;

    void Print() const;

    void MyStrcpy(MyString& obj);            // копирование с затиранием прошлого значения
    bool MyFindStr(const char* substr) const;
    int MyFindChr(char c) const;
    int MyStrLen() const;
    int GetCapacity() const;

    const char* c_str() const;

    MyString operator+(const MyString& other) const;
    MyString& operator+=(const MyString& other);

    char& operator[](int index);
    const char& operator[](int index) const;

    bool operator>(const MyString& other) const;
    bool operator<(const MyString& other) const;
    bool operator==(const MyString& other) const;

    static int GetObjectCount();

    friend std::ostream& operator<<(std::ostream& out, const MyString& obj);
    friend std::istream& operator>>(std::istream& in, MyString& obj);
};