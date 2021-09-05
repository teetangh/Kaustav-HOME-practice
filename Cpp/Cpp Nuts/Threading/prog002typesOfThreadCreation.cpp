// TOPIC: Different Types Of Thread Creation And Calling.
// There are 5 different types of creating threads and calling callable in threads.

// NOTES: Different types for creating threads.
// 1. Function Pointer -- this is the very basic form of creating threads.
// 2. Lambda Function
// 3. Functor (Function Object)
// 4. Non-static member function
// 5. Static member function

#include <iostream>
#include <thread>

using namespace std;

// Function Pointer
void fun(int x)
{
    while (x-- > 0)
        cout << x << " ";
    cout << endl;
}

// Functor (Function Object)
class Base
{
public:
    void operator()(int x)
    {
        while (x-- > 0)
            cout << x << " ";
        cout << endl;
    }
};

// Non-static member function
class Base2
{
public:
    void run(int x)
    {
        while (x-- > 0)
            cout << x << " ";
        cout << endl;
    }
};

// Static member function
class Base3
{
public:
    static void run(int x)
    {
        while (x-- > 0)
            cout << x << " ";
        cout << endl;
    }
};

int main(int argc, char const *argv[])
{
    // Function Pointer
    std::thread t1(fun, 11);
    std::thread t2(fun, 10);
    t1.join();
    t2.join();

    // Lambda Function
    // We can directly inject the lambda function into the thread.
    auto fun = [](int x)
    {
        while (x-- > 0)
            cout << x << " ";
        cout << endl;
    };
    std::thread t3(fun, 11);
    t3.join();

    // // Alternative way to create a thread.
    std::thread t4([](int x)
                   {
                       while (x-- > 0)
                           cout << x << " ";
                       cout << endl;
                   },
                   11);

    t4.join();

    // Functor (Function Object)
    std::thread t5(Base(), 11);
    t5.join();

    // Non-static member function
    Base2 b;
    std::thread t6(&Base2::run, &b, 11);
    t6.join();

    // Static member function
    std::thread t7(&Base3::run, 11);
    t7.join();

    return 0;
}
// g++ -std=c++11 -pthread prog002typesOfThreadCreation.cpp && ./a.out
// Sample Output:
// 109 9 8 7 6  8 75  46  35  2 14 0 3  2 1 0 

// 10 9 8 7 6 5 4 3 2 1 0 
// 10 9 8 7 6 5 4 3 2 1 0 
// 10 9 8 7 6 5 4 3 2 1 0 
// 10 9 8 7 6 5 4 3 2 1 0 
// 10 9 8 7 6 5 4 3 2 1 0 