// #include <mdspan>
#include <iostream>
#include <concepts>
#ifdef _GLIBCXX_STDFLOAT
#include <stdfloat>
#endif
#include "src/Tensor/Tensor.cpp"

using cayley::Tensor::Tensor;

int main()
{

    Tensor scalar1;
    Tensor<float> scalarFloat;
    Tensor<int> scalarInt;
#ifdef _GLIBCXX_STDFLOAT
    Tensor<std::float128_t> scalarFloat128;
    Tensor<std::bfloat16_t> scalarBinFloat;
#endif

    std::cout << "Hello World!\n";

    return 0;
}