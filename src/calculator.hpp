#ifndef CALCULATOR_HPP_
#define CALCULATOR_HPP_


#include <string>

#include "parser.hpp"


class calculator {

  public:

    typedef parser::token token;

    calculator()  {}

    calculator(const bool _debug) : m_debug(_debug)  {}

    ~calculator() {}

    const double calculate(const std::string _expression);

    // Evaluate a binary expression tree.
    const double evaluate(const binary_expr_tree<token>* _expr_tree);

  private:

    bool m_debug{false};

};


#endif
