#include <corsica/mat2.hpp>

#include <algorithm>

using namespace Corsica;

Mat2::Mat2()
{
    this->use_matrix(CORSICA_MAT2_DEFAULT_IDENTITY_MATRIX);
}

Mat2::Mat2(const std::array<f32, 4> &mat)
{
    this->use_matrix(mat);
}

Mat2 &Mat2::use_matrix(const std::array<f32, 4> &mat)
{
    std::copy_n(mat.begin(), 4, this->mat);

    return *this;
}

Mat2 Mat2::operator*(const Mat2& other) const
{
    Mat2 result;

    for (u32 i = 0; i < 2; i++) {
        for (u32 j = 0; j < 2; j++) {
            f32 sum = 0;
            for (u32 k = 0; k < 2; k++) {
                sum += mat[i * 2 + k] * other.mat[k * 2 + j];
            }
            result.mat[i * 2 + j] = sum;
        }
    }

    // result.mat[0] = this->mat[0] * other.mat[0] + this->mat[1] * other.mat[2];
    // result.mat[1] = this->mat[0] * other.mat[1] + this->mat[1] * other.mat[3];
    // result.mat[2] = this->mat[2] * other.mat[0] + this->mat[3] * other.mat[2];
    // result.mat[3] = this->mat[2] * other.mat[1] + this->mat[3] * other.mat[3];
    return result;
}

f32& Mat2::operator[](u32 idx)
{
    return this->mat[idx];
}

const f32& Mat2::operator[](u32 idx) const
{
    return this->mat[idx];
}