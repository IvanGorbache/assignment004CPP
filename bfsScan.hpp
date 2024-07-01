#pragma once
#include "node.hpp"
#include <queue>

template <typename T>
class BfsScan {
private:
    Node<T>* current;
    std::queue<Node<T>*> queue;

public:
    BfsScan(Node<T>* root) : current(root) {
        if (current != nullptr) {
            queue.push(current);
        }
    }

    T operator*() const {
        return queue.front()->get_value();
    }

    bool operator!=(const BfsScan<T>& other) const {
        return this->queue != other.queue;
    }

    BfsScan<T>& operator++() {
        if (!queue.empty()) {
            current = queue.front();
            queue.pop();
            if(!current->getChildren().empty())
            {
                for (Node<T>* child : current->getChildren()) {
                    queue.push(child);
                }
            }          
        }
        return *this;
    }

    Node<T>* operator->() const {
        
        return queue.front();
    }
};
