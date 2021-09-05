
// TOPIC: Condition Variable In C++ Threading

// NOTES:
// 1. Condition variables allow us to synchronize threads via notifications.
//    a. notify_one();
//    b. notify_all();
// 2. You need mutex to use condition variable
// 3. Condition variable is used to synchronize two or more threads.
// 4. Best use case of condition variable is Producer/Consumer problem.
// 5. Condition variables can be used for two purposes:
//     a. Notify other threads
//     b. Wait for some condition

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

std::condition_variable cv;
std::mutex mtx;
long balance = 0;

void addMoney(int money)
{
    std::lock_guard<std::mutex> lk(mtx);
    balance += money;
    cout << "Amount added and Current Balance is : " << balance << endl;
    cv.notify_one();
}

void withdrawMoney(int money)
{
    std::unique_lock<std::mutex> lk(mtx);
    cv.wait(lk, []
            { return (balance != 0) ? true : false; });

    if (balance >= money)
    {
        balance -= money;
        cout << "Amount withdrawn: " << money << endl;
        cout << "After deduction Current Balance is: " << balance << endl;
    }
    else
    {
        cout << "Insufficient funds since current Balance is: " << balance << endl;
    }
    cout << "Current Balance: " << balance << endl;
}

int main(int argc, char const *argv[])
{
    std::thread t1(withdrawMoney, 600);
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::thread t2(addMoney, 500);

    t1.join();
    t2.join();

    return 0;
}
// // Sample Output
// Amount added and Current Balance is : 100
// Amount withdrawn: 50
// After deduction Current Balance is: 50
// Current Balance: 50

// Sample Output 2
// Amount added and Current Balance is : 500
// Insufficient funds since current Balance is: 500
// Current Balance: 500