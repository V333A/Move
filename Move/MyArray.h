#pragma once
#include <iostream>

class MyArray
{
private:
    int* ar;
    int size;

public:
    MyArray();
    explicit MyArray(int size);
    MyArray(const MyArray& other);
    MyArray(MyArray&& other) noexcept;
    ~MyArray();

    MyArray& operator=(const MyArray& other);
    MyArray& operator=(MyArray&& other) noexcept;

    int GetSize() const;
    int& operator[](int index);
    const int& operator[](int index) const;

    friend std::ostream& operator<<(std::ostream& out, const MyArray& obj);
    friend std::istream& operator>>(std::istream& in, MyArray& obj);
};