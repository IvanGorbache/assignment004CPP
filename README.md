# Tree Data Structure

### Tree Class

```cpp
template <typename T, int K = 2>
class Tree
```

#### Member Variables:
- `Node<T>* root` - The root node of the tree.
- `int k` - The maximum number of children each node can have (default is 2).

#### Member Functions:

- `Tree()` - Constructor that initializes the tree with a `nullptr` root and sets `k` to `K`.
- `void add_root(Node<T>* root_node)` - Sets the root node of the tree.
- `void add_sub_node(Node<T>* parent, Node<T>* child)` - Adds a child node to the given parent node if the parent's children count is less than `K`.
- `std::vector<Node<T>*> myHeap()` - Returns a vector representing the tree in heap order using BFS.
- `PreOrderIterator<T> begin_pre_order()` - Returns an iterator to the beginning of the tree for pre-order traversal.
- `PreOrderIterator<T> end_pre_order()` - Returns an iterator to the end of the tree for pre-order traversal.
- `PostOrderIterator<T> begin_post_order()` - Returns an iterator to the beginning of the tree for post-order traversal.
- `PostOrderIterator<T> end_post_order()` - Returns an iterator to the end of the tree for post-order traversal.
- `InOrderIterator<T> begin_in_order()` - Returns an iterator to the beginning of the tree for in-order traversal.
- `InOrderIterator<T> end_in_order()` - Returns an iterator to the end of the tree for in-order traversal.
- `BfsScan<T> begin_bfs_scan()` - Returns an iterator to the beginning of the tree for BFS traversal.
- `BfsScan<T> end_bfs_scan()` - Returns an iterator to the end of the tree for BFS traversal.
- `DfsScan<T> begin_dfs_scan()` - Returns an iterator to the beginning of the tree for DFS traversal.
- `DfsScan<T> end_dfs_scan()` - Returns an iterator to the end of the tree for DFS traversal.
- `MinHeapIterator<T> begin_min_heap() const` - Returns an iterator to the beginning of the tree for minimum heap traversal.
- `MinHeapIterator<T> end_min_heap() const` - Returns an iterator to the end of the tree for minimum heap traversal.
- `void visualize() const` - Visualizes the tree using SFML.
- `void drawNode(sf::RenderWindow& window, Node<T>* node, float x, float y, float xOffset) const` - Helper function to draw a node and its children on the SFML window.

### Node Class

```cpp
template <typename T>
class Node
```

#### Member Variables:
- `T value` - The value stored in the node.
- `std::vector<Node*> children` - A vector of child nodes.

#### Member Functions:
- `Node(const T& value)` - Constructor that initializes the node with a given value.
- `~Node()` - Destructor to clean up any resources.
- `T get_value() const` - Returns the value stored in the node.
- `std::vector<Node<T>*> getChildren() const` - Returns the children of the node.
- `void addChild(Node<T>* child)` - Adds a child to the node.

### Complex Class

```cpp
class Complex
```

#### Member Variables:
- `double real` - The real part of the complex number.
- `double imag` - The imaginary part of the complex number.

#### Member Functions:
- `Complex(double r, double i)` - Constructor that initializes the complex number with given real and imaginary parts.
- `double get_real() const` - Returns the real part of the complex number.
- `double get_imag() const` - Returns the imaginary part of the complex number.
- `bool operator>(const Complex& other) const` - Overloads the `>` operator to compare two complex numbers.
- `friend std::ostream& operator<<(std::ostream& os, const Complex& complex)` - Overloads the `<<` operator to print the complex number.
- `std::string to_string() const` - Converts the complex number to a string.
- `friend std::string to_string(const Complex &complex)` - Friend function to convert the complex number to a string.

### Iterators

#### PreOrderIterator

```cpp
template <typename T>
class PreOrderIterator
```

- Traverses the tree in pre-order (root, left, right).
- `PreOrderIterator(Node<T>* root)` - Initializes the iterator with the root node.
- `T operator*() const` - Dereferences the iterator to get the current node's value.
- `bool operator!=(const PreOrderIterator<T>& other) const` - Compares two iterators for inequality.
- `PreOrderIterator<T>& operator++()` - Advances the iterator to the next node in pre-order.
- `Node<T>* operator->() const` - Returns a pointer to the current node.

#### PostOrderIterator

```cpp
template <typename T>
class PostOrderIterator
```

- Traverses the tree in post-order (left, right, root).
- `PostOrderIterator(Node<T>* root)` - Initializes the iterator with the root node.
- `T operator*() const` - Dereferences the iterator to get the current node's value.
- `bool operator!=(const PostOrderIterator<T>& other) const` - Compares two iterators for inequality.
- `PostOrderIterator<T>& operator++()` - Advances the iterator to the next node in post-order.
- `Node<T>* operator->() const` - Returns a pointer to the current node.

#### InOrderIterator

```cpp
template <typename T>
class InOrderIterator
```

- Traverses the tree in in-order (left, root, right).
- `InOrderIterator(Node<T>* root)` - Initializes the iterator with the root node.
- `T operator*() const` - Dereferences the iterator to get the current node's value.
- `bool operator!=(const InOrderIterator<T>& other) const` - Compares two iterators for inequality.
- `InOrderIterator<T>& operator++()` - Advances the iterator to the next node in in-order.
- `Node<T>* operator->() const` - Returns a pointer to the current node.

#### BfsScan

```cpp
template <typename T>
class BfsScan
```

- Traverses the tree in breadth-first search order.
- `BfsScan(Node<T>* root)` - Initializes the iterator with the root node.
- `T operator*() const` - Dereferences the iterator to get the current node's value.
- `bool operator!=(const BfsScan<T>& other) const` - Compares two iterators for inequality.
- `BfsScan<T>& operator++()` - Advances the iterator to the next node in BFS order.
- `Node<T>* operator->() const` - Returns a pointer to the current node.

#### DfsScan

```cpp
template <typename T>
class DfsScan
```

- Traverses the tree in depth-first search order.
- `DfsScan(Node<T>* root)` - Initializes the iterator with the root node.
- `T operator*() const` - Dereferences the iterator to get the current node's value.
- `bool operator!=(const DfsScan<T>& other) const` - Compares two iterators for inequality.
- `DfsScan<T>& operator++()` - Advances the iterator to the next node in DFS order.
- `Node<T>* operator->() const` - Returns a pointer to the current node.

#### MinHeapIterator

```cpp
template <typename T>
class MinHeapIterator
```

- Traverses the tree in minimum heap order.
- `MinHeapIterator(Node<T>* root)` - Initializes the iterator with the root node.
- `T operator*() const` - Dereferences the iterator to get the current node's value.
- `MinHeapIterator& operator++()` - Advances the iterator to the next node in min-heap order.
- `bool operator!=(const MinHeapIterator& other) const` - Compares two iterators for inequality.
- `Node<T>* operator->() const` - Returns a pointer to the current node.
