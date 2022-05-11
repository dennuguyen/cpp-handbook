// Requires Google Benchmark: https://github.com/google/benchmark
// g++ cpp9-02-constexpr-run-time.cpp -std=c++2a -isystem benchmark/include -Lbenchmark/build/src -lbenchmark -lpthread -O0 -o cpp9-02

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

unsigned factorial(unsigned n) { return n <= 1 ? 1 : (n * factorial(n - 1)); }

static void BM_factorial_run_time(benchmark::State& state) {
    flush();
    volatile int a = state.range(0);
    for (auto _ : state) {
        factorial(a);
    }
    flush();
}

BENCHMARK(BM_factorial_run_time)->Arg(100);
BENCHMARK(BM_factorial_run_time)->Arg(245);
BENCHMARK(BM_factorial_run_time)->Arg(512);
BENCHMARK_MAIN();
