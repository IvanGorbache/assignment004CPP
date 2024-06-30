#include "node.hpp"

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