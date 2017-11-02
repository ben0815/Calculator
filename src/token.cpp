#include "token.hpp"


std::ostream&
operator<<(std::ostream& _os, const token& _token) {
  _os << '(' << _token.m_type << ", " << _token.m_symbol << ')';

  return _os;
}


std::ostream&
operator<<(std::ostream& _os, const token::type& _type) {
  if(_type == token::integer)
    _os << "integer";
  else if(_type == token::floating_point)
    _os << "floating_point";
  else if(_type == token::unary_operator)
    _os << "unary_operator";
  else if(_type == token::binary_operator)
    _os << "binary_operator";
  else if(_type == token::unknown)
    _os << "unknown";

  return _os;
}
