// TOPIC: Use Of join(), detach() and joinable() In Thread In C++ (C++11)

// JOIN NOTES
// 0. Once a thread is started we wait for this thread to finish by calling join() function on thread object.
// 1. Double join will result into program termination.
// 2. If needed we should check thread is joinable before joining. ( using joinable() function)

// DETACH NOTES
// 0. This is used to detach newly created thread from the parent thread.
// 1. Always check before detaching a thread that it is joinable otherwise we may end up double detaching and
//    double detach() will result into program termination.
// 2. If we have detached thread and main function is returning then the detached thread execution is suspended.

// NOTES:
// Either join() or detach() should be called on thread object, otherwise during thread object�s destructor it will
// terminate the program. Because inside destructor it checks if thread is still joinable? if yes then it terminates the program.

#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void run(int count)
{
    while (count-- > 0)
        cout << "Inside Run " << count << endl;

    std::this_thread::sleep_for(std::chrono::seconds(5));
    cout << "Thread is exiting" << endl;
}

int main()
{
    std::thread t1(run, 10);
    cout << "Main thread is waiting for thread to finish" << endl;

    // t1.detach(); // Dont want to wait for thread to finish, detach it.
    // if (t1.joinable())
    //     t1.detach(); // Dont want to wait for thread to finish, detach it.

    t1.join();

    if (t1.joinable()) // Best practice to prevent Runtime Error
        t1.join();

    cout << "Main after join" << endl;
    std::this_thread::sleep_for(std::chrono::seconds(5));

    return 0;
}
// g++ -std=c++11 -pthread prog003joinAndDetachWithJoinable.cpp && ./a.out