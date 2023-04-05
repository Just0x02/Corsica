#include <corsica/mat3.hpp>

#include <algorithm>

using namespace Corsica;

Mat3::Mat3()
{
    this->use_matrix(CORSICA_MAT3_DEFAULT_IDENTITY_MATRIX);
}

Mat3::Mat3(const std::array<f32, 9> &mat)
{
    this->use_matrix(mat);
}

Mat3 &Mat3::use_matrix(const std::array<f32, 9> &mat)
{
    std::copy_n(mat.begin(), 9, this->mat);
    
    return *this;
}

Mat3 Mat3::operator*(const Mat3& other) const
{
    Mat3 result;

    for (u32 i = 0; i < 3; i++) {
        for (u32 j = 0; j < 3; j++) {
            f32 sum = 0;
            for (u32 k = 0; k < 3; k++) {
                sum += mat[i * 3 + k] * other.mat[k * 3 + j];
            }
            result.mat[i * 3 + j] = sum;
        }
    }

    // result.mat[0] = this->mat[0] * other.mat[0] + this->mat[1] * other.mat[3] + this->mat[2] * other.mat[6];
    // result.mat[1] = this->mat[0] * other.mat[1] + this->mat[1] * other.mat[4] + this->mat[2] * other.mat[7];
    // result.mat[2] = this->mat[0] * other.mat[2] + this->mat[1] * other.mat[5] + this->mat[2] * other.mat[8];
    // result.mat[3] = this->mat[3] * other.mat[0] + this->mat[4] * other.mat[3] + this->mat[5] * other.mat[6];
    // result.mat[4] = this->mat[3] * other.mat[1] + this->mat[4] * other.mat[4] + this->mat[5] * other.mat[7];
    // result.mat[5] = this->mat[3] * other.mat[2] + this->mat[4] * other.mat[5] + this->mat[5] * other.mat[8];
    // result.mat[6] = this->mat[6] * other.mat[0] + this->mat[7] * other.mat[3] + this->mat[8] * other.mat[6];
    // result.mat[7] = this->mat[6] * other.mat[1] + this->mat[7] * other.mat[4] + this->mat[8] * other.mat[7];
    // result.mat[8] = this->mat[6] * other.mat[2] + this->mat[7] * other.mat[5] + this->mat[8] * other.mat[8];
    return result;
}

f32& Mat3::operator[](u32 idx)
{
    return this->mat[idx];
}

const f32& Mat3::operator[](u32 idx) const
{
    return this->mat[idx];
}