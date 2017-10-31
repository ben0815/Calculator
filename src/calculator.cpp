#include "calculator.hpp"


const double
calculator::
calculate(const std::string _expression) {
  parser p(m_debug);

  // Construct a binary expression tree from the input expression.
  const auto& expr_tree = p.parse(_expression);

  // Evaluate the binary expression tree to produce the result of the
  // expression.
  return evaluate(expr_tree);
}


const double
calculator::
evaluate(const binary_expr_tree<token>* _expr_tree) {

  return 1.;
}
