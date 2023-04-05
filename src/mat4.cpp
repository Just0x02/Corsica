#include <corsica/mat4.hpp>

#include <algorithm>

using namespace Corsica;

Mat4::Mat4() : mat CORSICA_MAT4_DEFAULT_IDENTITY_MATRIX {}

Mat4::Mat4(f32 mat[])
{
    std::copy_n(mat, 16, this->mat);
}

Mat4 Mat4::operator*(const Mat4 &other) const
{
    Mat4 result;

    for (u32 i = 0; i < 4; i++) {
        for (u32 j = 0; j < 4; j++) {
            f32 sum = 0;
            for (u32 k = 0; k < 4; k++) {
                sum += mat[i * 4 + k] * other.mat[k * 4 + j];
            }
            result.mat[i * 4 + j] = sum;
        }
    }

    return result;
}

f32& Mat4::operator[](u32 idx)
{
    return this->mat[idx];
}

const f32& Mat4::operator[](u32 idx) const
{
    return this->mat[idx];
}