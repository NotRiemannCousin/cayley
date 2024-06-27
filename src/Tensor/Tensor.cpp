#pragma once
#include <functional>
#include <algorithm>
#include <ranges>
#include "../../include/Tensor/Tensor.hpp"
#include "../../include/exceptions.hpp"

using std::span;

namespace cayley::Tensor
{

#pragma region private

    template <arithmetic UnitType, TensorOrientation Orientation>
    size_t Tensor<UnitType, Orientation>::calculateSize() const noexcept
    {
        int count = 1;
        for (int dimension : dimensions)
            count *= dimension;
        return count;
    }

#pragma endregion

#pragma region Constructors
    // * Empty constructor, scalar tensor
    template <arithmetic UnitType, TensorOrientation Orientation>
    constexpr Tensor<UnitType, Orientation>::Tensor() noexcept = default;

    // * Scalar constructor
    template <arithmetic UnitType, TensorOrientation Orientation>
    constexpr Tensor<UnitType, Orientation>::Tensor(UnitType scalar) noexcept : data{scalar} {};

    template <arithmetic UnitType, TensorOrientation Orientation>
    Tensor<UnitType, Orientation>::Tensor(span<size_t> dimensions) : dimensions{dimensions}, order{dimensions.size()}
    {
        data.resize(calculateSize());
    };

    template <arithmetic UnitType, TensorOrientation Orientation>
    Tensor<UnitType, Orientation>::Tensor(span<size_t> dimensions, span<UnitType> data) : dimensions{dimensions}, data{data}, order{dimensions.size()}
    {
        if (data() != calculateSize())
            throw InvalidArgumentException("Data can't be assigned to this tensor.");
    };
#pragma endregion

#pragma region Observers
    template <arithmetic UnitType, TensorOrientation Orientation>
    constexpr bool Tensor<UnitType, Orientation>::IsScalar() const noexcept { return order == 0; };

    template <arithmetic UnitType, TensorOrientation Orientation>
    constexpr bool Tensor<UnitType, Orientation>::IsVector() const noexcept { return order == 1; };

    template <arithmetic UnitType, TensorOrientation Orientation>
    constexpr bool Tensor<UnitType, Orientation>::Is2DMatrix() const noexcept { return order == 2; };

    template <arithmetic UnitType, TensorOrientation Orientation>
    constexpr span<const UnitType> Tensor<UnitType, Orientation>::Data() const noexcept { return span(data); };

#pragma endregion
}