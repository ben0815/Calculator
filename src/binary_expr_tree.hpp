#ifndef BINARY_EXPR_TREE_HPP_
#define BINARY_EXPR_TREE_HPP_

#include <vector>
#include <cmath>

#include "binary_tree.hpp"
#include "token.hpp"


class binary_expr_tree : public binary_tree<token> {

  public:

    binary_expr_tree() {}

    // Construct a binary expression tree with a set of tokens in an expression.
    binary_expr_tree(const std::vector<token>& _elements);

    ~binary_expr_tree() {}

    // Find the highest order operator towards the middle of the input vector.
    const std::vector<token>::const_iterator
      find_highest_order(const std::vector<token>& _tokens);

  private:

};


#endif
