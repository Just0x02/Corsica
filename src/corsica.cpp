#include <corsica/corsica.hpp>

Corsica::Logger Corsica::SHADER_LOGGER = Corsica::Logger(
    Corsica::LogFlag::CORSICA | Corsica::LogFlag::SHADERS
);

Corsica::Logger Corsica::MESH_LOGGER = Corsica::Logger(
    Corsica::LogFlag::CORSICA | Corsica::LogFlag::MESH
);

Corsica::Logger Corsica::FILEIO_LOGGER = Corsica::Logger(
    Corsica::LogFlag::CORSICA | Corsica::LogFlag::FILEIO
);

Corsica::Logger Corsica::TEXTURE_LOGGER = Corsica::Logger(
    Corsica::LogFlag::CORSICA | Corsica::LogFlag::TEXTURE
);

Corsica::Logger Corsica::OPENGL_LOGGER = Corsica::Logger(
    Corsica::LogFlag::CORSICA | Corsica::LogFlag::OPENGL
);
