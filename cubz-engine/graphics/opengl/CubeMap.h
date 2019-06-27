#pragma once

#include <string>
#include <GL/glew.h>

#include "Texture.h"

namespace cubz::graphics::opengl {
    class CubeMap : public Texture {
    public:
        CubeMap(const std::string& name);

        void load(const std::string& name) override;
    };
}
