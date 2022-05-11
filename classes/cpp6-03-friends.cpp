#include <iostream>

class Graph;  // Forward declaration.

class Node {
    // Access specifier doesn't matter for friends.
    friend void setVal(Node& node, int val) { node.val_ = val; }  // setVal as friend function.
    friend Graph;                                                 // Graph can access Node's privates.

   public:
    void setVal(int val) { val_ = val; }  // setVal as public member function.

   private:
    int val_;  // Private member.
};

class Graph {
   public:
    int getNodeValue(Node node) {
        return node.val_;
    }
};

int main() {
    Graph g;
    Node n;

    setVal(n, 3);                                 // setVal can access Node's privates.
    std::cout << g.getNodeValue(n) << std::endl;  // Graph can access Node's privates.

    n.setVal(4);  // setVal can access Node's privates.
    std::cout << g.getNodeValue(n) << std::endl;
}