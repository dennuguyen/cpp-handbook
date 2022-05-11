#include <iostream>

class BaseClass {
   public:
    int a;  // What access will this have in DerivedClass?

   protected:
    int b;  // What access will this have in DerivedClass?

   private:
    int c;  // What access will this have in DerivedClass?
};

class DerivedClass : public BaseClass {
   public:
    int d;

   protected:
    int e;

   private:
    int f;
};

int main() {
}