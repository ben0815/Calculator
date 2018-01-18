#include "binary_expr_tree.hpp"


binary_expr_tree::
binary_expr_tree(const std::vector<token>& _elements) {
  // Select and set the root.
  const auto root_it = std::min_element(_elements.cbegin(), _elements.cend());

  // Check if the element vector is empty and thus no root was selected.
  if(root_it == _elements.cend())
    throw
      tree_error("Constructing binary expression tree", "Failed to select a root");

  std::cout << "Root: " << *root_it << std::endl;

  set_root(*root_it);

  // Build the left and right sides of the tree.
  if(root_it != _elements.cbegin())
    m_root->left = build_tree(std::vector<token>(_elements.cbegin(), root_it));

  if(root_it != _elements.cend() - 1)
    m_root->right = build_tree(std::vector<token>(root_it + 1, _elements.cend()));
}


typename binary_tree<token>::Node*
binary_expr_tree::
build_tree(const std::vector<token>& _elements) {
  // Select a root for the subtree
  const auto root_it = std::min_element(_elements.cbegin(), _elements.cend());




  return new Node(*root_it);
}
