#include "../src/Tensor/Tensor.cpp"
#include "Test.hpp"
#include <stdfloat>
#include <tuple>
#include <span>

using namespace std::literals::string_literals;
using cayley::Tensor::Tensor;
using std::bfloat16_t;
using std::float128_t;
using std::span;
using std::tuple;
using std::vector;

vector<UnitTest> checkScalarTest();
vector<UnitTest> checkVector1Test();
// vector<UnitTest> checkVector2Test();
// vector<UnitTest> checkMatrixTest();
// vector<UnitTest> checkMixedTest();

// vector<UnitTest> checkAddTest();
// vector<UnitTest> checkSubTest();
// vector<UnitTest> checkMulTest();
// vector<UnitTest> checkDivTest();
// vector<UnitTest> checkPowTest();
// vector<UnitTest> checkDotTest();
// vector<UnitTest> checkCrossTest();
// vector<UnitTest> checkOuterTest();
// vector<UnitTest> checkTransposeTest();

vector<UnitTest> checkScalarTest()
{
    vector<UnitTest> results;

    auto addTest = [&results]<typename T>(tuple<string, T> unit) -> void
    {
        auto testName = get<string>(unit);
        auto value    = get<T>(unit);
        
        bool test1, test2, test3;

        Tensor<T> tensor;

        test1 = tensor.IsScalar();
        test2 = tensor.Data().size() == 1 && tensor.Data()[0] == 0;

        auto t1 = Tensor<T>(value);
        test3 = t1.Data().size() == 1 && t1.Data()[0] == value;


        results.emplace_back(test1, testName + " uniqueness");
        results.emplace_back(test2, testName + " default value");
        results.emplace_back(test3, testName + " assigment");

        results.emplace_back(test1 && test2 && test3, testName);
    };

    
    tuple intScalar         = {"Int Scalar"s,        -120};
    tuple floatScalar       = {"Float Scalar"s,      85.9f};
    tuple doubleScalar      = {"Double Scalar"s,     32.234};
    tuple float128Scalar    = {"Float128 Scalar"s,   -19.0304f128};
    tuple brainFloatScalar  = {"BrainFloat Scalar"s, 1.01bf16};

    addTest(intScalar);
    addTest(floatScalar);
    addTest(doubleScalar);
    addTest(float128Scalar);
    addTest(brainFloatScalar);

    return results;
}

vector<UnitTest> checkVector1Test()
{
    // vector<UnitTest> results;

    // vector<size_t> dims{21};

    // Tensor doubleVector({32});
    // Tensor<float> FloatVector(dims);
    // Tensor<int> IntVector({12});
    // Tensor<float128_t> Float128Vector(span(dims));
    // Tensor<bfloat16_t> BrainFloatVector;

    
    return {};
}
// vector<UnitTest> checkMatrixTest();
// vector<UnitTest> checkMixedTest();

// vector<UnitTest> checkAddTest();
// vector<UnitTest> checkSubTest();
// vector<UnitTest> checkMulTest();
// vector<UnitTest> checkDivTest();
// vector<UnitTest> checkPowTest();
// vector<UnitTest> checkDotTest();
// vector<UnitTest> checkCrossTest();
// vector<UnitTest> checkOuterTest();
// vector<UnitTest> checkTransposeTest();