#ifndef CPPJOIN_RANDOM_H_
#define CPPJOIN_RANDOM_H_ 
#pragma once

#include <string>
#include <algorithm>
#include <random>
#include <ctime>

static constexpr const char* DEFAULT_CHARSET = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
static std::default_random_engine random_engine{static_cast<unsigned>(time(0))};
static std::mt19937 random_generator(random_engine());

inline std::string generate_string(size_t length) {
  std::string str = DEFAULT_CHARSET;

	while(length > str.length()) str += str;

	std::shuffle(str.begin(), str.end(), random_generator);

	return str.substr(0, length);
}

inline size_t generate_len(int from, int to)
{
  std::uniform_int_distribution<std::mt19937::result_type> dist(from, to);
  return dist(random_generator);
}

#endif // CPPJOIN_RANDOM_H_
