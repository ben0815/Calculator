#include "parser.hpp"

const binary_expr_tree<token>*
parser::
parse(const std::string& _expression) {
  // Parse and tokenize the expression according to the grammar in the header
  // file.
  for(auto sit = _expression.cbegin(); sit != _expression.cend(); ++sit) {
    // Skip whitespace.
    if(isspace(*sit))
      continue;
    else if(*sit == '(' or *sit == ')')
      continue;
    // If c is the start of a value (number or decimal point) parse the entire
    // number.
    else if(is_value(sit)) {
      const auto& token = parse_value(_expression, sit);

      m_tokens.push_back(token);

      --sit;
    }
    // Check if the character is a unary operator ('-' as in '-5').
    else if(*sit == '-' and (sit == _expression.cbegin() or !is_value(sit - 1))) {
      m_tokens.push_back(token(token::unary_operator,
            std::string(1, *sit)));
    }
    // Check for binary operators.
    else if(is_binary_operator(_expression, sit)) {
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

  token::type type = token::integer;
  if(decimal_point)
    type = token::floating_point;

  const auto& value = std::string(start, _sit);

  if(value == ".")
    throw parse_error(_expression, start, "A lone decimal point is not a valid value");

  return token(type, value);
}


const bool
parser::
is_value(const SIT& _sit) const {
  return isdigit(*_sit) or *_sit == '.';
}


const bool
parser::
is_operator(const SIT& _sit) const {
  // Do not check for '-' since this is used when validating a binary operator
  // and '-' can come directly after a binary operator (e.g. 4+-3 = 1).
  return *_sit == '+' or *_sit == '*' or *_sit == '/' or *_sit == '^';
}


const bool
parser::
is_binary_operator(const std::string& _expression, const SIT& _sit) const {
  const bool oper = is_operator(_sit) or *_sit == '-';

  if(oper) {
    if(_sit == _expression.cbegin() or _sit == _expression.cend() - 1)
      throw parse_error(_expression, _sit,
          "A binary operator cannot be at the beginning or end of an expression");
    else if(is_operator(_sit + 1))
      throw parse_error(_expression, _sit, _sit + 1, "Repeated binary operators");
  }

  return oper;
}
