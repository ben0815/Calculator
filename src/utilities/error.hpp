#ifndef ERROR_HPP_
#define ERROR_HPP_

#include <stdexcept>
#include <string>

// Parse error class so that we can throw specific errors while parsing expressions.
class parse_error : public std::runtime_error {

  public:

    explicit parse_error(const std::string& _where, const std::string& _what)
      : std::runtime_error("Parse Error.\nWhere: " + _where + "\nWhat: " \
          + _what + "\n") {}

    // Report error for specific character in an expression.
    explicit parse_error(const std::string& _expression,
        const std::string::const_iterator _sit, const std::string& _what)
      : std::runtime_error("\nWhere: character '" + std::string(1, *_sit) +
          "' in expression '" + _expression + "'\nWhat: " + _what + "\n") {}

};


#endif
