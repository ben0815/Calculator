#include "binary_expr_tree.hpp"


binary_expr_tree::
binary_expr_tree(const std::vector<token>& _elements, const bool _debug)
  : m_debug(_debug) {
  // Recursively build the expression tree.
  const auto root = build_tree(_elements);

  if(!root)
    throw tree_error("Binary expression tree constructor", "Unable to set the root");

  set_root(root);
}


typename binary_tree<token>::Node*
binary_expr_tree::
build_tree(const std::vector<token>& _elements) {
  // Select a root for the current subtree.
  const auto root_it = std::min_element(_elements.cbegin(), _elements.cend());

  if(m_debug)
    std::cout << "Subtree root: " << *root_it << std::endl;

  if(root_it == _elements.cend()) {
    if(m_debug)
      std::cout << "Elements vector is empty." << std::endl;

    return nullptr;
  }

  auto root = new Node(*root_it);

  // Recursively build left and right subtrees.
  // Stop when there are no more children to add to the tree.
  if(root_it != _elements.cbegin()) {
    root->left = build_tree(std::vector<token>(_elements.cbegin(), root_it));
    ++m_size;
  }

  if(root_it != _elements.cend() - 1) {
    root->right = build_tree(std::vector<token>(root_it + 1, _elements.cend()));
    ++m_size;
  }

  return root;
}


const double
binary_expr_tree::
evaluate_tree() {
  // Start recursive evaluation. Start with infinity as the result so that we
  // can check for it easily.
  evaluate_subtree(m_root);

  // Make sure the tree has been reduced to just the root containing the result.
  if(m_size != 1)
    throw tree_error("Evaluate tree",
        "Size is greater than 1 after evaluating the tree. Size = " +
        std::to_string(m_size));

  if(!m_root->element.is_number())
    throw tree_error("Evaluate tree",
        "The final root does not contain a number");

  return m_root->element.get_value();
}


void
binary_expr_tree::
evaluate_subtree(typename binary_tree<token>::Node* _node) {
  if(!_node)
    throw tree_error("Evaluate subtree", "Null subtree root");

  if(_node->is_leaf())
    throw tree_error("Evaluate subtree: " +
        static_cast<std::string>(_node->element), "Subtree root is a leaf");

  // Evaluate this subtree.

  const auto l_child = _node->left,
             r_child = _node->right;

  // Case where _node is an operator its left child is a leaf.
  // Traverse down the right subtree.
  if(l_child->is_leaf() and !r_child->is_leaf())
    evaluate_subtree(r_child);

  // Case where _node is an operator its right child is a leaf.
  // Traverse down the left subtree.
  if(!l_child->is_leaf() and r_child->is_leaf())
    evaluate_subtree(l_child);

  // Case where _node is an operator and has two leaf children (numbers).
  if(l_child->is_leaf() and r_child->is_leaf()) {
    // Double check again that the node is an operator.
    if(!_node->element.is_operator())
      throw tree_error("Evaluate subtree: " +
          static_cast<std::string>(_node->element),
          "Subtree root is not an operator");

    // NOTE: This sets _node to the result of the operation changing it from an
    // operator to a number.
    evaluate_operation(_node);

    if(m_size <= 1)
      throw tree_error("Evaluate subtree",
          "Size of tree has been reduced below 1. Size = " +
          std::to_string(m_size));

    m_size -= 2;
  }
  else
    throw tree_error("Evaluate subtree: " +
        static_cast<std::string>(_node->element), "Something went wrong");
}


void
binary_expr_tree::
evaluate_operation(typename binary_tree<token>::Node* _node) const {

  const auto op = _node->element.get_type();

  const auto l = _node->left->element.get_value(),
             r = _node->right->element.get_value();

  if(op == token::add)
    _node->element = token(token::number, l + r);
  else if(op == token::subtract)
    _node->element = token(token::number, l - r);
  else if(op == token::multiply)
    _node->element = token(token::number, l * r);
  else if(op == token::divide)
    _node->element = token(token::number, l / r);
  else if(op == token::exponent)
    _node->element = token(token::number, std::pow(l, r));
  else
    throw tree_error("Evaluate operation" +
        static_cast<std::string>(_node->element), "Invalid operator");

  // Set the children of the node to null since they have been used.
  _node->left = nullptr;
  _node->right = nullptr;
}


std::ostream&
operator<<(std::ostream& _os, const binary_expr_tree& _tree) {
  _os << "Binary Tree (size: " << _tree.size()  << "):" << std::endl;
  _os << "Root: " << _tree.get_root()->element << std::endl;

  return _os;
}
