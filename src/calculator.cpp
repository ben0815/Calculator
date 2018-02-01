#include "calculator.hpp"


const double
calculator::
calculate(const std::string& _expression) {
  parser p(m_debug);

  // Construct a binary expression tree from the input expression.
  auto tree = p.parse(_expression);

  if(m_debug)
    std::cout << tree << std::endl;

  // Evaluate the binary expression tree to produce the result of the
  // expression in the remaining root node.
  return tree.evaluate_tree();
}
