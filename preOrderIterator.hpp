#include <stack>
#include "node.hpp"
template <typename T>
class PreOrderIterator
{
private:
    std::stack<Node<T> *> stack;

public:
    PreOrderIterator(Node<T> *root)
    {
        if (root)
            stack.push(root);
    }

    bool operator!=(const PreOrderIterator<T> &other) const
    {
        return !stack.empty() || !other.stack.empty();
    }

    Node<T> *operator*() const
    {
        return stack.top();
    }

    PreOrderIterator<T> &operator++()
    {
        if (stack.empty())
        {
            return *this; // Avoid further actions if stack is empty
        }

        Node<T> *current = stack.top();
        stack.pop();

        auto children = current->getChildren();
        for (auto it = children.rbegin(); it != children.rend(); ++it)
        {
            stack.push(*it);
        }

        return *this;
    }

    Node<T> *operator->() const
    {
        return stack.top();
    }
};