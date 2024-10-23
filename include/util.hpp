#pragma once
#include <concepts>
#include <stdfloat>
#include <tuple>


namespace cayley
{
    // Concept to check if T is an arithmetic type (int, float, double, ...)
    template<typename T>
    concept arithmetic = std::is_arithmetic_v<T>;



    template<typename T, typename... Args>
    struct separate_first_helper {
        using first = T;
        using type = std::tuple<Args...>;
    };

    // Removes the first element of the tuple
    template<typename T, typename... Args>
    using remove_first = typename separate_first_helper<T, Args...>::type;

};