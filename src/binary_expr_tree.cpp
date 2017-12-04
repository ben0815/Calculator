#include "binary_expr_tree.hpp"


binary_expr_tree::
binary_expr_tree(const std::vector<token>& _tokens) {
  // TODO: Algorithm:
  //       1. Start with a high order operator towards the middle of the tokens
  //       as the root
  //       2. Construct the left subtree from the tokens on the left side
  //       3. Construct the right subtree from the tokens on the right side

  auto& root_it = find_highest_order(_tokens);
  set_root(*root_it);

}


const std::vector<token>::const_iterator
binary_expr_tree::
find_highest_order(const std::vector<token>& _tokens) {
  auto middle = _tokens.cbegin() + std::floor(_tokens.size() / 2);

  return middle;//middle->is_high_order() ? middle : _tokens.cbegin();

    /*
  if(middle->is_high_order()) {

  }
  */
}
