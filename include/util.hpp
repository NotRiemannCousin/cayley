#pragma once
#include <concepts>
#include <stdfloat>
#include <tuple>


using std::tuple;
using std::remove_cv_t;
using std::is_arithmetic_v;


namespace cayley
{
    // * Concept that matches arithmetic types (int, float, double, ...)
    template<typename T>
    concept arithmetic = is_arithmetic_v<T>;






    template<size_t N, typename Tuple>
    struct remove_nth_type;

    // * Specialization for the case when N == 0 (remove first element)
    template<typename First, typename... Rest>
    struct remove_nth_type<0, std::tuple<First, Rest...>> {
        using type = std::tuple<Rest...>;  // Skip the first type
    };

    // * Specialization for the case when N > 0 (keep first element, recurse)
    template<size_t N, typename First, typename... Rest>
    struct remove_nth_type<N, std::tuple<First, Rest...>> {
        using type = decltype(std::tuple_cat(
            std::tuple<First>(), // Keep the first type
            typename remove_nth_type<N - 1, std::tuple<Rest...>>::type() // Recurse on the rest
        ));
    };

    // * Helper alias for removing the N-th type from the tuple
    template<size_t N, typename Tuple>
    using remove_nth_t = typename remove_nth_type<N, Tuple>::type;
};