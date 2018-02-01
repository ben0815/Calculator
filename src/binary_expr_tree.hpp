#ifndef BINARY_EXPR_TREE_HPP_
#define BINARY_EXPR_TREE_HPP_

#include <vector>
#include <cmath>
#include <limits>

#include "binary_tree.hpp"
#include "token.hpp"
#include "error.hpp"


class binary_expr_tree : public binary_tree<token> {

  public:

    binary_expr_tree() {}

    // Construct a binary expression tree with a set of tokens in an expression.
    // NOTE: Token must have the less than operator (<) defined.
    binary_expr_tree(const std::vector<token>& _elements, const bool _debug = false);

    ~binary_expr_tree() {}

    typename binary_tree<token>::Node*
      build_tree(const std::vector<token>& _elements);

    // Start the recursive evaluation process.
    // NOTE: The expression must evaluate to a numerical value.
    const double evaluate_tree();

    // Traverse the tree and evaluate each subtree.
    void evaluate_subtree(typename binary_tree<token>::Node* _node);

    // Evaluate an operation consiting of a node (operator) and its two children
    // (numbers).
    void evaluate_operation(typename binary_tree<token>::Node* _node) const;

    friend std::ostream& operator<<(std::ostream& _os,
        const binary_expr_tree& _tree);

  private:

    bool m_debug{false};

};


#endif
