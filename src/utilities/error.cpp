#include "error.hpp"


const std::string
parse_error::
format(const SIT& _sit, const std::string& _expression) const {
  // Since both the iterator and the _expression string are const we cannot
  // modify either of them, so we need a copy of each.
  std::string error = _expression;
  auto eit = error.begin() + std::distance(_expression.cbegin(), _sit);

  error.insert(eit, {' ', '{'});
  error.insert(eit + 3, {'}', ' '});

  return error;
}


const std::string
parse_error::
highlight(const SIT& _start, const SIT& _end, const std::string& _expression)
  const {

  return "";
}
