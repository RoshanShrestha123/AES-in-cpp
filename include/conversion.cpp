#include <iostream>
#include <sstream>

std::string convert_string_to_hex(std::string input_str) {
  std::stringstream sso;
  for (char c : input_str) {
    sso << std::hex << int(c);
  }

  std::string string_hex = sso.str();
  return string_hex;
}

std::string convert_hex_to_string(std::string hex) {
  std::string ascii;
  for (int i = 0; i < hex.length(); i += 2) {
    std::string _part = hex.substr(i, 2);
    char ch = std::stoul(_part, nullptr, 16);
    ascii += ch;
  }

  return ascii;
}
