#ifndef BINARY_EXPR_TREE_HPP_
#define BINARY_EXPR_TREE_HPP_


template<class T>
class binary_expr_tree {

  // Node definition needs to come before public members so that the functions
  // can use it.

  private:

    struct Node;

  public:

    binary_expr_tree() {}

    ~binary_expr_tree() {}


    Node* get_node() { return new Node(); }

  private:

    struct Node {

      Node() {}

      T m_element;
    };

};


#endif
