#ifndef PARSER_HPP_
#define PARSER_HPP_


#include <string>
#include <iostream>
#include <vector>
#include <utility>

#include "token.hpp"
#include "utilities/binary_expr_tree.hpp"
#include "utilities/error.hpp"
#include "utilities/utilities.hpp"


// Parses basic math operations for a calculator application.
// TODO: Fix this grammar.
// The grammar is given by:
// <expr>             ::=  <value> | <value> <binary-operator> <expr> <EOL>
// <value>            ::= <integer> | <double> | <unary-operator> <value>
// <EOL>              ::= "\n"
// <unary-operator>   ::= "-"
// <binary-operator>  ::= "+" | "-" | "*" | "/" | "^"
// <integer>          ::= <digit> | <digit> <integer>
// <double>           ::= <integer> "." <integer>
// <digit>            ::= 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9
class parser {

  private:

    /*
    // The type of a token.
    enum type {
      integer,
      floating_point,
      unary_operator,
      binary_operator,
      unknown
    };

    struct token {
      token(type _type, const std::string& _symbol)
        : m_type(_type), m_symbol(_symbol) {}

      type m_type;

      std::string m_symbol = "";
    };
    */

  public:

    //typedef std::pair<type, std::string> token;

    parser() {}

    parser(const bool _debug) : m_debug(_debug) {}

    ~parser() {}

    // Parse and tokenize an expression and construct and return a binary
    // expression tree.
    const binary_expr_tree<token>* parse(const std::string& _expression);

    // Construct a binary express tree from a vector of tokens.
    const binary_expr_tree<token>* construct_tree(const std::vector<token>& _tokens);

    // Starting from the beginning of a value (digit or decimal point) parse the
    // entire integer or floating point number. Return a pair of the token
    // containing the new number and an iterator to the last character of the
    // number in the expression string.
    const std::pair<token, std::string::const_iterator>
    parse_value(std::string::const_iterator _sit, const std::string& _expression)
    const;

    // Returns true if the character pointed to by _sit is a digit or a decimal
    // point signalling the beginning of a floating point number.
    const bool is_value(std::string::const_iterator _sit) const;

    // Returns true if the character pointed to by _sit is a binary
    // operator, namely one of '+', '-', '*', '/' or '^'.
    const bool is_binary_operator(std::string::const_iterator _sit) const;

  private:

    std::vector<token> m_tokens;

    bool m_debug{false};
};


#endif
