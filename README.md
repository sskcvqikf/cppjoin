# cppjoin
Small performance comparison of different ways of string joining in C++.

# Run
`make`

### Using `std::string::operator+`. string_sum.h
Simply create an empty string and complete join by adding string with `operator+`.

### Using `std::stringstream`. string_stream.h
Most conventional "C++"-way. Simply use `operator<<` with `std::stringstream`. 

### Using `std::string::operator+` with preallocating. string_sum_prealloc.h
Just like first approach, but before the actual join, calculate the size of the resulting string, and reserve this space,
so that there will be no reallocations.

## Results
```bash
CPU Caches:
  L1 Data 32 KiB (x6)
  L1 Instruction 32 KiB (x6)
  L2 Unified 512 KiB (x6)
  L3 Unified 4096 KiB (x2)
Load Average: 1.45, 1.44, 1.43
***WARNING*** CPU scaling is enabled, the benchmark real time measurements may be noisy and will incur extra overhead.
------------------------------------------------------------------------------------
Benchmark                                          Time             CPU   Iterations
------------------------------------------------------------------------------------
SumStringJoinBench/iterations:500               3615 us         3589 us          500
StringStringJoinBench/iterations:500            6554 us         6507 us          500
SumStringPreallocJoinBench/iterations:500       2230 us         2216 us          500
```

# Conclusion
`std::stringstream` is bad for your perfomance.
