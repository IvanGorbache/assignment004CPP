#include <stack>
#include "node.hpp"
template <typename T>
class PostOrderIterator {
private:
    std::stack<Node<T>*> stack;

public:
    PreOrderIterator(Node<T>* root);

    bool operator!=(const PostOrderIterator<T> &other) const;

    Node<T>* operator*() const;

    PostOrderIterator& operator++();
};