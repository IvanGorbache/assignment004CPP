#pragma once
#include "node.hpp"
#include <queue>
#include <vector>
#include <functional>

template <typename T>
class MinHeapIterator {
private:
    using NodePtr = Node<T>*;
    std::priority_queue<NodePtr, std::vector<NodePtr>, std::function<bool(NodePtr, NodePtr)>> minHeap;

    void addNode(NodePtr node) {
        if (node) {
            minHeap.push(node);
            for (auto child : node->getChildren()) {
                addNode(child);
            }
        }
    }

public:
    MinHeapIterator(NodePtr root) : minHeap([](NodePtr a, NodePtr b) { return a->get_value() > b->get_value(); }) {
        addNode(root);
    }

    T operator*() const {
        return minHeap.top()->get_value();
    }

    MinHeapIterator& operator++() {
        if (!minHeap.empty()) {
            minHeap.pop();
        }
        return *this;
    }

    bool operator!=(const MinHeapIterator& other) const {
        return !(*this == other);
    }

    bool operator==(const MinHeapIterator& other) const {
        return minHeap.empty() == other.minHeap.empty();
    }

    NodePtr operator->() const {
        return minHeap.top();
    }
};
