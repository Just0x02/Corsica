#include <corsica/image.hpp>

#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>

#include <iostream>
#include <cstring>

using namespace Corsica;

Image::Image(const char *src_file_path)
{
    this->file_path = new char[std::strlen(src_file_path)];
    std::strcpy(this->file_path, src_file_path);

    this->load();
}

Image::~Image()
{
    stbi_image_free(this->pixels);
    delete[] this->file_path;
}


void Image::load()
{
    if (this->pixels != nullptr)
        stbi_image_free(this->pixels);

    stbi_set_flip_vertically_on_load(true);
    this->pixels = stbi_load(this->file_path, &this->width, &this->height, &this->channels, STBI_rgb_alpha);

    if (this->pixels == NULL)
    {
        exit(-1);
        std::cout << "Error loading image: " << this->file_path << "." << std::endl;
    }
}