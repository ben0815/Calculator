#ifndef CALCULATOR_HPP_
#define CALCULATOR_HPP_


#include <string>

#include "parser.hpp"


// Calculator class which utilizes a parser and a binary expression tree to read
// and evaluate expressions.
class calculator {

  public:


    calculator()  {}

    calculator(const bool _debug) : m_debug(_debug)  {}

    ~calculator() {}

    const double calculate(const std::string _expression) const;

    // Evaluate a binary expression tree.
    const double evaluate(const binary_expr_tree<token>* _expr_tree) const;

  private:

    bool m_debug{false};
};


#endif
