#include "preOrderIterator.hpp"

template<typename T>
PreOrderIterator<T>::PreOrderIterator(Node<T>* root) {
    if (root)
        stack.push(root);
}

template<typename T>
bool PreOrderIterator<T>::operator!=(const PreOrderIterator<T>& other) const {
    return !stack.empty() || !other.stack.empty();
}

template<typename T>
Node<T>* PreOrderIterator<T>::operator*() const {
    return stack.top();
}

template<typename T>
PreOrderIterator<T>& PreOrderIterator<T>::operator++() {
    Node<T>* current = stack.top();
    stack.pop();
    // Push right child first to ensure left is processed first (LIFO stack order)
    for (auto it = current->get_children().rbegin(); it != current->get_children().rend(); ++it) {
        stack.push(*it);
    }
    return *this;
}