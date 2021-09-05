// TOPIC: std::lock_guard In C++

// NOTES:
// 0. It is very light weight wrapper for owning mutex on scoped basis.
// 1. It acquires mutex lock the moment you create the object of lock_guard.
// 2. It automatically removes the lock while goes out of scope.
// 3. You can not explicitly unlock the lock_guard.
// 4. You can not copy lock_guard.

#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

std::mutex m1;
int buffer = 0;

void task(const char *threadNumber, int loopCount)
{
    std::lock_guard<std::mutex> lock(m1); // unlock when goes out of scope of lock_guard (i.e when the destructor is called)
    // m1.lock();
    for (int i = 0; i < loopCount; i++)
    {
        cout << "Thread " << threadNumber << ": " << ++buffer << endl;
    }
    // m1.unlock();
}

int main(int argc, char const *argv[])
{
    std::thread t1(task, "T1", 10);
    std::thread t2(task, "T2", 10);

    t1.join();
    t2.join();

    return 0;
}
