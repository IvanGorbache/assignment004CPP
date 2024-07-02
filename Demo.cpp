/**
 * Demo app for Ex4
 */
#include <iostream>
#include <string>
#include "node.hpp"
#include "tree.hpp"
#include "complex.hpp"

using namespace std;
int main()
{
    Node<double> root_node = Node<double>(1.1);
    Tree<double> tree; // Binary tree that contains doubles.
    tree.add_root(&root_node);
    Node<double> n1 = Node<double>(1.2);
    Node<double> n2 = Node<double>(1.3);
    Node<double> n3 = Node<double>(1.4);
    Node<double> n4 = Node<double>(1.5);
    Node<double> n5 = Node<double>(1.6);
    //Node<double> n6 = Node<double>(1.7);

    tree.add_sub_node(&root_node, &n1);
    tree.add_sub_node(&root_node, &n2);
    tree.add_sub_node(&n1, &n3);
    tree.add_sub_node(&n1, &n4);
    tree.add_sub_node(&n2, &n5);
    //tree.add_sub_node(&n5,&n6);
   
    // The tree should look like:
    /**
     *       root = 1.1
     *     /       \
     *    1.2      1.3
     *   /  \      /
     *  1.4  1.5  1.6
     */

    for (auto node = tree.begin_pre_order(); node != tree.end_pre_order(); ++node)
    {
        cout << node->get_value() << endl;
    } // prints: 1.1, 1.2, 1.4, 1.5, 1.3, 1.6
    cout << endl;

    std::cout<<"POST:"<<std::endl;

    for (auto node = tree.begin_post_order(); node != tree.end_post_order(); ++node)
    {
        cout << node->get_value() << endl;
    } // prints: 1.4, 1.5, 1.2, 1.6, 1.3, 1.1

    std::cout<<"IN:"<<std::endl;

    for (auto node = tree.begin_in_order(); node != tree.end_in_order(); ++node)
    {
        cout << node->get_value() << endl;
    } // prints: 1.4, 1.2, 1.5, 1.1, 1.6, 1.3

    std::cout<<"BFS:"<<std::endl;

    for (auto node = tree.begin_bfs_scan(); node != tree.end_bfs_scan(); ++node)
    {
        cout << node->get_value() << endl;
    } // prints: 1.1, 1.2, 1.3, 1.4, 1.5, 1.6

    std::cout<<"HEAP:"<<std::endl;

    for (auto node = tree.begin_min_heap(); node != tree.end_min_heap(); ++node)
    {
        cout << node->get_value() << endl;
    } // prints: 1.1, 1.2, 1.3, 1.4, 1.5, 1.6
    
    std::cout<<"FOR:"<<std::endl;

    for (Node<double> node : tree) {
        std::cout << node.get_value() << std::endl;
    }// same as BFS: 1.1, 1.2, 1.3, 1.4, 1.5, 1.6

    

    Node<double> tri_root_node = Node<double>(1.1);

    Tree<double,3> three_ary_tree; // 3-ary tree.
    Node<double> u1 = Node<double>(1.2);
    Node<double> u2 = Node<double>(1.3);
    Node<double> u3 = Node<double>(1.4);
    Node<double> u4 = Node<double>(1.5);
    Node<double> u5 = Node<double>(1.6);

    three_ary_tree.add_root(&tri_root_node);
    three_ary_tree.add_sub_node(&tri_root_node, &u1);
    three_ary_tree.add_sub_node(&tri_root_node, &u2);
    three_ary_tree.add_sub_node(&tri_root_node, &u3);
    three_ary_tree.add_sub_node(&u1, &u4);
    three_ary_tree.add_sub_node(&u2, &u5);

    std::cout<<"BFS:"<<std::endl;

    for (auto node = three_ary_tree.begin_bfs_scan(); node != three_ary_tree.end_bfs_scan(); ++node)
    {
        cout << node->get_value() << endl;
    } 
    //  // The tree should look like:
    // /**
    //  *       root = 1.1
    //  *     /      |     \
    //  *    1.2    1.3    1.4
    //  *   /        |
    //  *  1.5      1.6
    //  */

    std::cout<<"PRE:"<<std::endl;

    for (auto node = three_ary_tree.begin_pre_order(); node != three_ary_tree.end_pre_order(); ++node)
    {
        cout << node->get_value() << endl;
    } // prints: 1.1, 1.2, 1.5, 1.3, 1.6, 1.4

    std::cout<<"POST:"<<std::endl;

    for (auto node = three_ary_tree.begin_post_order(); node != three_ary_tree.end_post_order(); ++node)
    {
        cout << node->get_value() << endl;
    } // prints: 1.5, 1.2, 1.6, 1.3, 1.4, 1.1

    std::cout<<"DFS:"<<std::endl;

    for (auto node = three_ary_tree.begin_dfs_scan(); node != three_ary_tree.end_dfs_scan(); ++node)
    {
        cout << node->get_value() << endl;
    } // prints: 1.5, 1.2, 1.1, 1.6, 1.3, 1.4

    Node<Complex> c_root_node = Node<Complex>(Complex(1,5));
    Tree<Complex> c_tree; 
    c_tree.add_root(&c_root_node);
    Node<Complex> c1 = Node<Complex>(Complex(1,3));
    Node<Complex> c2 = Node<Complex>(Complex(1,6));
    Node<Complex> c3 = Node<Complex>(Complex(1,2));
    Node<Complex> c4 = Node<Complex>(Complex(1,8));
    Node<Complex> c5 = Node<Complex>(Complex(1,7));


    c_tree.add_sub_node(&c_root_node, &c1);
    c_tree.add_sub_node(&c_root_node, &c2);
    c_tree.add_sub_node(&c1, &c3);
    c_tree.add_sub_node(&c1, &c4);
    c_tree.add_sub_node(&c2, &c5);

    std::cout<<"HEAP:"<<std::endl;

    for (auto node = c_tree.begin_min_heap(); node != c_tree.end_min_heap(); ++node)
    {
        cout << node->get_value() << endl;
    } // prints: 
    cout << tree;
    cout << c_tree; // Should print the graph using GUI.

}





