# cppjoin
Small performance comparison of different ways of string joining in C++.

# Run
`make`

### Using `std::string::operator+`. string_sum.h (SumStringJoinBench)
Simply create an empty string and complete join by adding string with `operator+`.

### Using `std::stringstream`. string_stream.h (StringStringJoinBench)
Most conventional "C++"-way. Simply use `operator<<` with `std::stringstream`. 

### Using `std::string::operator+` with preallocating. string_sum_prealloc.h (SumStringPreallocJoinBench)
Just like first approach, but before the actual join, calculate the size of the resulting string, and reserve this space,
so that there will be no reallocations.

### Using `std::string::append`. string_append.h (StringAppendJoinBench)
Turned out, very effective.

## Results
```bash
Run on (12 X 4056.45 MHz CPU s)
CPU Caches:
  L1 Data 32 KiB (x6)
  L1 Instruction 32 KiB (x6)
  L2 Unified 512 KiB (x6)
  L3 Unified 4096 KiB (x2)
Load Average: 1.76, 1.68, 1.60
***WARNING*** CPU scaling is enabled, the benchmark real time measurements may be noisy and will incur extra overhead.
------------------------------------------------------------------------------------
Benchmark                                          Time             CPU   Iterations
------------------------------------------------------------------------------------
SumStringJoinBench/iterations:500               3817 us         3803 us          500
StringStringJoinBench/iterations:500            6802 us         6779 us          500
SumStringPreallocJoinBench/iterations:500       2397 us         2390 us          500                                                                                                    
StringAppendJoinBench/iterations:500            2483 us         2475 us          500
```

# Conclusion
`std::stringstream` is bad for your perfomance.
