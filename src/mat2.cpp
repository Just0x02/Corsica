#include <corsica/mat2.hpp>


using namespace Corsica;

Mat2::Mat2() : mat CORSICA_MAT2_DEFAULT_IDENTITY_MATRIX {}

Mat2::Mat2(f32 mat[]) 
{
    this->mat[0] = mat[0];
    this->mat[1] = mat[1];
    this->mat[2] = mat[2];
    this->mat[3] = mat[3];
}

Mat2 Mat2::operator*(const Mat2& other) const
{
    Mat2 result;
    result.mat[0] = this->mat[0] * other.mat[0] + this->mat[1] * other.mat[2];
    result.mat[1] = this->mat[0] * other.mat[1] + this->mat[1] * other.mat[3];
    result.mat[2] = this->mat[2] * other.mat[0] + this->mat[3] * other.mat[2];
    result.mat[3] = this->mat[2] * other.mat[1] + this->mat[3] * other.mat[3];
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