#pragma once
#include <stack>
#include "node.hpp"

template<typename T>
class PostOrderIterator {
private:
    Node<T>* current;
    std::stack<Node<T>*> stack;
    std::stack<Node<T>*> visited;

public:
    PostOrderIterator(Node<T>* root) : current(root) {
        if (current) {
            stack.push(current);
        }
    }

    T operator*() const {
        return current->get_value();
    }

    PostOrderIterator& operator++() {
        while (!stack.empty()) {
            current = stack.top();
            stack.pop();
            visited.push(current);
            for (Node<T>* child : current->getChildren()) {
                stack.push(child);
            }
        }
        if (!visited.empty()) {
            current = visited.top();
            visited.pop();
        } else {
            current = nullptr;
        }
        return *this;
    }

    bool operator!=(const PostOrderIterator& other) const {
        return current != other.current;
    }
    Node<T>* operator->() const {
        return stack.top();
    }
};