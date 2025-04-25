#include <iostream>

class Car
{
public:
    void Move()
    {
        ++M_pos;
    }
    void ToString()
    {
        std::cout << "Car has postion " << M_pos;
    }
private:
    int M_pos = 0;
};

int main()
{
    Car myCar;
    myCar.Move();
    myCar.ToString();

    // ctrl + d , duplicates lines
    // alt + mouse  , customize selection
}


