#include <stdint.h>

#include <bitset>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <vector>

#include "include/conversion.h"

const int LMT_STATE_ARR = 16;  // byte

/**
 * Main Key schedule core module for creating the round_key [0 - 10]
 * Takes the 128 bit & converts to the 44w (each w -> 32bit)
 *
 * @param key
 * @return
 */
void key_schedule_core(std::string key) {
  std::string converted_key_hex = convert_string_to_hex(key);

  std::vector<std::string> chunk_words;
  for (int i = 0; i < converted_key_hex.length(); i += 8) {
    std::string string_chunk = converted_key_hex.substr(i, 8);
    chunk_words.push_back(string_chunk);
    std::cout << string_chunk << "-> w" << std::endl;
  }

  std::vector<std::string> sub_chunk_words;
  for (std::string word : chunk_words) {
    std::string sub_word;

    for (int i = 0; i < word.length(); i += 2) {
      std::string part_hex = word.substr(i, 2);
      int s_index;
      std::stringstream ss(part_hex);
      ss >> std::hex >> s_index;

      std::cout << part_hex << " = ";

      std::cout << std::hex << s_box[s_index] << std::endl;
    }
  }

  // for (std::string chunk : sub_chunk_words) {
  //   std::cout << chunk << "-> s_w" << std::endl;
  // }
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
  std::string key_128 = "abcdefghijklmnop";

  std::cout << "Key Scheduler started....." << std::endl;
  std::cout << std::setfill('-') << std::setw(20) << "" << std::endl;
  key_schedule_core(key_128);
  return 0;
}