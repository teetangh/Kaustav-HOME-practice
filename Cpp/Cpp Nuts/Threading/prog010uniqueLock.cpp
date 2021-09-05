// TOPIC: unique_lock In C++

// NOTES:
// 1. The class unique_lock is a mutex ownership wrapper.
// 2. It Allows:
//     a. Can Have Different Locking Strategies
//     b. time-constrained attempts at locking (try_lock_for, try_lock_until)
//     c. recursive locking
//     d. transfer of lock ownership (move not copy)
//     e. condition variables. (See this in coming videos)

// Locking Strategies
//    TYPE           EFFECTS(S)
// 1. defer_lock  do not acquire ownership of the mutex.
// 2. try_to_lock  try to acquire ownership of the mutex without blocking.
// 3. adopt_lock  assume the calling thread already has ownership of the mutex.

#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std;

std::mutex m1;
int buffer = 0;

// EXAMPLE: 1

void uniqueLockExample(const char *threadNumber, int loopCount)
{
    std::unique_lock<std::mutex> lck(m1); // unlock when lck goes out of scope (when the destructor is called)
    for (int i = 0; i < loopCount; ++i)
        std::cout << threadNumber << ": " << ++buffer << std::endl;
}

void uniqueLockWithDeferLockExample(const char *threadNumber, int loopCount)
{
    std::unique_lock<std::mutex> lck(m1, defer_lock); // Does not call lock on the mutex
    lck.lock();                                       // call lock on the mutex
    for (int i = 0; i < loopCount; ++i)
        std::cout << threadNumber << ": " << ++buffer << std::endl;
    // lck.unlock(); // Unlocking is not required as it is done by the destructor
}

int main(int argc, char const *argv[])
{
    std::thread t1(uniqueLockExample, "T1", 10);
    std::thread t2(uniqueLockExample, "T2", 10);

    t1.join();
    t2.join();

    return 0;
}
