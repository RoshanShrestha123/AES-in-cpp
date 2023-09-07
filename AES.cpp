#include <bitset>
#include <iostream>
#include <vector>

const int LMT_STATE_ARR = 16;  // byte

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
  std::string key_128 = "aaaaaaaaaaaaaaaa";

  std::vector<char> value_state;
  std::vector<char> round_key_state;

  std::vector<char> round_key_1 = xor_arr(value_state, round_key_state);

  return 0;
}