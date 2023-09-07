#include <bitset>
#include <iostream>
#include <vector>

const int LMT_STATE_ARR = 16;  // byte

void generate_state_arr(std::string text, std::vector<char>& vec) {
  for (int i = 0; i < LMT_STATE_ARR; i++) {
    vec.push_back(text[i]);
  }
}

void printArr(char arr[LMT_STATE_ARR]) {
  for (int i = 0; i < LMT_STATE_ARR; i++) {
    std::cout << arr[i];
  }
}

int main() {
  std::string input = "Hey this is a test";
  std::string key_128 = "aaaaaaaaaaaaaaaa";

  std::vector<char> value_state;
  std::vector<char> round_key_state;

  return 0;
}