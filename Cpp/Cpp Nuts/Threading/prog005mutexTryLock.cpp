// TOPIC: std::mutex::try_lock() On Mutex In C++11 Threading

// 0. try_lock() Tries to lock the mutex. Returns immediately. On successful lock acquisition returns true otherwise returns false.
// 1. If try_lock() is not able to lock mutex, then it doesn't get blocked that's why it is called non-blocking.
// 2. If try_lock is called again by the same thread which owns the mutex, the behavior is undefined.
//    It is a dead lock situation with undefined behavior. (if you want to be able to lock the same mutex by same thread more than one time the go for recursive_mutex)

// There are so many try_lock function
// 1. std::try_lock
// 2. std::mutex::try_lock
// 3. std::shared_lock::try_lock
// 4. std::timed_mutex::try_lock
// 5. std::unique_lock::try_lock
// 6. std::shared_mutex::try_lock
// 7. std::recursive_mutex::try_lock
// 8. std::shared_timed_mutex::try_lock
// 9. std::recursive_timed_mutex::try_loc

#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

int counter = 0;
mutex mtx;

void IncreaseTheCounterFor10000Times()
{
    for (int i = 0; i < 10000; i++)
    {
        // if (mtx.try_lock())
        mtx.lock();
        ++counter;
        mtx.unlock();
    }
}

int main(int argc, char const *argv[])
{
    std::thread t1(IncreaseTheCounterFor10000Times);
    std::thread t2(IncreaseTheCounterFor10000Times);

    t1.join();
    t2.join();

    cout << "Counter could be raised to: " << counter << endl;

    return 0;
}
// g++ -std=c++17 -pthread prog005mutexTryLock.cpp && ./a.out
// Counter could be raised to: 15189 // WITH TRY LOCK  
// Counter could be raised to: 15636 // WITH TRY LOCK 
// Counter could be raised to: 20000 // WITH LOCK