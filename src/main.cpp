#include <iostream>
#include <string>
#include <stdexcept>

#include "calculator.hpp"
#include "error.hpp"


int
main(int _argc, char** _argv) {
  bool debug = false;

  // Check for debug option (-d or --debug).
  if(_argc > 1)
    for(size_t i = 1; i < _argc; ++i)
      if(std::string(_argv[i]) == "-d" or std::string(_argv[i]) == "--debug")
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
    try {
      result = calc.calculate(line);
    }
    catch (parse_error _pe) {
      std::cout << "Parse exception: " << _pe.what() << std::endl;
    }
    catch (std::runtime_error _re) {
      std::cout << "Runtime exception: " << _re.what() << std::endl;
    }

    std::cout << "   = " << result << std::endl;
  }

  return 0;
}
