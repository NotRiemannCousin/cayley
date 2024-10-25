#include "../../../src/Tensor/Tensor.cpp"
#include "../../Test.hpp"
#include <stdfloat>

using namespace std::literals::string_literals;
using cayley::Tensor::Tensor;
using std::bfloat16_t;
using std::float128_t;

template<typename T>
static vector<UnitTest> checkScalarTest(const string testName, const T value);

MainTest IntScalarTest();
MainTest FloatScalarTest();
MainTest DoubleScalarTest();
MainTest Float128ScalarTest();
MainTest BrainFloatScalarTest();




template<typename T>
static vector<UnitTest> checkScalarTest(const string testName, const T value)
{
    vector<UnitTest> results;
    bool test1, test2, test3, test4;

    Tensor<T> tensor;

    test1 = tensor.IsScalar();
    test2 = tensor.Data().size() == 1 && tensor.Data()[0] == 0;


    auto t1 = Tensor<T>(value);
    test3 = t1.Data().size() == 1 && t1.Data()[0] == value;


    if  constexpr (!requires { typename Tensor<T>::ReducedTensor; })
        test4 = true;

    results.emplace_back(test1, testName + " uniqueness");
    results.emplace_back(test2, testName + " default value");
    results.emplace_back(test3, testName + " assigment");
    results.emplace_back(test4, testName + " irreducible");

    return results;
}


MainTest IntScalarTest(){
    return {
    [](){ return checkScalarTest("1D Tensor"s, -120); },
        "1D Tensor Int (Scalar)"
    };
}
MainTest FloatScalarTest(){
    return {
    [](){ return checkScalarTest("1D Tensor"s, 85.9f); },
        "1D Tensor Float (Scalar)"
    };
}
MainTest DoubleScalarTest(){
    return {
    [](){ return checkScalarTest("1D Tensor"s, 32.234); },
        "1D Tensor Double (Scalar)"
    };
}
MainTest Float128ScalarTest(){
    return {
    [](){ return checkScalarTest("1D Tensor"s, -19.0304f128); },
        "1D Tensor Float128 (Scalar)"
    };
}
MainTest BrainFloatScalarTest(){
    return {
    [](){ return checkScalarTest("1D Tensor"s, 1.01bf16); },
        "1D Tensor BrainFloat (Scalar)"
    };
}