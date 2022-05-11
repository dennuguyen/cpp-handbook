#include <iostream>

class A {
   public:
    int data_ = 0;
};

class B : public A {};

class C : public A {};

class D : public B, public C {
   public:
    void modify() {
        data_++;  // Compiler error: reference to data_ is ambiguous.
    }
};

int main() {
    D d;
    d.modify();
}