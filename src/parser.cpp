#include "parser.hpp"

binary_expr_tree
parser::
parse(const std::string& _expression) {
  // Parse and tokenize the expression according to the grammar in the header
  // file.
  for(auto sit = _expression.cbegin(); sit != _expression.cend(); ++sit) {
    // Skip whitespace.
    if(isspace(*sit))
      continue;
    // Parse parenthesis.
    // TODO: Ignore parenthesis for now. Add this support later.
    else if(*sit == '(' or *sit == ')')
      continue;
    // Parse various operators.
    else if(*sit == '^')
      m_tokens.push_back(token(token::exponent));
    else if(*sit == '*')
      m_tokens.push_back(token(token::multiply));
    else if(*sit == '/')
      m_tokens.push_back(token(token::divide));
    else if(*sit == '+')
      m_tokens.push_back(token(token::add));
    // NOTE: The subtact operator may be a unary operator indicating a negative
    // number.
    else if(*sit == '-')
      m_tokens.push_back(token(token::subtract));
    // If c is the start of a value (number or decimal point) parse the entire
    // number.
    else if(is_value(sit)) {
      const auto& token = parse_value(_expression, sit);

      m_tokens.push_back(token);

      // parse_value(...) moves sit one past the end of the value. Since this
      // for loop will increment sit once more we need to decrement it first so
      // we do not skip any characters or move sit past end().
      --sit;
    }
    else
      throw parse_error(_expression, sit, "Unknown symbol");
  }

  if(m_debug)
    std::cout << "Tokens: " << m_tokens << std::endl << std::endl;

  return binary_expr_tree(m_tokens, m_debug);
}


const token
parser::
parse_value(const std::string& _expression, SIT& _sit)
  const {
  // A number can only have one decimal point.
  bool decimal_point = *_sit == '.';

  std::string number = "";
  const auto start = _sit;

  // We have already checked the first character.
  ++_sit;

  // Find the end of the number.
  while(is_value(_sit) and _sit != _expression.cend()) {
    if(*_sit == '.') {
      if(decimal_point)
        throw parse_error(_expression, start, _sit, "Repeated decimal point");
      else
        decimal_point = true;
    }

    ++_sit;
  }

  const auto& value = std::string(start, _sit);

  if(value == ".")
    throw parse_error(_expression, start, "A lone decimal point is not a valid value");

  return token(token::number, std::stod(value));
}


const bool
parser::
is_value(const SIT& _sit) const {
  return isdigit(*_sit) or *_sit == '.';
}
