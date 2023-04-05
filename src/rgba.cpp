#include <corsica/rgba.hpp>

using namespace Corsica;

RGBA::RGBA() : r(0), g(0), b(0), a(255)
{
}

RGBA::RGBA(u32 rgba) : r((rgba >> 24) & 0xFF), g((rgba >> 16) & 0xFF), b((rgba >> 8) & 0xFF), a(rgba & 0xFF)
{
}

RGBA::RGBA(u8 r, u8 g, u8 b, u8 a) : r(r), g(g), b(b), a(a)
{
}

std::array<u8, 4> RGBA::as_array()
{
    return { this->r, this->g, this->b, this->a };
}

std::string RGBA::as_string()
{
    return std::to_string(this->r) + "," + std::to_string(this->g) + "," + std::to_string(this->b) + "," + std::to_string(this->a);
}

RGBA::operator u32()
{
    return (static_cast<u32>(this->r) << 24) | 
           (static_cast<u32>(this->g) << 16) | 
           (static_cast<u32>(this->b) << 8)  | 
           (static_cast<u32>(this->a));
}

// RGBA::operator RGB()
// {
//     return RGB(this->r, this->g, this->b);
// }