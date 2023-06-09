#pragma once

#include <types.h>

#include <corsica/gfx.hpp>
#include <array>

#define CORSICA_MAT3_DEFAULT_IDENTITY_MATRIX {1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f}

namespace Corsica
{
    struct Mat3
    {
        f32 mat[9];

        Mat3();
        Mat3(const std::array<f32, 9> &mat);

        Mat3 &use_matrix(const std::array<f32, 9> &mat);

        Mat3 operator*(const Mat3 &other) const;

        f32& operator[](u32 idx);
        const f32& operator[](u32 idx) const;
    };
};