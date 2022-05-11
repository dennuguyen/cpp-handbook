#include <iostream>
#include <queue>
#include <stack>

auto main() -> int {

    { // Simple queue.
        auto q = std::queue<char>({'a', 'b', 'c'});
        std::cout << q.back() << std::endl;
        q.pop();
        std::cout << q.back() << std::endl;
        q.pop();
        q.push('z');
        std::cout << q.back() << std::endl;
        q.pop();
        q.pop();
        std::cout << std::boolalpha << q.empty() << std::endl;
    }

    { // Simple stack.
        auto s = std::stack<char>({'a', 'b', 'c'});
        std::cout << q.top() << std::endl;
        q.pop();
        std::cout << q.top() << std::endl;
        q.pop();
        q.push('z');
        std::cout << q.top() << std::endl;
        q.pop();
        q.pop();
        std::cout << std::boolalpha << q.empty() << std::endl;
    }

    return 0;
}