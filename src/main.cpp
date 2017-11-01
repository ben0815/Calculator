#include <iostream>
#include <string>

#include "calculator.hpp"


int
main(int argc, char** argv) {
  bool debug = false;

  // Check for debug option (-d or --debug).
  if(argc > 1)
    for(size_t i = 1; i < argc; ++i)
      if(std::string(argv[i]) == "-d" or std::string(argv[i]) == "--debug")
        debug = true;

  calculator calc(debug);

  std::string line = "";

  // Loop forever, reading lines and sending them off to the calculator.
  for(;;) {
    std::cout << " > ";
    std::getline(std::cin, line);

    if(line.empty())
      continue;

    if(debug)
      std::cout << "Read line: '" << line << "'" << std::endl;

    double result = 0.;

    // Try to calculate the input expression.
    try {
      result = calc.calculate(line);
    }
    catch (parse_error _pe) {
      std::cout << "Parse error: " << _pe.what() << std::endl;
    }

    std::cout << "   = " << result << std::endl;
  }

  return 0;
}
