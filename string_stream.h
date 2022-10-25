#ifndef CPPJOIN_STRING_STREAM_H_
#define CPPJOIN_STRING_STREAM_H_ 
#pragma once

#include <string>
#include <sstream>

template<typename It>
inline std::string string_stream_join(const std::string& sep, It beg, It end) {
  std::stringstream buf;
  buf << *beg;
  ++beg;
  for(; beg != end; ++beg) {
    buf << sep;
    buf << *beg;
  }
  return std::move(buf).str();
}

#endif // CPPJOIN_STRING_STREAM_H_
