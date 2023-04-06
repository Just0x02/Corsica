#include <corsica/image.hpp>
#include <corsica/corsica.hpp>

#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <stb/stb_image.h>
#include <stb/stb_image_write.h>

#include <iostream>
#include <cstring>

using namespace Corsica;

Image::Image()
{
    this->pixels = NULL;
}

Image::Image(std::string src_file_path) : file_path(src_file_path)
{
    this->pixels = NULL;

    this->load();
}

Image::~Image()
{
    Corsica::CORSICA_LOGGER.warn("Freeing image '", this->file_path, "' from memory...");
    stbi_image_free(this->pixels);
}

u64 Image::get_size()
{
    return this->width * this->height;
}

u64 Image::get_pixels_size()
{
    return this->width * this->height * this->channels;
}

void Image::load()
{
    Corsica::CORSICA_LOGGER.debug("Attempting to load image '", this->file_path, "' into memory...");

    if (this->pixels != NULL)
        stbi_image_free(this->pixels);

    stbi_set_flip_vertically_on_load(true);
    this->pixels = (u32 *) stbi_load(this->file_path.c_str(), &this->width, &this->height, &this->channels, STBI_rgb_alpha);

    if (this->pixels == NULL)
    {
        Corsica::CORSICA_LOGGER.fatal("Error loading image '", this->file_path, "'...");
        exit(-1);
    }

    Corsica::CORSICA_LOGGER.debug("Sucessfully loaded image '", this->file_path, "' into memory!");
}

void Image::load_from_file(const std::string &img_path)
{
    this->file_path = std::string(img_path);
    this->load();
}

void Image::write_to_file(const std::string &new_file_path)
{
    stbi_write_png(new_file_path.c_str(), this->width, this->height, this->channels, this->pixels, this->width * this->channels);
}