#include <iostream>

template<class T>
T Add(T a, T b)
{
    return a + b;
}
template<class T>
T Substract(T a, T b)
{
    return a - b;
}
template<class T>
T Multiply(T a, T b)
{
    return a * b;
}
template<class T>
T Division(T a, T b)
{
    return a / b;
}

template<class T>
class AddValue
{
public:
    T value;
    AddValue<T> operator+(const AddValue& rhs)
    {
        AddValue<T> newValue;
        newValue.value = value + rhs.value;
        return newValue;
    }
    AddValue<T> operator-(const AddValue& rhs)
    {
        AddValue<T> newValue;
        newValue.value = value - rhs.value;
        return newValue;
    }
    AddValue<T> operator*(const AddValue& rhs)
    {
        AddValue<T> newValue;
        newValue.value = value * rhs.value;
        return newValue;
    }
    AddValue<T> operator/(const AddValue& rhs)
    {
        AddValue<T> newValue;
        newValue.value = value / rhs.value;
        return newValue;
    }
};

int main()
{
    AddValue<int> a, b;
    a.value = 2.5;
    b.value = 1.5;
    std::cout << Multiply(3, 3);
    std::cout << Add(a.value, b.value);
}
