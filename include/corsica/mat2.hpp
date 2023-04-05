#pragma once

#include <types.h>

#include <corsica/gfx.hpp>

#define CORSICA_MAT2_DEFAULT_IDENTITY_MATRIX {1.0f, 0.0f, 0.0f, 1.0f}

namespace Corsica
{
    struct Mat2
    {
        f32 mat[4];

        Mat2();
        Mat2(f32 mat[]);

        Mat2 operator*(const Mat2 &other) const;

        f32 &operator[](u32 idx);
        const f32 &operator[](u32 idx) const;
    };
};