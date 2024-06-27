#pragma once
#include "../../include/Tensor/Tensor.hpp"

namespace cayley::Tensor
{

    template <arithmetic UnitType,
              TensorOrientation Orientation>
    Tensor<UnitType, Orientation>::Tensor() : data{0}, dimensions{1}, order{1} {};
}