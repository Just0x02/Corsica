#include <corsica/corsica.hpp>

extern const Corsica::Logger Corsica::SHADER_LOGGER = Corsica::Logger(
    Corsica::LogFlag::CORSICA | Corsica::LogFlag::SHADERS
);

extern const Corsica::Logger Corsica::MESH_LOGGER = Corsica::Logger(
    Corsica::LogFlag::CORSICA | Corsica::LogFlag::MESH
);

extern const Corsica::Logger Corsica::FILEIO_LOGGER = Corsica::Logger(
    Corsica::LogFlag::CORSICA | Corsica::LogFlag::FILEIO
);

extern const Corsica::Logger Corsica::TEXTURE_LOGGER = Corsica::Logger(
    Corsica::LogFlag::CORSICA | Corsica::LogFlag::TEXTURE
);

extern const Corsica::Logger Corsica::OPENGL_LOGGER = Corsica::Logger(
    Corsica::LogFlag::CORSICA | Corsica::LogFlag::OPENGL
);
