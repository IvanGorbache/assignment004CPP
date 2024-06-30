#include <stack>
#include "node.hpp"
template <typename T>
class InOrderIterator {
private:
    std::stack<Node<T>*> stack;

public:
    PreOrderIterator(Node<T>* root);

    bool operator!=(const InOrderIterator<T> &other) const;

    Node<T>* operator*() const;

    InOrderIterator& operator++();
};