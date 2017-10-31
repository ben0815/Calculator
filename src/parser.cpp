#include "parser.hpp"


parser::
~parser() {
  m_tokens.clear();
}


const binary_expr_tree<parser::token>*
parser::
parse(const std::string& _expression) {

  //std::vector<token> tokens;
  // A set of tokens. Each token is a pair of the type (value, operator, etc.)
  // and the symbol (actual number or operator) as a string.
  std::vector<std::pair<type, std::string>> tokens;

  // Parse and tokenize the expression according to the grammar in the header
  // file.
  for(auto it = _expression.cbegin(); it != _expression.cend(); ++it) {
    if(m_debug)
      std::cout << *it << std::endl;

    if(isspace(*it))
      continue;
    // If c is the start of a value (number or decimal point) parse the entire
    // number.
    else if(is_value(*it)) {
      const auto& start = it;
      auto& end = it;

      while(is_value(*end))
        ++end;

      const std::string value(start, end);

      std::cout << "v: " << value << std::endl;

      it = end;
    }
    else if(is_operator(*it)) {
    }
  }

  if(m_debug)
    print_tokens();

  return nullptr;
}


const binary_expr_tree<parser::token>*
parser::
construct_tree(const std::vector<token>& _tokens) {
  return nullptr;
}


const bool
parser::
is_value(const char& _c) {
  return isdigit(_c) or _c == '.';
}


const bool
parser::
is_operator(const char& _c) {
  return _c == '+' or _c == '-' or _c == '*' or _c == '/' or _c == '^';
}


void
parser::
print_tokens() const {
  std::cout << "Tokens (size: " << m_tokens.size() << "): [ ";

  for(auto it = m_tokens.cbegin(); it != m_tokens.cend(); ++it) {
    std::cout << '(' << it->first << ", " << it->second << ')';

    if(it != m_tokens.cend() - 1)
      std::cout << ", ";
  }

  std::cout << " ]" << std::endl;
}
