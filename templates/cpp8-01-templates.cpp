#include <iostream>
#include <vector>

template <typename T>
class stack {
   public:
    void push(T t) {
        list_.push_back(t);
    }

    T pop() {
        auto t = list_.back();
        list_.pop_back();
        return t;
    }

    template <typename U>
    void print(U u) {
        std::cout << u << *this << std::endl;
    }

    friend std::ostream& operator<<(std::ostream& os, stack st) {
        for (auto const& l : st.list_) {
            os << l;
        }
        return os;
    }

   private:
    std::vector<T> list_;
};

int main() {
    {  // Our own stack that works with ints.
        stack<int> l;
        l.push(3);
        l.push(5);
        std::cout << l << std::endl;
    }
    {  // Our own stack that works with std::string.
        stack<std::string> l;
        l.push("hello ");
        l.push("world");
        std::cout << l << std::endl;
        l.print(31.4512);  // Can also have templated methods.
    }
}