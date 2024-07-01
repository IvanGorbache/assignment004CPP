#pragma once
#include "node.hpp"
#include "preOrderIterator.hpp"
#include "postOrderIterator.hpp"
#include "inOrderIterator.hpp"
#include "bfsScan.hpp"
#include <vector>
#include <iostream>
#include <queue>

template <typename T, int K = 2>
class Tree
{
private:
    Node<T> *root;

public:
    Tree() : root(nullptr) {}

    void add_root(Node<T> *root_node)
    {
        root = root_node;
    }

    void add_sub_node(Node<T> *parent, Node<T> *child)
    {
        if (parent->getChildren().size() < K)
        {
            parent->addChild(child);
        }
    }

    std::vector<Node<T> *> myHeap()
    {
        std::vector<Node<T> *> heap;
        std::queue<Node<T> *> queue;
        if (root)
            queue.push(root);
        while (!queue.empty())
        {
            Node<T> *current = queue.front();
            queue.pop();
            heap.push_back(current);
            for (Node<T> *child : current->getChildren())
            {
                queue.push(child);
            }
        }
        return heap;
    }

    PreOrderIterator<T> begin_pre_order()
    {
        return PreOrderIterator<T>(root);
    }

    PreOrderIterator<T> end_pre_order()
    {
        return PreOrderIterator<T>(nullptr);
    }

    PostOrderIterator<T> begin_post_order()
    {
        return PostOrderIterator<T>(root);
    }

    PostOrderIterator<T> end_post_order()
    {
        return PostOrderIterator<T>(nullptr);
    }

    InOrderIterator<T> begin_in_order() {
        return InOrderIterator<T>(root);
    }

    InOrderIterator<T> end_in_order() {
        return InOrderIterator<T>(nullptr);
    }

    BfsScan<T> begin_bfs_scan() {
        return BfsScan<T>(root);
    }

    BfsScan<T> end_bfs_scan() {
        return BfsScan<T>(nullptr);
    }

    BfsScan<T> begin() {
        return begin_bfs_scan();
    }

    BfsScan<T> end() {
        return end_bfs_scan();
    }
};
