#include "parser.hpp"

const binary_expr_tree<token>*
parser::
parse(const std::string& _expression) {

  // Parse and tokenize the expression according to the grammar in the header
  // file.
  for(auto sit = _expression.cbegin(); sit != _expression.cend(); ++sit) {
    if(m_debug)
      std::cout << *sit << std::endl;

    // Skip whitespace.
    if(isspace(*sit))
      continue;
    // If c is the start of a value (number or decimal point) parse the entire
    // number.
    else if(is_value(sit)) {
      const auto& pair = parse_value(sit, _expression);

      if(pair.second == _expression.cend()) {}

    }
    // Check if the character is a unary operator ('-' as in '-5').
    else if(*sit == '-' and (sit == _expression.cbegin() or is_value(sit - 1))) {
      m_tokens.push_back(token(token::unary_operator,
            std::string(1, *sit)));
    }
    // Check for binary operators.
    else if(is_binary_operator(sit)) {
      m_tokens.push_back(token(token::binary_operator,
            std::string(1, *sit)));
    }
    else
      throw parse_error(_expression, sit, "Unknown symbol");
  }

  if(m_debug)
    std::cout << "Tokens: " << m_tokens << std::endl;

  return nullptr;
}


const binary_expr_tree<token>*
parser::
construct_tree(const std::vector<token>& _tokens) {
  return nullptr;
}


const std::pair<token, std::string::const_iterator>
parser::
parse_value(std::string::const_iterator _sit, const std::string& _expression)
  const {
    // A number can only have one decimal point.
    bool decimal_point = *_sit == '.';

    std::string number = "";
    token tok;

    if(decimal_point)
      tok = token(token::floating_point, std::string(1, *_sit));

  return std::make_pair(token(), _expression.cend());
}


const bool
parser::
is_value(std::string::const_iterator _sit) const {
  return isdigit(*_sit) or *_sit == '.';
}


const bool
parser::
is_binary_operator(std::string::const_iterator _sit) const {
  return *_sit == '+' or *_sit == '-' or *_sit == '*' or *_sit == '/'
    or *_sit == '^';
}
