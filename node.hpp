#pragma once
#include <vector>

template <typename T>
class Node {
private:
    T value;
    std::vector<Node*> children;

public:
    Node() = default;
    Node(const T& value);
    ~Node();

    T get_value() const;
    std::vector<Node*> getChildren() const;
    void addChild( Node<T>* child);
};

template <typename T>
Node<T>::Node(const T& value) : value(value) {}

template <typename T>
Node<T>::~Node() {
    // You can implement a proper destructor to delete child nodes if necessary
}

template <typename T>
T Node<T>::get_value() const {
    return value;
}

template <typename T>
std::vector<Node<T>*> Node<T>::getChildren() const {
    return children;
}

template <typename T>
void Node<T>::addChild(Node<T>* child) {
    children.push_back(child);
}

