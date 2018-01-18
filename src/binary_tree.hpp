#ifndef BINARY_TREE_HPP_
#define BINARY_TREE_HPP_


#include <iostream>


template<class T>
class binary_tree {
  // Node definition needs to come before public members so that the functions
  // can use it.
  protected:

    struct Node {

      Node() {}

      Node(const T& _element) : element(_element) {}

      Node* left{nullptr};
      Node* right{nullptr};

      T element;
    };

  public:

    binary_tree() {}

    ~binary_tree();

    friend std::ostream& operator<<(std::ostream& _os,
        const binary_tree& _tree);

  protected:

    void set_root(const T& _element);

    Node* m_root{nullptr};

  private:

    // Helper for destructing the tree.
    void delete_tree(const Node* _root);


    size_t m_size{0};
};


template<class T>
std::ostream&
operator<<(std::ostream& _os, const binary_tree<T>& _tree) {
  _os << "Binary Tree (size: " << _tree.m_size  << "):" << std::endl;

  return _os;
}


template<class T>
binary_tree<T>::
~binary_tree() {
  delete_tree(m_root);
}


template<class T>
void
binary_tree<T>::
delete_tree(const Node* _root) {
  if(_root) {
    // Delete both subtrees.
    delete_tree(_root->left);
    delete_tree(_root->right);

    // Delete root.
    delete _root;
  }
}


template<class T>
void
binary_tree<T>::
set_root(const T& _element) {
  m_root = new Node(_element);
}


#endif
