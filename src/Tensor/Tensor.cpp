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

#pragma region private

    template <arithmetic UnitType>
    size_t Tensor<UnitType>::calculateSize() const noexcept
    {
        int count = 1;
        for (int dimension : dimensions)
            count *= dimension;
        return count;
    }

#pragma endregion

#pragma region Constructors
    // * Empty constructor, scalar tensor
    template <arithmetic UnitType>
    constexpr Tensor<UnitType>::Tensor() noexcept = default;

    // * Scalar constructor
    template <arithmetic UnitType>
    constexpr Tensor<UnitType>::Tensor(UnitType scalar) noexcept : data{scalar} {};

    template <arithmetic UnitType>
    Tensor<UnitType>::Tensor(span<size_t> dimensions): dimensions{dimensions}, order{dimensions.size()}
    {
        data.resize(calculateSize());
    };

    template <arithmetic UnitType>
    Tensor<UnitType>::Tensor(span<size_t> dimensions, span<UnitType> data) : dimensions{dimensions}, data{data}, order{dimensions.size()}
    {
        if (data() != calculateSize())
            throw InvalidArgumentException("Data can't be assigned to this tensor.");
    };
#pragma endregion

#pragma region Operators

    // template <arithmetic UnitType>
    // constexpr Tensor<UnitType> Tensor<UnitType>::operator=(Tensor<UnitType> &&t) noexcept{
    //     data        = move(t.data);
    //     dimensions  = move(remove_cv_t<decltype(t.dimensions)>(t.dimensions));
    //     order       = move(t.order);
    //     orientation = move(t.orientation);

    //     return this;
    // };
    // template <arithmetic UnitType>
    // constexpr Tensor<UnitType> Tensor<UnitType>::operator=(const Tensor<UnitType> &t) noexcept{
    //     data        = t.data;
    //     dimensions  = t.dimensions;
    //     order       = t.order;
    //     orientation = t.orientation;

    //     return *this;
    // };

#pragma endregion

#pragma region Observers
    template <arithmetic UnitType>
    constexpr bool Tensor<UnitType>::IsScalar() const noexcept { return order == 0; };

    template <arithmetic UnitType>
    constexpr bool Tensor<UnitType>::IsVector() const noexcept { return order == 1; };

    template <arithmetic UnitType>
    constexpr bool Tensor<UnitType>::Is2DMatrix() const noexcept { return order == 2; };

    template <arithmetic UnitType>
    constexpr span<const UnitType> Tensor<UnitType>::Data() const noexcept { return span(data); };

#pragma endregion
}