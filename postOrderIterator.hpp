#pragma once
#include "node.hpp"
#include <stack>

template <typename T>
class PostOrderIterator
{
private:
    Node<T> *current;
    std::stack<Node<T> *> stack;

    void push_children(Node<T> *node)
    {
        while (node != nullptr)
        {
            stack.push(node);
            if (!node->getChildren().empty())
            {
                node = node->getChildren().front();
            }
            else
            {
                node = nullptr;
            }
        }
    }

public:
    PostOrderIterator(Node<T> *root)
    {
        current = root;
        if (current != nullptr)
        {
            push_children(current);
        }
    }

    T operator*() const
    {
        return current->get_value();
    }

    bool operator!=(const PostOrderIterator<T> &other) const
    {
        return current != other.current;
    }

    PostOrderIterator<T> &operator++()
    {
        if (stack.empty())
        {
            current = nullptr;
            return *this;
        }
        Node<T> *top = stack.top();
        stack.pop();

        if (!stack.empty())
        {
            Node<T> *parent = stack.top();
            if (!parent->getChildren().empty() && top == parent->getChildren().back())
            {
                current = parent;
            }
            else
            {
                push_children(parent->getChildren().back());
            }
        }
        else
        {
            current = nullptr;
        }

        return *this;
    }
    Node<T> *operator->() const
    {
        return stack.top();
    }
};
