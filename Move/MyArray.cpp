#include "MyArray.h"

MyArray::MyArray() : ar(nullptr), size(0)
{
}

MyArray::MyArray(int size) : ar(nullptr), size(size)
{
    if (size > 0)
    {
        ar = new int[size];
        for (int i = 0; i < size; i++)
        {
            ar[i] = 0;
        }
    }
    else
    {
        this->size = 0;
    }
}

MyArray::MyArray(const MyArray& other) : ar(nullptr), size(other.size)
{
    if (size > 0)
    {
        ar = new int[size];
        for (int i = 0; i < size; i++)
        {
            ar[i] = other.ar[i];
        }
    }
}

MyArray::MyArray(MyArray&& other) noexcept : ar(other.ar), size(other.size)
{
    other.ar = nullptr;
    other.size = 0;
}

MyArray::~MyArray()
{
    delete[] ar;
}

MyArray& MyArray::operator=(const MyArray& other)
{
    if (this != &other)
    {
        delete[] ar;

        size = other.size;
        if (size > 0)
        {
            ar = new int[size];
            for (int i = 0; i < size; i++)
            {
                ar[i] = other.ar[i];
            }
        }
        else
        {
            ar = nullptr;
        }
    }
    return *this;
}

MyArray& MyArray::operator=(MyArray&& other) noexcept
{
    if (this != &other)
    {
        delete[] ar;

        ar = other.ar;
        size = other.size;

        other.ar = nullptr;
        other.size = 0;
    }
    return *this;
}

int MyArray::GetSize() const
{
    return size;
}

int& MyArray::operator[](int index)
{
    return ar[index];
}

const int& MyArray::operator[](int index) const
{
    return ar[index];
}

std::ostream& operator<<(std::ostream& out, const MyArray& obj)
{
    out << "Size: " << obj.size << "\n";
    for (int i = 0; i < obj.size; i++)
    {
        out << obj.ar[i] << " ";
    }
    return out;
}

std::istream& operator>>(std::istream& in, MyArray& obj)
{
    std::cout << "Enter size: ";
    int newSize;
    in >> newSize;

    delete[] obj.ar;
    obj.size = newSize;
    obj.ar = new int[obj.size];

    for (int i = 0; i < obj.size; i++)
    {
        std::cout << "ar[" << i << "] = ";
        in >> obj.ar[i];
    }

    return in;
}