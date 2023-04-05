#include <corsica/texture.hpp>
#include <corsica/corsica.hpp>

#include <cstring>

using namespace Corsica;

Texture2D Texture2D::create_from_pixels(u8 *pixels, size_t width, size_t height)
{
    Texture2D tex;

    tex.size.x = width;
    tex.size.y = height;

    glGenTextures(1, &tex.handle);
    glBindTexture(GL_TEXTURE_2D, tex.handle);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixels);
    glGenerateMipmap(GL_TEXTURE_2D);

    return tex;
}

Texture2D Texture2D::create_from_image(Image &image)
{
    // size_t img_total_size = image.width * image.height * 4;
    // u8 *pixels_cpy = new u8[img_total_size];
    // memcpy(pixels_cpy, image.pixels, img_total_size);

    return Texture2D::create_from_pixels(image.pixels, image.width, image.height);
}

Texture2D Texture2D::create_from_path(char *path)
{
    Corsica::TEXTURE_LOGGER.debug("Loading image from path: '", path, "'");
    Image tex_image(path);
    Corsica::TEXTURE_LOGGER.debug("Sucessfully loaded image from path: '", path, "'");
    return Texture2D::create_from_image(tex_image);
}

void Texture2D::destroy(const Texture2D &tex)
{
    Corsica::TEXTURE_LOGGER.warn("Destroying texture ID: ", tex.handle);
    glDeleteTextures(1, &tex.handle);
}

void Texture2D::bind(const Texture2D &tex)
{
    glBindTexture(GL_TEXTURE_2D, tex.handle);
}