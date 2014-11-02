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

BENCHMARK_P(StringAppendBenchmark, Trivial, 10, 100,(std::size_t count))
{
    std::string res;
    char_generator next_char;
    for (size_t i=0; i<count; i++) {
    	res.append(next_char());
    }
    static std::size_t do_not_optimize_away=res.size();
}

BENCHMARK_P_INSTANCE(StringAppendBenchmark, Trivial, (1));
BENCHMARK_P_INSTANCE(StringAppendBenchmark, Trivial, (10));
BENCHMARK_P_INSTANCE(StringAppendBenchmark, Trivial, (100));
BENCHMARK_P_INSTANCE(StringAppendBenchmark, Trivial, (1000));
BENCHMARK_P_INSTANCE(StringAppendBenchmark, Trivial, (10000));
BENCHMARK_P_INSTANCE(StringAppendBenchmark, Trivial, (100000));
BENCHMARK_P_INSTANCE(StringAppendBenchmark, Trivial, (1000000));
BENCHMARK_P_INSTANCE(StringAppendBenchmark, Trivial, (4000000));

BENCHMARK_P(StringAppendBenchmark, StringStream, 10, 100,(std::size_t count))
{
    std::stringstream res;
    char_generator next_char;
    for (size_t i=0; i<count; i++) {
    	res << next_char();
    }
    static std::size_t do_not_optimize_away=res.str().size();
}

BENCHMARK_P_INSTANCE(StringAppendBenchmark, StringStream, (1));
BENCHMARK_P_INSTANCE(StringAppendBenchmark, StringStream, (10));
BENCHMARK_P_INSTANCE(StringAppendBenchmark, StringStream, (100));
BENCHMARK_P_INSTANCE(StringAppendBenchmark, StringStream, (1000));
BENCHMARK_P_INSTANCE(StringAppendBenchmark, StringStream, (10000));
BENCHMARK_P_INSTANCE(StringAppendBenchmark, StringStream, (100000));
BENCHMARK_P_INSTANCE(StringAppendBenchmark, StringStream, (1000000));
BENCHMARK_P_INSTANCE(StringAppendBenchmark, StringStream, (4000000));

BENCHMARK_P(StringAppendBenchmark, ReserveAppendString, 10, 100,(std::size_t count))
{
    std::string res;
    res.reserve(count);
    char_generator next_char;
    for (size_t i=0; i<count; i++) {
    	res.append(next_char());
    }
    static std::size_t do_not_optimize_away=res.size();
}

BENCHMARK_P_INSTANCE(StringAppendBenchmark, ReserveAppendString, (1));
BENCHMARK_P_INSTANCE(StringAppendBenchmark, ReserveAppendString, (10));
BENCHMARK_P_INSTANCE(StringAppendBenchmark, ReserveAppendString, (100));
BENCHMARK_P_INSTANCE(StringAppendBenchmark, ReserveAppendString, (1000));
BENCHMARK_P_INSTANCE(StringAppendBenchmark, ReserveAppendString, (10000));
BENCHMARK_P_INSTANCE(StringAppendBenchmark, ReserveAppendString, (100000));
BENCHMARK_P_INSTANCE(StringAppendBenchmark, ReserveAppendString, (1000000));
BENCHMARK_P_INSTANCE(StringAppendBenchmark, ReserveAppendString, (4000000));
