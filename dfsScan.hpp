#pragma once
#include "node.hpp"
#include <stack>

template <typename T>
class DfsScan {
private:
    Node<T>* current;
    std::stack<Node<T>*> stack;

public:
    DfsScan(Node<T>* root) : current(root) {
        if (current != nullptr) {
            stack.push(current);
        }
    }

    T operator*() const {
        return stack.front()->get_value();
    }

    bool operator!=(const DfsScan<T>& other) const {
        return this->stack != other.stack;
    }

    DfsScan<T>& operator++() {
        if (stack.empty()) {
            current = nullptr;
            return *this;
        }

        current = stack.top();
        stack.pop();

        // Push children of current node onto the stack in reverse order
        const std::vector<Node<T>*>& children = current->getChildren();
        for (auto it = children.rbegin(); it != children.rend(); ++it) {
            stack.push(*it);
        }

        return *this;
    }

    Node<T>* operator->() const {
        return stack.top();
    }
};
