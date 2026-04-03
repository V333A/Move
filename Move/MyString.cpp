#include "MyString.h"
#include <iostream>
#include <cstring>

int MyString::objectCount = 0;

void MyString::initEmpty(int cap)
{
    if (cap < 1)
        cap = 1;

    capacity = cap;
    str = new char[capacity + 1];
    str[0] = '\0';
    length = 0;
}

void MyString::copyFrom(const char* source)
{
    if (source == nullptr)
    {
        initEmpty(80);
        return;
    }

    length = static_cast<int>(std::strlen(source));
    capacity = length > 80 ? length : 80;
    str = new char[capacity + 1];
    strcpy_s(str, capacity + 1, source);
}

MyString::MyString()
{
    initEmpty(80);
    ++objectCount;
}

MyString::MyString(int size)
{
    initEmpty(size);
    ++objectCount;
}

MyString::MyString(const char* s)
{
    copyFrom(s);
    ++objectCount;
}

MyString::MyString(const MyString& other)
{
    length = other.length;
    capacity = other.capacity;
    str = new char[capacity + 1];
    strcpy_s(str, capacity + 1, other.str);
    ++objectCount;
}

MyString::MyString(std::initializer_list<char> il)
{
    length = static_cast<int>(il.size());
    capacity = length > 80 ? length : 80;
    str = new char[capacity + 1];

    int i = 0;
    for (char ch : il)
    {
        str[i++] = ch;
    }
    str[length] = '\0';
    ++objectCount;
}

MyString::MyString(MyString&& other) noexcept
{
    str = other.str;
    length = other.length;
    capacity = other.capacity;

    other.str = nullptr;
    other.length = 0;
    other.capacity = 0;
    ++objectCount;
}

MyString::~MyString()
{
    delete[] str;
    --objectCount;
}

MyString& MyString::operator=(const MyString& other)
{
    if (this != &other)
    {
        delete[] str;

        length = other.length;
        capacity = other.capacity;
        str = new char[capacity + 1];
        strcpy_s(str, capacity + 1, other.str);
    }
    return *this;
}

MyString& MyString::operator=(MyString&& other) noexcept
{
    if (this != &other)
    {
        delete[] str;

        str = other.str;
        length = other.length;
        capacity = other.capacity;

        other.str = nullptr;
        other.length = 0;
        other.capacity = 0;
    }
    return *this;
}

void MyString::Print() const
{
    std::cout << str;
}

void MyString::MyStrcpy(MyString& obj)
{
    if (this == &obj)
        return;

    delete[] str;

    length = obj.length;
    capacity = obj.capacity;
    str = new char[capacity + 1];
    strcpy_s(str, capacity + 1, obj.str);
}

bool MyString::MyFindStr(const char* substr) const
{
    if (substr == nullptr)
        return false;

    return std::strstr(str, substr) != nullptr;
}

int MyString::MyFindChr(char c) const
{
    for (int i = 0; i < length; ++i)
    {
        if (str[i] == c)
            return i;
    }
    return -1;
}

int MyString::MyStrLen() const
{
    return length;
}

int MyString::GetCapacity() const
{
    return capacity;
}

const char* MyString::c_str() const
{
    return str;
}

MyString MyString::operator+(const MyString& other) const
{
    int newLen = length + other.length;
    MyString temp(newLen);

    delete[] temp.str;
    temp.capacity = newLen > 80 ? newLen : 80;
    temp.str = new char[temp.capacity + 1];

    strcpy_s(temp.str, temp.capacity + 1, str);
    strcat_s(temp.str, temp.capacity + 1, other.str);
    temp.length = newLen;

    return temp;
}

MyString& MyString::operator+=(const MyString& other)
{
    int newLen = length + other.length;
    int newCap = newLen > capacity ? newLen : capacity;

    char* newStr = new char[newCap + 1];
    strcpy_s(newStr, newCap + 1, str);
    strcat_s(newStr, newCap + 1, other.str);

    delete[] str;
    str = newStr;
    length = newLen;
    capacity = newCap;

    return *this;
}

char& MyString::operator[](int index)
{
    return str[index];
}

const char& MyString::operator[](int index) const
{
    return str[index];
}

bool MyString::operator>(const MyString& other) const
{
    return std::strcmp(str, other.str) > 0;
}

bool MyString::operator<(const MyString& other) const
{
    return std::strcmp(str, other.str) < 0;
}

bool MyString::operator==(const MyString& other) const
{
    return std::strcmp(str, other.str) == 0;
}

int MyString::GetObjectCount()
{
    return objectCount;
}

std::ostream& operator<<(std::ostream& out, const MyString& obj)
{
    out << obj.str;
    return out;
}

std::istream& operator>>(std::istream& in, MyString& obj)
{
    char buffer[1000];
    in.getline(buffer, 1000);

    delete[] obj.str;
    obj.length = static_cast<int>(std::strlen(buffer));
    obj.capacity = obj.length > 80 ? obj.length : 80;
    obj.str = new char[obj.capacity + 1];
    strcpy_s(obj.str, obj.capacity + 1, buffer);

    return in;
}