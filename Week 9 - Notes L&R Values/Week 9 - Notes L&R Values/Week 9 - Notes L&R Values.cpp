#include <iostream>

void Print(int& value) { std::cout << "lvalue reference :" << value << "\n"; }
void Print(int&& value) { std::cout << "rvalue reference :" << value << "\n"; }
void Print(const int& value) {
    std::cout << "const lvalue reference :" << value << "\n";
}

int main()
{
    int val = 7;
    Print(val);
    Print(5);
    const int val2 = val;
    Print(val2);
}
