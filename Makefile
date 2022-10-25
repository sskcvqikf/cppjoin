run: build
	./main

build: main.cc string_sum.h string_stream.h string_sum_prealloc.h random.h
	${CXX} -lbenchmark --std=c++20 -O3 main.cc -o main


