#ifndef BINARY_TREE_HPP_
#define BINARY_TREE_HPP_


template<class T>
class binary_tree {
  // Node definition needs to come before public members so that the functions
  // can use it.
  private:

    struct Node {

      Node() {}

      T m_element;
    };

  public:

    binary_tree() {}

    ~binary_tree() {}

  protected:

  private:

    Node* get_node() { return new Node(); }

};


#endif
