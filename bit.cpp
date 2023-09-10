#include <stdint.h>

#include <iomanip>
#include <iostream>
#include <sstream>
#include <vector>

int main() {
  // asking for the Hex string from user
  std::string input1;
  std::string input2;

  std::cout << "Please enter HEX string (1-F): " << std::endl;
  std::cin >> input1;

  std::stringstream ss;
  for (char c : input1) {
    ss << std::hex << (int)c;
  }

  std::string result = ss.str();
  std::cout << "String to HEX=  " << result << std::endl;

  // hex to original value
  std::string ascii;
  for (int i = 0; i < result.length(); i += 2) {
    std::string chunk = result.substr(i, 2);
    char c = std::stol(chunk, nullptr, 16);
    ascii += c;
  }

  std::cout << "Hex back to string=" << ascii << std::endl;
}