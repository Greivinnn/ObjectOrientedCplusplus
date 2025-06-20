#include <iostream>
#include <thread>
#include <chrono> // this is to use time

void ThreadFunction1()
{
    std::cout << "This is a thread 1\n";
}
void ThreadFunction2()
{
    std::cout << "This is a thread 2\n";
}


int main()
{
    const auto startTime = std::chrono::high_resolution_clock::now(); // gives the time of right now



    std::thread t1(ThreadFunction1);
    std::thread t2(ThreadFunction2);

    t1.join();
    t2.join();

    const auto endTime = std::chrono::high_resolution_clock::now(); // gives the time of right now
    const auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count();   // converts time to milliseconds

    std::cout << "Time (milliseconds): " << milliseconds; // display how long it took to do the 2 threads
    return 0;
}

