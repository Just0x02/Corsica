#include <corsica/image.hpp>
#include <corsica/corsica.hpp>

#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>

#include <iostream>
#include <cstring>

using namespace Corsica;

Image::Image(std::string src_file_path) : file_path(src_file_path)
{
    this->pixels = NULL;

    this->load();
}

Image::~Image()
{
    stbi_image_free(this->pixels);
}

void Image::load()
{
    Corsica::CORSICA_LOGGER.debug("Attempting to load image '", this->file_path, "' into memory...");

    if (this->pixels != NULL)
        stbi_image_free(this->pixels);

    // stbi_set_flip_vertically_on_load(true);
    this->pixels = stbi_load(this->file_path.c_str(), &this->width, &this->height, &this->channels, STBI_rgb_alpha);

    if (this->pixels == NULL)
    {
        Corsica::CORSICA_LOGGER.fatal("Error loading image '", this->file_path, "'...");
        exit(-1);
    }

    Corsica::CORSICA_LOGGER.debug("Sucessfully loaded image '", this->file_path, "' into memory!");
}