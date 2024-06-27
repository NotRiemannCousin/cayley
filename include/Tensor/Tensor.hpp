#pragma once
#include <type_traits>
#include <typeinfo>
#include <concepts>
#include <vector>
#include <span>

#include "TensorOrientation.hpp"
#include "../util.hpp"


using std::vector;
using std::remove_cv_t;



namespace cayley::Tensor
{
    template <arithmetic UnitType = float,
              TensorOrientation Orientation = TensorOrientation::ROW_MAJOR>
    class Tensor
    {
    public:
#pragma region Aliases
        using element_type           = UnitType;
        using value_type             = remove_cv_t<UnitType>;
        using size_type              = size_t;
        using difference_type        = ptrdiff_t;
        using pointer                = UnitType*;
        using const_pointer          = const UnitType*;
        using reference              = UnitType&;
        using const_reference        = const UnitType&;
        // TODO: Implement iterators
        // using iterator               = __gnu_cxx::__normal_iterator<pointer, span>;
        // using reverse_iterator       = std::reverse_iterator<iterator>;
#pragma endregion

    private:
        TensorOrientation orientation = Orientation;

        vector<UnitType> data;
        const vector<int> dimensions;
        const int order;

    public:

        Tensor();

        // Tensor(vector<UnitType> dimensions);

        // Tensor(vector<int> dimensions, vector<UnitType> data);



        // Tensor operator*(const double scalar) const;

        // Tensor operator /(const double scalar) const;


        // Tensor operator *(const Tensor& other) const;

        // Tensor operator /(const Tensor& other) const;

        // Tensor operator +(const Tensor& other) const;

        // Tensor operator -(const Tensor& other) const;


        // Tensor operator [](const int other) const;

        // bool IsNull() const noexcept;

    };

};