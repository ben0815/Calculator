#include "binary_expr_tree.hpp"


binary_expr_tree::
binary_expr_tree(const std::vector<token>& _elements, const bool _debug)
  : m_debug(_debug) {
  // Recursively build the expression tree.
  const auto root = build_tree(_elements);

  if(!root)
    throw tree_error("Binary expression tree constructor", "Unable to set the root");

  if(m_debug)
    std::cout << "Root: " << root->element << std::endl;

  set_root(root);
}


typename binary_tree<token>::Node*
binary_expr_tree::
build_tree(const std::vector<token>& _elements) {
  // Select a root.
  const auto root_it = std::min_element(_elements.cbegin(), _elements.cend());

  if(root_it == _elements.cend()) {
    if(m_debug)
      std::cout << "Elements vector is empty." << std::endl;

    return nullptr;
  }

  const auto root = new Node(*root_it);

  // Recursively build left and right subtrees.
  // Stop when there are no more children to add to the tree.
  if(root_it != _elements.cbegin())
    add_node(root->left,
        build_tree(std::vector<token>(_elements.cbegin(), root_it)));

  if(root_it != _elements.cend() - 1)
    add_node(root->right,
        build_tree(std::vector<token>(root_it + 1, _elements.cend())));

  return root;
}


std::ostream&
operator<<(std::ostream& _os, const binary_expr_tree& _tree) {
  _os << "Binary Tree (size: " << _tree.size()  << "):" << std::endl;
  _os << "Root: " << _tree.root()->element << std::endl;

  return _os;
}
