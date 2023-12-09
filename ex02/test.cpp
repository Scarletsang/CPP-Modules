#include <iostream>

#include "types/Box.hpp"

class Base {
  public:
    Base() {}
    Base(const Base &) {}
    virtual ~Base() {}
  
    virtual void say() const { std::cout << "Base" << std::endl; }
};

class A : public Base
{
  public:
    A() : Base() {}
    A(const A &copy) : Base(copy) {}
    virtual ~A() {}
    virtual void say() const { std::cout << "A" << std::endl; }
};

class B : public Base
{
  public:
    B() : Base() {}
    B(const B &copy) : Base(copy) {}
    virtual ~B() {}
    virtual void say() const { std::cout << "B" << std::endl; }
};

int main()
{
  Box<Base> data = Box<A>(A());

  Box<A> a2 = data;
  a2->say();
  return 0;
}
