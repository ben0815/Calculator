#ifndef ERROR_HPP_
#define ERROR_HPP_

#include <stdexcept>
#include <string>
#include <iostream>

// Parse error class so that we can throw specific errors while parsing expressions.
class parse_error : public std::runtime_error {

  typedef std::string::const_iterator SIT;

  public:

    explicit parse_error(const std::string& _where, const std::string& _what)
      : std::runtime_error("Parse Error.\nWhere: " + _where + "\nWhat: " \
          + _what + "\n") {}

    // Report error for specific character in an expression.
    explicit parse_error(const std::string& _expression, const SIT& _sit,
        const std::string& _what)
      : std::runtime_error("\nWhere: character '" + std::string(1, *_sit) +
          "' in expression '" + format(_sit, _expression) + "'.\nWhat: "
          + _what + ".\n") {}

    // Report error for specific substring in an expression.
    explicit parse_error(const std::string& _expression, const SIT _start,
        const SIT _end, const std::string& _what)
      : std::runtime_error("\nWhere: '" + std::string(_start, _end) +
          "' in expression '" + format(_start, _end, _expression) +
          "'.\nWhat: " + _what + ".\n") {}

  private:

    // Place ' { } ' around a character pointed to by _sit. Used to indicate the
    // portion of a string which contains an error.
    // Also, if the _expression is large cut it off after the error portion.
    const std::string format(const SIT& _sit, const std::string& _expression)
      const;

    // Same as above, but wraps a substring in ' { } '.
    const std::string format(const SIT& _start, const SIT& _end,
        const std::string& _expression)
      const;


};


#endif
