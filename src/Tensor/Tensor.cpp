#pragma once
#include <functional>
#include <algorithm>
#include <ranges>
#include "../../include/Tensor/Tensor.hpp"
#include "../../include/exceptions.hpp"

using std::span;
using std::move;

namespace cayley::Tensor
{

// #pragma region private

// #pragma endregion

#pragma region Constructors
    // * Empty constructor, tensor os initialized with zeros
    template <arithmetic UnitType, size_t... Dims>
    constexpr Tensor<UnitType, Dims...>::Tensor() noexcept: m_data{} {};

      // * Initialize the tensor with an value
    template <arithmetic UnitType, size_t... Dims>
    constexpr Tensor<UnitType, Dims...>::Tensor(UnitType value) noexcept {
        m_data.fill(value);
    };

    // * Array constructor
    template <arithmetic UnitType, size_t... Dims>
    Tensor<UnitType, Dims...>::Tensor(Tensor<UnitType, Dims...>::underlying_array data) : m_data{data} {};

#pragma endregion

#pragma region Operators

    

#pragma endregion

#pragma region Observers

    // * Checks if the tensor is a scalar (0D)
    template <arithmetic UnitType, size_t... Dims>
    constexpr bool Tensor<UnitType, Dims...>::IsScalar() const noexcept { return Rank == 0; };

    // * Checks if the tensor is a vector (1D)
    template <arithmetic UnitType, size_t... Dims>
    constexpr bool Tensor<UnitType, Dims...>::IsVector() const noexcept { return Rank == 1; };

    // * Checks if the tensor is a matrix (2D)
    template <arithmetic UnitType, size_t... Dims>
    constexpr bool Tensor<UnitType, Dims...>::IsMatrix() const noexcept { return Rank == 2; };

    // * Checks if the tensor is a matrix (2x2)
    template <arithmetic UnitType, size_t... Dims>
    constexpr bool Tensor<UnitType, Dims...>::Is2x2Matrix() const noexcept { return Shape == (2, 2); };

    // * Checks if the tensor is a matrix (3x3)
    template <arithmetic UnitType, size_t... Dims>
    constexpr bool Tensor<UnitType, Dims...>::Is3x3Matrix() const noexcept { return Shape == (3, 3); };


    // * Returns and span to the underlying data
    template <arithmetic UnitType, size_t... Dims>
    auto Tensor<UnitType, Dims...>::Data() const noexcept { return span(m_data); };

#pragma endregion
}