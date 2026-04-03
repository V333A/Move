#include <iostream>
#include "MyString.h"

int main()
{
    MyString s1;
    MyString s2("Hello");
    MyString s3 = { 'W', 'o', 'r', 'l', 'd' };
    MyString s4(s2);
    MyString s5(std::move(s3));

    std::cout << "s2 = " << s2 << "\n";
    std::cout << "s4 = " << s4 << "\n";
    std::cout << "s5 = " << s5 << "\n";

    MyString s6(" !!!");
    MyString s7 = s2 + s6;
    std::cout << "s7 = " << s7 << "\n";

    s2 += s6;
    std::cout << "s2 += s6 -> " << s2 << "\n";

    std::cout << "Find 'llo': " << s2.MyFindStr("llo") << "\n";
    std::cout << "Find char 'e': " << s2.MyFindChr('e') << "\n";
    std::cout << "Len: " << s2.MyStrLen() << "\n";

    std::cout << "Objects: " << MyString::GetObjectCount() << "\n";

    return 0;
}