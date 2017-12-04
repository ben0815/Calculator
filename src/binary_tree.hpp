#ifndef BINARY_TREE_HPP_
#define BINARY_TREE_HPP_


template<class T>
class binary_tree {
  // Node definition needs to come before public members so that the functions
  // can use it.
  private:

    struct Node {

      Node() {}

      Node(const T& _element) : m_element(_element) {}

      Node* m_left{nullptr};
      Node* m_right{nullptr};

      T m_element;
    };

  public:

    binary_tree() {}

    ~binary_tree();

  protected:

    void set_root(const T& _element);

  private:

    // Helper for destructing the tree.
    void delete_tree(const Node* _root);

    Node* m_root{nullptr};
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
    delete_tree(_root->m_left);
    delete_tree(_root->m_right);

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
