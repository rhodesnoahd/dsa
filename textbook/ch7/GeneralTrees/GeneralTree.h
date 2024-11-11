#ifndef GENERAL_TREE_H
#define GENERAL_TREE_H

#include <iostream>
#include <memory>
#include <vector>
using std::cout;

template <typename T>
class Node {
  public:
    Node<T>* parent;
    T data;
    std::vector< std::unique_ptr< Node<T> > > children;

    Node(Node<T>* par = nullptr, const T& val = T()) : parent(par), data(val) {}
    bool isRoot() const { return parent == nullptr; }
    bool isLeaf() const { return children.empty(); }
    void addChild(const T& val) {
      children.push_back(std::make_unique<Node<T>>(this, val));
    }
};

template <typename T>
class Tree {
  public:
    std::unique_ptr<Node<T>> root;

    Tree(const T& val) {
      root = std::make_unique<Node<T>>(nullptr, val);
    }

    int depth(const Node<T>* node) {
      if (node->isRoot()) return 0;
      return 1 + depth((node->parent));
    }

    int height(const std::unique_ptr<Node<T>>& node) {
      if (node->isLeaf()) return 0;
      int h = 0;
      for (const std::unique_ptr<Node<T>>& child : node->children) {
        h = std::max(h, height(child));
      }
      return 1 + h;
    }

    void preorderTraversal() {
      cout << "Preorder Traversal:  ";
      _preorderTraversal(root);
      cout << std::endl;
    }

    void postorderTraversal() {
      cout << "Postorder Traversal: ";
      _postorderTraversal(root);
      cout << std::endl;
    }

  private:
    void _preorderTraversal(const std::unique_ptr<Node<T>>& node) {
      if (!node) return;
      cout << node->data << " ";
      for (const std::unique_ptr<Node<T>>& child : node->children) {
        _preorderTraversal(child);
      }
    }
    
    void _postorderTraversal(const std::unique_ptr<Node<T>>& node) {
    if(!node) return;
    for (const std::unique_ptr<Node<T>>& child : node->children) {
      _postorderTraversal(child);
    }
    cout << node->data << " ";
    }
};

#endif