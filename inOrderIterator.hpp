#pragma once
#include "node.hpp"
#include <stack>

template <typename T>
class InOrderIterator {
private:
    Node<T>* current;
    std::stack<Node<T>*> stack;

    void push_left_children(Node<T>* node) {
        while (node != nullptr) {
            stack.push(node);
            if (!node->getChildren().empty()) {
                node = node->getChildren().front();
            } else {
                break;
            }
        }
    }

public:
    InOrderIterator(Node<T>* root) : current(root) {
        if (current != nullptr) {
            push_left_children(current);
        }
    }

    T operator*() const {
        return current->get_value();
    }

    bool operator!=(const InOrderIterator<T>& other) const {
        return current != other.current;
    }

    InOrderIterator<T>& operator++() {
        if (stack.empty()) {
            current = nullptr;
        } else {
            current = stack.top();
            stack.pop();
            if (!current->getChildren().empty()) {
                if(current->getChildren().size()>1)
                {
                    push_left_children(current->getChildren().back());
                }
                else if(stack.empty())
                {
                    current = nullptr;
                }
                else
                {
                    current = stack.top();

                }
            }
        }
        return *this;
    }

    Node<T>* operator->() const {
        return stack.top();
    }
};

