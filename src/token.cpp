#include "token.hpp"


std::ostream&
operator<<(std::ostream& _os, const token& _token) {
  if(_token.is_number())
    _os <<  _token.m_value;
  else
    _os << _token.m_type;

  return _os;
}


std::ostream&
operator<<(std::ostream& _os, const token::type& _type) {
  _os << token::stringify(_type);

  return _os;
}


const double
token::
get_value() const {
  return m_value;
}


token::type
token::
get_type() const {
  return m_type;
}


const bool
token::
is_number() const {
  return m_type == token::number;
}


const bool
token::
is_operator() const {
  return !this->is_number();
}


const bool
token::
operator<(const token& _other) const {
  return m_type < _other.m_type;
}


token::
operator std::string() const {
  // Check if this token is a value or an operator.

  // Operator
  if(m_value == std::numeric_limits<double>::max())
    return stringify(this->m_type);

  // Value
  return std::to_string(m_value);
}


const std::string
token::
stringify(const token::type& _type) {
  if(_type == token::parenthesis)
    return "parenthesis";
  else if(_type == token::exponent)
    return "exponent";
  else if(_type == token::multiply)
    return "multiply";
  else if(_type == token::divide)
    return "divide";
  else if(_type == token::add)
    return "add";
  else if(_type == token::subtract)
    return "subtract";
  else if(_type == token::number)
    return "number";
  else if(_type == token::unknown)
    return "unknown";

  return "";
}
