#ifndef CPPJOIN_STRING_APPEND_H_
#define CPPJOIN_STRING_APPEND_H_ 
#pragma once

#include <string>

template<typename It>
inline std::string string_append_join(const std::string& sep, It beg, It end) {
  std::string ret;
  ret.append(*beg);
  ++beg;
  for(; beg != end; ++beg) {
    ret.append(sep);
    ret.append(*beg);
  }
  return ret;
}

#endif // CPPJOIN_STRING_APPEND_H_
