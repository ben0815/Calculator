#include "calculator.hpp"


const double
calculator::
calculate(const std::string _expression) const {
  parser p(m_debug);

  // Construct a binary expression tree from the input expression.
  const auto& tree = p.parse(_expression);

  // Evaluate the binary expression tree to produce the result of the
  // expression.
  return evaluate(tree);
}


const double
calculator::
evaluate(const binary_expr_tree<token>* _expr_tree) const {

  return 1.;
}
