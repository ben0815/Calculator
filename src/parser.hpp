#ifndef PARSER_HPP_
#define PARSER_HPP_


#include <string>
#include <iostream>
#include <vector>
#include <utility>

#include "utilities/binary_expr_tree.hpp"
#include "utilities/utilities.hpp"



// Parses basic math operations for a calculator application.
// TODO: Fix this grammar.
// The grammar is given by:
// <expr>      ::=  <value> | <value> <binary-operator> <expr> <EOL>
// <value>     ::= <integer> | <double> | <unary-operator> <value>
// <EOL>       ::= "\n"
// <unary-operator>   ::= "-"
// <binary-operator>  ::= "+" | "-" | "*" | "/" | "^"
// <integer>   ::= <digit> | <digit> <integer>
// <double>    ::= <integer> "." <integer>
// <digit>     ::= 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9
class parser {

  private:

    // The type of a token.
    enum type {
      INTEGER,
      DOUBLE,
      UNARY_OPERATOR,
      BINARY_OPERATOR,
      UNKNOWN
    };

  public:

    typedef std::pair<type, std::string> token;

    parser() {}

    parser(const bool _debug) : m_debug(_debug) {}

    ~parser();

    // Parse and tokenize an expression and construct and return a binary
    // expression tree.
    const binary_expr_tree<token>* parse(const std::string& _expression);

    // Construct a binary express tree from a vector of tokens.
    const binary_expr_tree<token>* construct_tree(const std::vector<token>& _tokens);

    // Returns true if the string _c is a number or a decimal point signalling
    // the beginning of a floating point number.
    const bool is_value(const char& _c);

    // Returns true if the string _c is one of '+', '-', '*', '/' or '^'.
    const bool is_operator(const char& _char);

    void print_tokens() const;

  private:

    std::vector<token> m_tokens;

    bool m_debug{false};
};


#endif
