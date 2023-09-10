#include <stdint.h>

#include <bitset>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <vector>

#include "include/helpers.h"

const int LMT_STATE_ARR = 16;  // byte
std::string substitute_word_s_box(std::string word) {
  std::string result;

  for (int i = 0; i < word.length(); i += 2) {
    std::string ascii;
    std::string part_hex = word.substr(i, 2);
    char s_index = std::stol(part_hex, nullptr, 16);

    std::stringstream ss;
    ss << std::hex << s_box[s_index];
    ss >> ascii;
    result += ascii;
  }

  return result;
}

void key_schedule_core(std::string key) {
  std::string converted_key_hex = convert_string_to_hex(key);

  std::vector<std::string> chunk_words;
  for (int i = 0; i < converted_key_hex.length(); i += 8) {
    std::string string_chunk = converted_key_hex.substr(i, 8);
    chunk_words.push_back(string_chunk);
  }

  std::vector<std::string> sub_chunk_words;
  for (std::string word : chunk_words) {
    sub_chunk_words.push_back(substitute_word_s_box(word));
  }

  print_header("First 4 words");
  for (std::string chunk : chunk_words) {
    std::cout << chunk << " " << std::endl;
  }

  print_header("Words sub is created");
  for (std::string chunk : sub_chunk_words) {
    std::cout << chunk << " " << std::endl;
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
  std::string key_128 = "1wX8p$B*Q@vK#7Yz";

  print_header("Debunk AES encryption process!", false);

  std::cout << "TESTING KEY = <" << key_128 << '>' << std::endl;

  print_header("Starting Key Schedular process...");
  key_schedule_core(key_128);
  return 0;
}