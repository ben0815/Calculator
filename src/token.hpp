#ifndef TOKEN_HPP_
#define TOKEN_HPP_

#include <string>
#include <iostream>


class token {

  public:

    enum type {
      parenthesis,
      exponent,
      multiply,
      divide,
      add,
      subtract,
      number,
      unknown
    };

    token() {}

    token(type _type, const double& _value = 0) : m_type(_type), m_value(_value) {}

    ~token() {}

    const bool is_number() const;

    friend std::ostream& operator<<(std::ostream& _os, const token& _token);

    // Output operator to elegantly print the enum type.
    friend std::ostream& operator<<(std::ostream& _os, const type& _type);

  private:

    type m_type{unknown};

    // Value in the case where the token is a number (integer or floating
    // point).
    double m_value{0.};
};


#endif
