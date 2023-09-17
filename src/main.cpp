#include <cmath>
#include <iostream>
#include <string>

// TODO 5: Include MathFunctions.h
#include "HelloConfig.h"

int main(int argc, char* argv[])
{
  if (argc < 2) {
    // report version
    std::cout << argv[0] << " Version " << HelloProject_VERSION_MAJOR << "."
              << HelloProject_VERSION_MINOR << std::endl;
    std::cout << "Usage: " << argv[0] << " number" << std::endl;
    return 1;
  }

  // convert input to double
  const double inputValue = std::stod(argv[1]);

  // TODO 6: Replace sqrt with mathfunctions::sqrt

  // calculate square root
  const double outputValue = sqrt(inputValue);
  std::cout << "The square root of " << inputValue << " is " << outputValue
            << std::endl;
  return 0;
}
