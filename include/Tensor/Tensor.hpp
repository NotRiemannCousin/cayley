#pragma once
#include <type_traits>
#include <typeinfo>
#include <concepts>
#include <vector>
#include <ranges>

#ifdef _GLIBCXX_STDFLOAT
#include <stdfloat>
#endif

#include "TensorOrientation.hpp"
#include "../util.hpp"

using std::remove_cv_t;
using std::span;
using std::vector;

namespace cayley::Tensor
{
    template <arithmetic UnitType = float,
              TensorOrientation Orientation = TensorOrientation::ROW_MAJOR>
    class Tensor
    {
    private:
        TensorOrientation orientation = Orientation;

        vector<UnitType> data{(UnitType)0};
        const vector<size_t> dimensions{};
        const size_t order = 0;

        size_t calculateSize() const noexcept;

    public:
#pragma region Constructors

        constexpr Tensor() noexcept;

        constexpr Tensor(UnitType scalar) noexcept;

        Tensor(span<size_t> dimensions);

        Tensor(span<size_t> dimensions, span<UnitType> data);

#pragma endregion

#pragma region Element Access

        Tensor operator[](const size_t other) const;

#pragma endregion

#pragma region operators

        // Tensor operator*(const double scalar) const;

        // Tensor operator /(const double scalar) const;

        // Tensor operator *(const Tensor& other) const;

        // Tensor operator /(const Tensor& other) const;

        // Tensor operator +(const Tensor& other) const;

        // Tensor operator -(const Tensor& other) const;

        // Tensor operator [](const int other) const;

#pragma endregion

#pragma region Observers

        constexpr size_t Size() const noexcept;

        constexpr bool IsScalar() const noexcept;

        constexpr bool IsVector() const noexcept;

        constexpr bool Is2DMatrix() const noexcept;

        constexpr bool Is3DMatrix() const noexcept;

        constexpr span<const UnitType> Data() const noexcept;

#pragma endregion
    };
};