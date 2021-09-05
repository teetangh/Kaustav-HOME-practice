// TOPIC: Recursive Mutex In C++ (std::recursive_mutex)

// NOTES:
// 0. It is same as mutex but, Same thread can lock one mutex multiple times using recursive_mutex.
// 1. If thread T1 first call lock/try_lock on recursive mutex m1, then m1 is locked by T1, now
//    as T1 is running in recursion T1 can call lock/try_lock any number of times there is no issue.
// 2. But if T1 have aquired 10 times lock/try_lock on mutex m1 then thread T1 will have to unlock
//    it 10 times otherwise no other thread will be able to lock mutex m1.
//    It means recursive_mutex keeps count how many times it was locked so that many times it should be unlocked.
// 3. How many time we can lock recursive_mutex is not defined but when that number reaches and if we were calling
//    lock() it will return std::system_error OR if we were calling try_lock() then it will return false.

// BOTTOM LINE:
// 0. It is similar to mutex but have extra facility that it can be locked multiple time by same thread.
// 1. If we can avoid recursive_mutex then we should because it brings overhead to the system.
// 2. It can be used in loops also.

#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std;

// EXAMPEL 1: With Recursion

std::recursive_mutex m1;
int buffer = 0;

void recursion(char c, int loopFor)
{
    if (loopFor < 0)
        return;

    m1.lock();
    cout << " Thread ID is : " << c << " buffer is " << buffer++ << endl;
    recursion(c, --loopFor);
    m1.unlock();
    cout << " Unlocking Thread ID is : " << c << endl;
}

void loop(char c, int count)
{
    for (int i = 0; i < count; i++)
    {
        m1.lock();
        cout << " Locked Thread ID is : " << c << " iteration numebr is " << i << endl;
    }

    for (int i = 0; i < count; i++)
    {
        cout << " Unlocking Thread ID is : " << c << " iteration numebr is " << i << endl;
        m1.unlock();
    }
}

int main(int argc, char const *argv[])
{
    thread t1(recursion, 'A', 10);
    thread t2(recursion, 'B', 10);

    t1.join();
    t2.join();

    thread t3(loop, 'C', 10);
    thread t4(loop, 'D', 10);

    t3.join();
    t4.join();

    return 0;
}

// // Sample IO
//  Thread ID is : A buffer is 0
//  Thread ID is : A buffer is 1
//  Thread ID is : A buffer is 2
//  Thread ID is : A buffer is 3
//  Thread ID is : A buffer is 4
//  Thread ID is : A buffer is 5
//  Thread ID is : A buffer is 6
//  Thread ID is : A buffer is 7
//  Thread ID is : A buffer is 8
//  Thread ID is : A buffer is 9
//  Thread ID is : A buffer is 10
//  Unlocking Thread ID is : A
//  Unlocking Thread ID is : A
//  Unlocking Thread ID is : A
//  Unlocking Thread ID is : A
//  Unlocking Thread ID is : A
//  Unlocking Thread ID is : A
//  Unlocking Thread ID is : A
//  Unlocking Thread ID is : A
//  Unlocking Thread ID is : A
//  Unlocking Thread ID is : A
//  Unlocking Thread ID is : A
//  Thread ID is : B buffer is 11
//  Thread ID is : B buffer is 12
//  Thread ID is : B buffer is 13
//  Thread ID is : B buffer is 14
//  Thread ID is : B buffer is 15
//  Thread ID is : B buffer is 16
//  Thread ID is : B buffer is 17
//  Thread ID is : B buffer is 18
//  Thread ID is : B buffer is 19
//  Thread ID is : B buffer is 20
//  Thread ID is : B buffer is 21
//  Unlocking Thread ID is : B
//  Unlocking Thread ID is : B
//  Unlocking Thread ID is : B
//  Unlocking Thread ID is : B
//  Unlocking Thread ID is : B
//  Unlocking Thread ID is : B
//  Unlocking Thread ID is : B
//  Unlocking Thread ID is : B
//  Unlocking Thread ID is : B
//  Unlocking Thread ID is : B
//  Unlocking Thread ID is : B
//  Locked Thread ID is : C iteration numebr is 0
//  Locked Thread ID is : C iteration numebr is 1
//  Locked Thread ID is : C iteration numebr is 2
//  Locked Thread ID is : C iteration numebr is 3
//  Locked Thread ID is : C iteration numebr is 4
//  Locked Thread ID is : C iteration numebr is 5
//  Locked Thread ID is : C iteration numebr is 6
//  Locked Thread ID is : C iteration numebr is 7
//  Locked Thread ID is : C iteration numebr is 8
//  Locked Thread ID is : C iteration numebr is 9
//  Unlocking Thread ID is : C iteration numebr is 0
//  Unlocking Thread ID is : C iteration numebr is 1
//  Unlocking Thread ID is : C iteration numebr is 2
//  Unlocking Thread ID is : C iteration numebr is 3
//  Unlocking Thread ID is : C iteration numebr is 4
//  Unlocking Thread ID is : C iteration numebr is 5
//  Unlocking Thread ID is : C iteration numebr is 6
//  Unlocking Thread ID is : C iteration numebr is 7
//  Unlocking Thread ID is : C iteration numebr is 8
//  Unlocking Thread ID is : C iteration numebr is 9
//  Locked Thread ID is : D iteration numebr is 0
//  Locked Thread ID is : D iteration numebr is 1
//  Locked Thread ID is : D iteration numebr is 2
//  Locked Thread ID is : D iteration numebr is 3
//  Locked Thread ID is : D iteration numebr is 4
//  Locked Thread ID is : D iteration numebr is 5
//  Locked Thread ID is : D iteration numebr is 6
//  Locked Thread ID is : D iteration numebr is 7
//  Locked Thread ID is : D iteration numebr is 8
//  Locked Thread ID is : D iteration numebr is 9
//  Unlocking Thread ID is : D iteration numebr is 0
//  Unlocking Thread ID is : D iteration numebr is 1
//  Unlocking Thread ID is : D iteration numebr is 2
//  Unlocking Thread ID is : D iteration numebr is 3
//  Unlocking Thread ID is : D iteration numebr is 4
//  Unlocking Thread ID is : D iteration numebr is 5
//  Unlocking Thread ID is : D iteration numebr is 6
//  Unlocking Thread ID is : D iteration numebr is 7
//  Unlocking Thread ID is : D iteration numebr is 8
//  Unlocking Thread ID is : D iteration numebr is 9