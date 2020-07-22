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
    std::shared_ptr<A> p1(new A());
    std::shared_ptr<A> p2(p1);
    std::shared_ptr<A> p3 = p2;

    std::cout << p1.get() << std::endl;
    std::cout << p2.get() << std::endl;
    std::cout << p3.get() << std::endl;

    p1.reset();

    std::cout << p1.get() << std::endl;
    std::cout << p2.get() << std::endl;
    std::cout << p3.get() << std::endl;

    return 0;
}
