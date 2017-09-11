#include <iostream>
#include <string>

#include "calculator.hpp"

#define debug 1


int
main() {
  calculator calc;
  std::string line = "";

  // Loop forever, reading lines and sending them off to the calculator.
  while(true) {
    std::cout << " > ";
    std::getline(std::cin, line);

    if(line.empty())
      continue;

    if(debug)
      std::cout << "Read line: '" << line << "'" << std::endl;

    const auto& result = calc.calculate(line);

    std::cout << "   = " << result << std::endl;
  }

  return 0;
}
