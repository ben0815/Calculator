#include "token.hpp"


std::ostream&
operator<<(std::ostream& _os, const token& _token) {
  if(_token.is_number())
    _os << '(' << _token.m_type << ", " << _token.m_value << ')';
  else
    _os << _token.m_type;

  return _os;
}


std::ostream&
operator<<(std::ostream& _os, const token::type& _type) {
  if(_type == token::parenthesis)
    _os << "parenthesis";
  else if(_type == token::exponent)
    _os << "exponent";
  else if(_type == token::multiply)
    _os << "multiply";
  else if(_type == token::divide)
    _os << "divide";
  else if(_type == token::add)
    _os << "add";
  else if(_type == token::subtract)
    _os << "subtract";
  else if(_type == token::number)
    _os << "number";
  else if(_type == token::unknown)
    _os << "unknown";

  return _os;
}


const bool
token::
is_number() const {
  return m_type == token::number;
}


const bool
token::
operator<(const token& _other) const {
  return m_type < _other.m_type;
}
