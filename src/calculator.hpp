#ifndef CALCULATOR_HPP_
#define CALCULATOR_HPP_


#include <string>


class calculator {

  public:

    calculator() {}

    ~calculator() {}

    template<typename T>
    const T calculate(const std::string _expression);

  private:


};


#endif
