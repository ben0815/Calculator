#include "parser.hpp"


const binary_expr_tree<parser::token>*
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
      auto x = parse_value(sit);
    }
    // Check if the character is a unary operator ('-' as in '-5').
    else if(*sit == '-' and (sit == _expression.cbegin() or is_value(sit - 1))) {
      m_tokens.push_back(std::make_pair(parser::unary_operator,
            std::string(1, *sit)));
    }
    // Check for binary operators.
    else if(is_binary_operator(sit)) {
      m_tokens.push_back(std::make_pair(parser::binary_operator,
            std::string(1, *sit)));
    }
    else
      throw parse_error(_expression, sit, "Unknown symbol.");
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


const std::pair<std::string, std::string::const_iterator>
parser::
parse_value(std::string::const_iterator _sit) const {


  return std::make_pair("", _sit);
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


void
parser::
print_tokens() const {
  std::cout << "Tokens (size: " << m_tokens.size() << "): [ ";

  for(auto it = m_tokens.cbegin(); it != m_tokens.cend(); ++it) {
    std::cout << '(' << (it->first) << ", " << it->second << ')';

    if(it != m_tokens.cend() - 1)
      std::cout << ", ";
  }

  std::cout << " ]" << std::endl;
}


std::ostream&
operator<<(std::ostream& _os, const parser::type& _type) {
  if(_type == parser::integer)
    _os << "integer";
  else if(_type == parser::floating_point)
    _os << "floating_point";
  else if(_type == parser::unary_operator)
    _os << "unary_operator";
  else if(_type == parser::binary_operator)
    _os << "binary_operator";
  else if(_type == parser::unknown)
    _os << "unknown";

  return _os;
}

