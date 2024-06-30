#pragma once
#include <vector>

template <typename T>
class Node
{
private:
    T value;
    std::vector<Node*> children;
    


public:
    Node(const T& value);
    ~Node();

    template <typename T> Node(T) -> Node<T>; 

    T get_value() const;
    std::vector<Node*> getChildren() const;
    void addChild(Node<T>* child);
};