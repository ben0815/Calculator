#ifndef TOKEN_HPP_
#define TOKEN_HPP_

#include <string>
#include <limits>
#include <iostream>


class token {

  public:

    // The ordering of these types is specific. It allows us to rank the token
    // according to PEMDAS.
    enum type {
      add,
      subtract,
      multiply,
      divide,
      exponent,
      parenthesis,
      number,
      unknown
    };

    token() {}

    token(type _type, const double& _value = std::numeric_limits<double>::max())
      : m_type(_type), m_value(_value) {}

    ~token() {}

    const double get_value() const;

    type get_type() const;

    const bool is_number() const;

    const bool is_operator() const;

    const bool operator<(const token& _other) const;

    operator std::string() const;

    static const std::string stringify(const token::type& _type);

    friend std::ostream& operator<<(std::ostream& _os, const token& _token);

    // Output operator to elegantly print the enum type.
    friend std::ostream& operator<<(std::ostream& _os, const type& _type);

  private:

    type m_type{unknown};

    // Value in the case where the token is a number (integer or floating
    // point).
    double m_value{std::numeric_limits<double>::max()};
};


#endif
