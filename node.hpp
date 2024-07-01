#pragma once
#include <vector>

template <typename T>
class Node {
private:
    T value;
    std::vector<Node*> children;

public:
    Node(const T& value) : value(value) {}

    ~Node() {
            
    }

    T get_value() const {
        return value;
    }

    std::vector<Node<T>*> getChildren() const {
        return children;
    }

    void addChild(Node<T>* child) {
        children.push_back(child);
    }
};

