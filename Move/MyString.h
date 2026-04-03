#pragma once
#include <iostream>

class MyString
{
private:
    char* str;

public:
    MyString();
    explicit MyString(const char* s);
    MyString(const MyString& other);
    MyString(MyString&& other) noexcept;
    ~MyString();

    MyString& operator=(const MyString& other);
    MyString& operator=(MyString&& other) noexcept;

    const char* GetStr() const;

    friend std::ostream& operator<<(std::ostream& out, const MyString& obj);
    friend std::istream& operator>>(std::istream& in, MyString& obj);
};