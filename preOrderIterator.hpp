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

    T operator*() const {
        return stack.front()->get_value();
    }

    bool operator!=(const PreOrderIterator<T>& other) const {
        return this->stack != other.stack;
    }

    PreOrderIterator<T> &operator++()
    {
        if (stack.empty())
        {
            return *this;
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