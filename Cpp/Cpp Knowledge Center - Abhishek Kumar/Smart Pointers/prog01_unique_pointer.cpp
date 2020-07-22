#include <iostream>
#include <memory>

struct A
{
    void printA()
    {
        std::cout << "A struct ..." << std::endl;
    }
};

int main(int argc, char const *argv[])
{
    std::unique_ptr<A> p1(new A);
    p1->printA();
    std::cout << p1.get() << std::endl;

    std::unique_ptr<A> p2 = std::move(p1);
    p2->printA();

    std::cout << p1.get() << std::endl;
    std::cout << p2.get() << std::endl;

    std::unique_ptr<A> p3 = std::move(p2);
    p3->printA();

    std::cout << p1.get() << std::endl;
    std::cout << p2.get() << std::endl;
    std::cout << p3.get() << std::endl;


    return 0;
}
