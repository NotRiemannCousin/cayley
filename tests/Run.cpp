#include "Test.cpp"
#include <assert.h>
#include <vector>
#include <string>
#include <print>
#include <tuple>

#ifndef _GLIBCXX_STDFLOAT
static_assert(false && "GLIBCXX_STDFLOAT is not defined\n");
#endif

using namespace std::literals::string_literals;
using std::println;
using std::print;
using std::string;

int main()
{
    MainTest MainTests[] = {
        IntScalarTest(),
        FloatScalarTest(),
        DoubleScalarTest(),
        Float128ScalarTest(),
        BrainFloatScalarTest(),
    };

    const auto YELLOW  = "\e[33m"s;
    const auto GREEN   = "\e[32m"s;
    const auto GRAY    = "\e[90m"s;
    const auto RED     = "\e[91m"s;
    const auto CLEAR   = "\e[0m"s;

    const string stringOK  = GREEN + "OK  " + CLEAR;
    const string stringBAD = RED   + "BAD " + CLEAR;



    for (auto const &[runMainTest, testName] : MainTests)
    {
        println("{}Main UnitTest: {}", YELLOW, testName);

        for (auto unit : runMainTest())
        {
            
            println("\t{} {}", unit.result ? stringOK : stringBAD,
                    GRAY + unit.name);
        }

        println("{}", CLEAR);
    }

    return 0;
}