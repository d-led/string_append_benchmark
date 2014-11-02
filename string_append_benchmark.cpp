#include <hayai.hpp>

#include <string>
#include <sstream>

class char_generator {
    char pos;
public:
    char_generator():pos(32){}

    std::string operator()() {
        char res = pos;
        if (pos>=126)
            pos = 32;
        else
            pos++;
        return std::string(2,pos);
    }
};

struct StringAppendBenchmark : public ::hayai::Fixture {
    char_generator next_char;
    std::string str;
    std::stringstream ss;
};

BENCHMARK_P_F(StringAppendBenchmark, Trivial, 10, 100,(std::size_t count))
{
    for (size_t i=0; i<count; i++) {
        str.append(next_char());
    }
    static std::size_t do_not_optimize_away=str.size();
}

BENCHMARK_P_INSTANCE(StringAppendBenchmark, Trivial, (1));
BENCHMARK_P_INSTANCE(StringAppendBenchmark, Trivial, (10));
BENCHMARK_P_INSTANCE(StringAppendBenchmark, Trivial, (100));
BENCHMARK_P_INSTANCE(StringAppendBenchmark, Trivial, (1000));
BENCHMARK_P_INSTANCE(StringAppendBenchmark, Trivial, (10000));
BENCHMARK_P_INSTANCE(StringAppendBenchmark, Trivial, (100000));
BENCHMARK_P_INSTANCE(StringAppendBenchmark, Trivial, (1000000));
BENCHMARK_P_INSTANCE(StringAppendBenchmark, Trivial, (4000000));

BENCHMARK_P_F(StringAppendBenchmark, StringStream, 10, 100, (std::size_t count))
{
    for (size_t i=0; i<count; i++) {
        ss << next_char();
    }
    static std::size_t do_not_optimize_away=ss.str().size();
}

BENCHMARK_P_INSTANCE(StringAppendBenchmark, StringStream, (1));
BENCHMARK_P_INSTANCE(StringAppendBenchmark, StringStream, (10));
BENCHMARK_P_INSTANCE(StringAppendBenchmark, StringStream, (100));
BENCHMARK_P_INSTANCE(StringAppendBenchmark, StringStream, (1000));
BENCHMARK_P_INSTANCE(StringAppendBenchmark, StringStream, (10000));
BENCHMARK_P_INSTANCE(StringAppendBenchmark, StringStream, (100000));
BENCHMARK_P_INSTANCE(StringAppendBenchmark, StringStream, (1000000));
BENCHMARK_P_INSTANCE(StringAppendBenchmark, StringStream, (4000000));

BENCHMARK_P_F(StringAppendBenchmark, ReserveAppendString, 10, 100, (std::size_t count))
{
    str.reserve(count);
    for (size_t i=0; i<count; i++) {
        str.append(next_char());
    }
    static std::size_t do_not_optimize_away=str.size();
}

BENCHMARK_P_INSTANCE(StringAppendBenchmark, ReserveAppendString, (1));
BENCHMARK_P_INSTANCE(StringAppendBenchmark, ReserveAppendString, (10));
BENCHMARK_P_INSTANCE(StringAppendBenchmark, ReserveAppendString, (100));
BENCHMARK_P_INSTANCE(StringAppendBenchmark, ReserveAppendString, (1000));
BENCHMARK_P_INSTANCE(StringAppendBenchmark, ReserveAppendString, (10000));
BENCHMARK_P_INSTANCE(StringAppendBenchmark, ReserveAppendString, (100000));
BENCHMARK_P_INSTANCE(StringAppendBenchmark, ReserveAppendString, (1000000));
BENCHMARK_P_INSTANCE(StringAppendBenchmark, ReserveAppendString, (4000000));
