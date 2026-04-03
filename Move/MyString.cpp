#include "MyString.h"
#include <cstring>

MyString::MyString() : str(nullptr)
{
    str = new char[1];
    str[0] = '\0';
}

MyString::MyString(const char* s) : str(nullptr)
{
    if (s == nullptr)
    {
        str = new char[1];
        str[0] = '\0';
    }
    else
    {
        size_t len = std::strlen(s);
        str = new char[len + 1];
        strcpy_s(str, len + 1, s);
    }
}

MyString::MyString(const MyString& other) : str(nullptr)
{
    size_t len = std::strlen(other.str);
    str = new char[len + 1];
    strcpy_s(str, len + 1, other.str);
}

MyString::MyString(MyString&& other) noexcept : str(other.str)
{
    other.str = nullptr;
}

MyString::~MyString()
{
    delete[] str;
}

MyString& MyString::operator=(const MyString& other)
{
    if (this != &other)
    {
        delete[] str;

        size_t len = std::strlen(other.str);
        str = new char[len + 1];
        strcpy_s(str, len + 1, other.str);
    }
    return *this;
}

MyString& MyString::operator=(MyString&& other) noexcept
{
    if (this != &other)
    {
        delete[] str;

        str = other.str;
        other.str = nullptr;
    }
    return *this;
}

const char* MyString::GetStr() const
{
    return str;
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
    size_t len = std::strlen(buffer);
    obj.str = new char[len + 1];
    strcpy_s(obj.str, len + 1, buffer);

    return in;
}