// Requires Google Benchmark: https://github.com/google/benchmark
// g++ cpp9-01-constexpr-compile-time.cpp -std=c++2a -isystem benchmark/include -Lbenchmark/build/src -lbenchmark -lpthread -O0 -o cpp9-01

#include <benchmark/benchmark.h>
#include <unistd.h>

#include <fstream>
#include <iostream>

namespace {
// This is to clear the cache.
void flush() {
    sync();
    std::ofstream ofs("/proc/sys/vm/drop_caches");
    ofs << "3" << std::endl;
}
}  // namespace

constexpr unsigned factorial(unsigned n) { return n <= 1 ? 1 : (n * factorial(n - 1)); }

// Pre C++20 solution to force compile time programming.
template <unsigned n>
struct force_compile_time {
    force_compile_time() {}
};

static void BM_factorial_compile_time_100(benchmark::State& state) {
    flush();
    constexpr int a = 100;
    for (auto _ : state) {
        force_compile_time<factorial(a)> cf;
    }
    flush();
}

static void BM_factorial_compile_time_245(benchmark::State& state) {
    flush();
    constexpr int a = 245;
    for (auto _ : state) {
        force_compile_time<factorial(a)> cf;
    }
    flush();
}

static void BM_factorial_compile_time_512(benchmark::State& state) {
    flush();
    constexpr int a = 512;
    for (auto _ : state) {
        force_compile_time<factorial(a)> cf;
    }
    flush();
}

BENCHMARK(BM_factorial_compile_time_100);
BENCHMARK(BM_factorial_compile_time_245);
BENCHMARK(BM_factorial_compile_time_512);
BENCHMARK_MAIN();
