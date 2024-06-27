#pragma once
#include <concepts>
#include <stdfloat>


namespace cayley
{
    template<typename T>
    concept arithmetic = std::is_arithmetic_v<T>;
};