#pragma once

#include <types.h>

#include <corsica/gfx.hpp>
#include <array>

#define CORSICA_MAT4_DEFAULT_IDENTITY_MATRIX {1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f}

namespace Corsica
{
    struct Mat4
    {
        f32 mat[16];

        Mat4();
        Mat4(const std::array<f32, 16> &mat);

        Mat4 &use_matrix(const std::array<f32, 16> &mat);

        Mat4 operator*(const Mat4 &other) const;

        f32& operator[](u32 idx);
        const f32& operator[](u32 idx) const;
    };
};