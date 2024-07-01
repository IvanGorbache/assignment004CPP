#pragma once
#include "node.hpp"
#include <stack>

template <typename T>
class PostOrderIterator
{
private:
    Node<T> *current;
    std::stack<Node<T> *> stack;
    unsigned long index = 0;

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

    T operator*() const {
        return stack.front()->get_value();
    }

    bool operator!=(const PostOrderIterator<T>& other) const {
        return this->stack != other.stack;
    }

    PostOrderIterator<T> &operator++()
    {
        Node<T> *top = stack.top();
        stack.pop();
        if (!stack.empty())
        {
            Node<T> *parent = stack.top();
            if (top != parent->getChildren().back())
            {
                push_children(parent->getChildren().at(++index));

                if(index==parent->getChildren().size()-1)
                {
                    index = 0;
                }
            }
        }
        return *this;
    }
    Node<T> *operator->() const
    {
        return stack.top();
    }
};