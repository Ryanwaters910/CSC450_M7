#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

void countUp()
{
    for (int i = 1; i <= 20; i++)
    {
        cout << "Thread 1 counting up: " << i << endl;
        this_thread::sleep_for(chrono::milliseconds(100));
    }
}

void countDown()
{
    for (int i = 20; i >= 0; i--)
    {
        cout << "Thread 2 counting down: " << i << endl;
        this_thread::sleep_for(chrono::milliseconds(100));
    }
}

int main()
{
    cout << "Starting Thread 1..." << endl;

    thread threadOne(countUp);
    threadOne.join();

    cout << "Thread 1 finished. Starting Thread 2..." << endl;

    thread threadTwo(countDown);
    threadTwo.join();

    cout << "Both threads have completed." << endl;

    return 0;
}
