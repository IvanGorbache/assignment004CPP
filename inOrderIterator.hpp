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
        return stack.front()->get_value();
    }

    bool operator!=(const InOrderIterator<T>& other) const {
        return this->stack != other.stack;
    }

    InOrderIterator<T>& operator++() {
        if (!stack.empty()){
            current = stack.top();
            stack.pop();
            if (!current->getChildren().empty()) {
                if(current->getChildren().size()>1)
                {
                    push_left_children(current->getChildren().back());
                }
            }
        }
        return *this;
    }

    Node<T>* operator->() const {
        return stack.top();
    }
};
