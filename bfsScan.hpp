#include <stack>
#include "node.hpp"
template <typename T>
class BfsScan {
private:
    std::stack<Node<T>*> stack;

public:
    BfsScan(Node<T>* root);

    bool operator!=(const BfsScan<T> &other) const;

    Node<T>* operator*() const;

    BfsScan& operator++();
};