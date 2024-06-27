#pragma once
#include <type_traits>
#include <typeinfo>
#include <concepts>
#include <vector>
#include <span>

#include "TensorOrientation.hpp"
#include "../util.hpp"


using std::vector;



namespace cayley::Tensor
{
    // template <Number UnitType = float,
    //           TensorOrientation Orientation = TensorOrientation::ROW_MAJOR>
    class Tensor
    {
    private:
        // TensorOrientation orientation = Orientation;

        // type_info element_type = typeid(UnitType);
        // vector<UnitType> data;
        // const vector<int> dimensions;
        // const int order;

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