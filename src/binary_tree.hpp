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

    const size_t size() const { return m_size; }

    const Node* root() const { return m_root; }

  protected:

    void set_root(Node* _root);
    void set_root(const T& _element);

    void add_node(Node* _where, Node* _what);

    Node* m_root{nullptr};

  private:

    // Helper for destructing the tree.
    void delete_tree(const Node* _root);

    size_t m_size{0};
};


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
set_root(Node* _root) {
  m_root = _root;
  ++m_size;
}


template<class T>
void
binary_tree<T>::
set_root(const T& _element) {
  m_root = new Node(_element);
  ++m_size;
}


template<class T>
void
binary_tree<T>::
add_node(Node* _where, Node* _what) {
  _where = _what;
  ++m_size;
}

#endif
