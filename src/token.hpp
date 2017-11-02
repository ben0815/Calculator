#ifndef TOKEN_HPP_
#define TOKEN_HPP_

#include <string>
#include <iostream>


class token {

  public:

    enum type {
      integer,
      floating_point,
      unary_operator,
      binary_operator,
      unknown
    };

    token() {}

    token(type _type, const std::string& _symbol)
      : m_type(_type), m_symbol(_symbol) {}

    ~token() {}

    friend std::ostream& operator<<(std::ostream& _os, const token& _token);

    // Output operator to elegantly print the enum type.
    friend std::ostream& operator<<(std::ostream& _os, const type& _type);

  private:

    type m_type{unknown};

    std::string m_symbol = "";
};


#endif
