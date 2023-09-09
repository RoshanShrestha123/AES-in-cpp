#include <iostream>
#include <sstream>

std::string convert_string_to_hex(std::string input_str) {
  std::stringstream sso;
  for (int i = 0; i < input_str.length(); i++) {
    sso << std::hex << static_cast<int>(static_cast<char>(input_str[i]));
  }

  std::string string_hex = sso.str();
  return string_hex;
}

std::string convert_hex_to_string(std::string hex) {
  std::string ascii;
  for (int i = 0; i < hex.length(); i += 2) {
    std::string part = hex.substr(i, 2);
    char ch = std::stoul(part, nullptr, 16);
    ascii += ch;
  }

  return ascii;
}
