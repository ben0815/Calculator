#ifndef UTILITIES_HPP_
#define UTILITIES_HPP_

#include <iostream>
#include <string>
#include <vector>


class utilities {

  public:

    utilities() {}

    ~utilities() {}

    // T must have a '<<' operator.
    template<class T>
    friend std::ostream& operator<<(std::ostream& _os,
        std::vector<T> _vec);

  private:

};


template<class T>
std::ostream&
operator<<(std::ostream& _os, const std::vector<T>& _vec) {
  _os << "(size: " << _vec.size() << ") [ ";

  for(auto it = _vec.cbegin(); it != _vec.cend(); ++it) {
    _os << *it;

    if(it != _vec.cend() - 1)
      _os << ", ";
  }

  _os << " ]";

  return _os;
}


#endif
