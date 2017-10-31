#include <stdexcept>
#include <string>

// Parse error class so that we can throw errors while parsing expressions.
class parse_error : public std::runtime_error {

  public:

    explicit parse_error(const std::string& _where, const std::string& _what)
      : std::runtime_error("Parse Error.\nWhere: " + _where + "\nWhat: " \
          + _what + "\n") {}
};
