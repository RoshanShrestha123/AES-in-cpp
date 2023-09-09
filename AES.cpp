#include <bitset>
#include <iostream>
#include <sstream>
#include <vector>

const int LMT_STATE_ARR = 16;  // byte

std::string convert_hex_to_string(std::string hex) {
  std::string ascii;
  for (int i = 0; i < hex.length(); i += 2) {
    std::string part = hex.substr(i, 2);
    char ch = std::stoul(part, nullptr, 16);
    ascii += ch;
  }

  return ascii;
}

std::string convert_string_to_hex(std::string input_str) {
  std::stringstream sso;
  std::string string_hex;
  std::string ascii;
  for (int i = 0; i < input_str.length(); i++) {
    sso << std::hex << (int)input_str[i];
  }
  sso >> string_hex;
  return string_hex;
}

void key_schedule_core(std::string key) {
  std::string hex_string = convert_string_to_hex(key);
  std::cout << hex_string << std::endl;
}

void generate_state_arr(std::string text, std::vector<char>& vec) {
  for (int i = 0; i < LMT_STATE_ARR; i++) {
    vec.push_back(text[i]);
  }
}

// implement xor
std::vector<char> xor_arr(std::vector<char>& vec1, std::vector<char>& vec2) {
  std::vector<char> xor_data;
  for (int i = 0; i < vec1.size(); i++) {
    xor_data.push_back(vec1[i] ^ vec2[i]);
  }

  return xor_data;
}

int main() {
  std::string input = "Hey this is a test";
  std::string key_128 = "abcdefghijklmnopqrstuvwxyz";

  key_schedule_core(key_128);

  // std::vector<char> value_state;
  // std::vector<char> round_key_state;

  // std::vector<char> round_key_1 = xor_arr(value_state, round_key_state);

  return 0;
}