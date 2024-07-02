#pragma once
#include "node.hpp"
#include "preOrderIterator.hpp"
#include "postOrderIterator.hpp"
#include "inOrderIterator.hpp"
#include "bfsScan.hpp"
#include "dfsScan.hpp"
#include "minHeapIterator.hpp"
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <queue>

#include "complex.hpp"

template <typename T, int K = 2>
class Tree
{
private:
    Node<T> *root;
    int k;

public:
    Tree() : root(nullptr), k(K) {}

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

    InOrderIterator<T> begin_in_order()
    {
        return InOrderIterator<T>(root);
    }

    InOrderIterator<T> end_in_order()
    {
        return InOrderIterator<T>(nullptr);
    }

    BfsScan<T> begin_bfs_scan()
    {
        return BfsScan<T>(root);
    }

    BfsScan<T> end_bfs_scan()
    {
        return BfsScan<T>(nullptr);
    }

    DfsScan<T> begin_dfs_scan()
    {
        return DfsScan<T>(root);
    }

    DfsScan<T> end_dfs_scan()
    {
        return DfsScan<T>(nullptr);
    }

    BfsScan<T> begin()
    {
        return begin_bfs_scan();
    }

    BfsScan<T> end()
    {
        return end_bfs_scan();
    }

    MinHeapIterator<T> begin_min_heap() const
    {
        return MinHeapIterator<T>(root);
    }

    MinHeapIterator<T> end_min_heap() const
    {
        return MinHeapIterator<T>(nullptr);
    }

    friend std::ostream &operator<<(std::ostream &os, const Tree<T, K> &tree)
    {
        tree.visualize();
        return os;
    }

    void visualize() const
    {
        sf::RenderWindow window(sf::VideoMode(800, 800), "Tree");

        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            window.clear(sf::Color::White);
            if (root)
            {
                drawNode(window, root, 400, 50, 200);
            }
            window.display();
        }
    }

    void drawNode(sf::RenderWindow &window, Node<T> *node, float x, float y, float xOffset) const
    {
        if (!node)
            return;

        sf::CircleShape circle(20);
        circle.setFillColor(sf::Color::Green);
        circle.setPosition(x - circle.getRadius(), y - circle.getRadius());

        sf::Font font;
        if (!font.loadFromFile("/usr/share/fonts/truetype/dejavu/DejaVuSans-Bold.ttf"))
        {
            std::cerr << "Failed not found" << std::endl;
            return;
        }

        sf::Text text;
        std::stringstream ss;
        ss << node->get_value();
        std::string nodeValueStr = ss.str();
        text.setString(nodeValueStr);
        text.setFillColor(sf::Color::Black);
        text.setPosition(x - 10, y - 10);

        float childX = x - xOffset;
        float childY = y + 100;
        for (auto child : node->getChildren())
        {
            sf::Vertex line[] = {
                sf::Vertex(sf::Vector2f(x, y), sf::Color::Black),
                sf::Vertex(sf::Vector2f(childX, childY), sf::Color::Black)};
            window.draw(line, 2, sf::Lines);
            drawNode(window, child, childX, childY, xOffset / 2);
            childX += 2 * xOffset / K;
        }

        
        window.draw(text);
    }
};
