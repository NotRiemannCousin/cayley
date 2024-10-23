#pragma once
#include <type_traits>
#include <typeinfo>
#include <concepts>
#include <ranges>
#include <array>

#ifdef _GLIBCXX_STDFLOAT
#include <stdfloat>
#endif

#include "../util.hpp"

using std::remove_cv_t;
using std::array;
using std::span;

// Tensors are limited to 2GB of memory
static constexpr size_t MemoryLimit = 1LL << 31;

namespace cayley::Tensor
{
	template <arithmetic UnitType = double, size_t... Dims>
	class Tensor
	{
	public: 
		  // using ReduceTensor = Tensor<UnitType, remove_first<Dims...>...>;

		// * The number of dimensions in the tensor
		static constexpr size_t Rank = sizeof...(Dims);
		// * The number of elements in the tensor
		static constexpr size_t Size = (1 * ... * Dims);
		// * The shape of the tensor
		static constexpr size_t Shape[] = {Dims...};



		// * The maximum number of elements in the tensor
		static constexpr size_t MaxSize = MemoryLimit / sizeof(UnitType);
		// static_assert(Size <= MaxSize, "Tensor is too large");



		// * using ReducedTensor = Tensor<UnitType, remove_first<Dims...>>;
		using underlying_array = array<UnitType, Size>;

	private:
		// * The array that stores the data
		underlying_array m_data;

	public:
#pragma region Constructors

		constexpr Tensor() noexcept;

		constexpr Tensor(UnitType value) noexcept;

		Tensor(underlying_array data);

#pragma endregion

#pragma region Element Access

		Tensor operator[](const size_t other) const;

#pragma endregion

#pragma region operators
		// Tensor operator*(const double scalar) const;

		// Tensor operator/(const double scalar) const;

		

		// Tensor operator+(const Tensor& other) const;

		// Tensor operator-(const Tensor& other) const;
	
		// Tensor ComponentwiseMult(const Tensor& other) const;

		// Tensor ComponentwiseDiv(const Tensor& other) const;

		// auto operator[](const int other) const;

#pragma endregion

#pragma region Observers

		constexpr bool IsScalar() const noexcept;

		constexpr bool IsVector() const noexcept;

		constexpr bool IsMatrix() const noexcept;

		constexpr bool Is2x2Matrix() const noexcept;

		constexpr bool Is3x3Matrix() const noexcept;

		auto Data() const noexcept;
		// span<UnitType> Data() const noexcept;

#pragma endregion
	};

	  // Matrix Especialization
	

};