#pragma once
#include <concepts>
#include <stdfloat>


namespace cayley
{
    template<typename T>
    concept Hashable = requires(T a)
    {
        { std::hash<T>{}(a) } -> std::convertible_to<std::size_t>;
    };

    template<typename T>
    concept Number = std::integral<T> || std::floating_point<T> || std::same_as<T, __float128>;

};