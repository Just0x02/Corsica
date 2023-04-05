#include <corsica/rgb.hpp>

#include <boost/format.hpp>

using namespace Corsica;

RGB::RGB() : r(0), g(0), b(0)
{
}

RGB::RGB(u32 rgb) : r((rgb >> 16) & 0xFF), g((rgb >> 8) & 0xFF), b(rgb & 0xFF)
{
}

RGB::RGB(u8 r, u8 g, u8 b) : r(r), g(g), b(b)
{
}

std::array<u8, 3> RGB::as_array()
{
    return { this->r, this->g, this->b };
}

std::string RGB::as_string()
{
    return std::to_string(this->r) + "," + std::to_string(this->g) + "," + std::to_string(this->b);
}

std::string RGB::as_escape_code()
{
    boost::format fmt = boost::format("\033[38;2;%s;%s;%sm") % std::to_string(this->r) % std::to_string(this->g) % std::to_string(this->b);
    return fmt.str();
}

RGB::operator u32()
{
    return (static_cast<u32>(this->r) << 16) | 
           (static_cast<u32>(this->g) << 8)  | 
           (static_cast<u32>(this->b));
}

// RGB::operator RGBA()
// {
//     return RGBA(this->r, this->g, this->b, 255);
// }