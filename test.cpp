#include "src/Tensor/Tensor.cpp"
#include <functional>
#include <assert.h>
#include <vector>
#include <string>
#include <tuple>
#include <print>

#ifndef _GLIBCXX_STDFLOAT
cout << "GLIBCXX_STDFLOAT is not defined" << endl;
static_assert(false);
#endif

using cayley::Tensor::Tensor;
using std::bfloat16_t;
using std::float128_t;
using std::function;
using std::print;
using std::println;
using std::string;
using std::tuple;
using std::vector;

struct Test
{
    bool result;
    string name;
};

struct MajorTest
{
    vector<Test> (*majorTest)();
    string name;
};

vector<Test> checkScalarTest();
// vector<Test> checkVectorTest();
// vector<Test> checkMatrixTest();
// vector<Test> checkMixedTest();

// vector<Test> checkAddTest();
// vector<Test> checkSubTest();
// vector<Test> checkMulTest();
// vector<Test> checkDivTest();
// vector<Test> checkPowTest();
// vector<Test> checkDotTest();
// vector<Test> checkCrossTest();
// vector<Test> checkOuterTest();
// vector<Test> checkTransposeTest();

int main()
{

    MajorTest AllTests[] = {
        {checkScalarTest, "Scalar Tests"},
    };
    const string stringOK = "\033[32mOK  ";
    const string stringBAD = "\033[91mBAD ";







    for (auto [majorTest, majorTestName] : AllTests)
    {
        println("\033[33mMajor Test: {}", majorTestName);

        for (auto [result, name] : majorTest())
            println("\t{} \033[90m{}", result ? stringOK : stringBAD, name);

        print("\033[0m");
    }

    return 0;
}

vector<Test> checkScalarTest()
{
    vector<Test> results;

    Tensor scalar1;
    Tensor<float> scalarFloat;
    Tensor<int> scalarInt;
    Tensor<float128_t> scalarFloat128;
    Tensor<bfloat16_t> scalarBrainFloat;

    auto checkScalar = [&results]<typename T>(const Tensor<T> &tensor, const string &name)
    {
        results.emplace_back(tensor.Data().size() == 1, name);
    };

    checkScalar(scalar1, "Default Scalar Tensor");
    checkScalar(scalarFloat, "Float Scalar Tensor");
    checkScalar(scalarInt, "Int Scalar Tensor");
    checkScalar(scalarFloat128, "Float128 Scalar Tensor");
    checkScalar(scalarBrainFloat, "BrainFloat Scalar Tensor");

    return results;
}
