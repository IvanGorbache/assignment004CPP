#include <stack>
#include "node.hpp"
template <typename T>
class PreOrderIterator {
private:
    std::stack<Node<T>*> stack;

public:
    PreOrderIterator(Node<T>* root);

    bool operator!=(const PreOrderIterator<T> &other) const;

    Node<T>* operator*() const;

    PreOrderIterator& operator++();
};