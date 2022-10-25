#ifndef CPPJOIN_STRING_SUM_PREALLOC_H_
#define CPPJOIN_STRING_SUM_PREALLOC_H_ 
#pragma once

#include <string>

template<typename It>
inline std::string string_sum_prealloc_join(const std::string& sep, It beg, It end) {
  auto ret_sz = 0;
  
  for(auto it = beg; it != end; ++it) {
    ret_sz += it->size() + sep.size();
  }

  std::string ret;
  ret.reserve(ret_sz + 1);

  ret += *beg;
  ++beg;
  for(; beg != end; ++beg) {
    ret += sep;
    ret += *beg;
  }
  return ret;
}

#endif // CPPJOIN_STRING_SUM_PREALLOC_H_
