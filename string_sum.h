#ifndef CPPJOIN_STRING_SUM_H_
#define CPPJOIN_STRING_SUM_H_ 
#pragma once

#include <string>

template<typename It>
inline std::string string_sum_join(const std::string& sep, It beg, It end) {
  std::string ret;
  ret += *beg;
  ++beg;
  for(; beg != end; ++beg) {
    ret += sep;
    ret += *beg;
  }
  return ret;
}

#endif // CPPJOIN_STRING_SUM_H_
