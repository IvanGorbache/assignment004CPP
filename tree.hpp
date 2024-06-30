#pragma once
#include "preOrderIterator.hpp"
#include "inOrderIterator.hpp"
#include "postOrderIterator.hpp"
#include "bfsScan.hpp"


template <typename T, int K = 2>
class Tree
{
private:
    Node<T>* root;
public:
    Tree(/* args */);
    ~Tree();

    void add_root(const Node<T>& root_node);

    void add_sub_node(Node<T>& parent, const Node<T>& child);

    void delete_sub_tree(Node<T>* node);

    PreOrderIterator begin_pre_order();

    PreOrderIterator end_pre_order();

    PostOrderIterator begin_post_order();

    PostOrderIterator end_post_order();

    InOrderIterator begin_in_order();

    InOrderIterator end_in_order();

    BfsScan begin_bfs_scan();

    BfsScan end_bfs_scan();

    std::vector<Node<T>*> myHeap();

    BfsScan begin();

    BfsScan end();

    friend std::ostream& operator<<(std::ostream& os, const Tree<T, K>& tree);
};
