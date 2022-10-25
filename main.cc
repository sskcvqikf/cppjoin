#include "string_sum.h"
#include "string_sum_prealloc.h"
#include "string_stream.h"
#include <iostream>
#include <vector>

#include "random.h"

#include <benchmark/benchmark.h>

std::vector<std::string> gen_input() {
  auto vec_sz = generate_len(100'000, 200'000);
  std::vector<std::string> inp(vec_sz);
  --vec_sz;
  for (; vec_sz != 0; --vec_sz) {
    auto str_sz = generate_len(5, 17);
    auto str = generate_string(str_sz);
    inp[vec_sz] = std::move(str);
  }
  return inp;
}

const auto data = gen_input();

static void SumStringJoinBench(benchmark::State& state) {
  for (auto _ : state) {
    auto ret = string_sum_join("----", data.cbegin(), data.cend());
    benchmark::DoNotOptimize(ret);
  }
}

BENCHMARK(SumStringJoinBench)->Iterations(500)->Unit(benchmark::kMicrosecond);

static void StringStringJoinBench(benchmark::State& state) {
  for (auto _ : state) {
    auto ret = string_stream_join("----", data.cbegin(), data.cend());
    benchmark::DoNotOptimize(ret);
  }
}

BENCHMARK(StringStringJoinBench)->Iterations(500)->Unit(benchmark::kMicrosecond);

static void SumStringPreallocJoinBench(benchmark::State& state) {
  for (auto _ : state) {
    auto ret = string_sum_prealloc_join("----", data.cbegin(), data.cend());
    benchmark::DoNotOptimize(ret);
  }
}

BENCHMARK(SumStringPreallocJoinBench)->Iterations(500)->Unit(benchmark::kMicrosecond);

BENCHMARK_MAIN();

