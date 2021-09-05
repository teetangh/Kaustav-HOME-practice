// TOPIC: Timed Mutex In C++ Threading (std::timed_mutex)
// We have learned Mutex, Race Condition, Critical Section in previous videos.

// NOTES:
// 0. std::timed_mutex is blocked till timeout_time or the lock is aquired and returns true if success
//    otherwise false.
// 1. Member Function:
//    a. lock
//    b. try_lock
//    c. try_lock_for    ---\ These two functions makes it different from mutex.
//    d. try_lock_until  ---/
//    e. unlock

// EXAMPLE: try_lock_for();
// Waits until specified timeout_duration has elapsed or the lock is acquired, whichever comes first.
// On successful lock acquisition returns true, otherwise returns false.

#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

using namespace std;

int myAmount = 0;
std::timed_mutex m;

void tryLockExample(int i)
{
    if (m.try_lock_for(std::chrono::seconds(3)))
    {
        cout << "Thread  " << i << " acquired the lock " << endl;
        ++myAmount;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        m.unlock();
    }
    else
    {
        cout << "Thread " << i << " failed to acquire lock" << endl;
    }
}

void tryLockUntilExample(int i)
{
    auto now = std::chrono::system_clock::now();
    if (m.try_lock_until(now + std::chrono::seconds(2)))
    {
        ++myAmount;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        cout << "Thread " << i << " acquired the lock" << endl;
        m.unlock();
    }
    else
    {
        cout << "Thread " << i << " failed to acquire lock" << endl;
    }
}

int main(int argc, char const *argv[])
{
    std::thread t1(tryLockExample, 1);
    std::thread t2(tryLockExample, 2);

    t1.join();
    t2.join();

    cout << "myAmount = " << myAmount << endl;
    
    std::thread t3(tryLockUntilExample, 3);
    std::thread t4(tryLockUntilExample, 4);

    t3.join();
    t4.join();

    cout << "myAmount = " << myAmount << endl;
    
    return 0;
}
// sample output:
// If try lock time is sufficient, it will acquire the lock and increment the value.
// Thread  1 acquired the lock
// Thread  2 acquired the lock
// myAmount = 2

// If try lock time is not enough, then it will return false.
// Thread  1 acquired the lock
// Thread 2 failed to acquire lock
// myAmount = 1


// Try lock until time is sufficient, it will acquire the lock and increment the value.
// Thread  1 acquired the lock 
// Thread  2 acquired the lock 
// myAmount = 2
// Thread 3 acquired the lock
// Thread 4 acquired the lock
// myAmount = 4

// If try lock until time is not enough, then it will return false.
// Thread  1 acquired the lock 
// Thread  2 acquired the lock 
// myAmount = 2
// Thread 4 failed to acquire lock
// Thread 3 acquired the lock
// myAmount = 3