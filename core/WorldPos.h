#pragma once

#include <functional>
#include <glm/vec3.hpp>

namespace core {
    struct WorldPos {
        int x;
        int y;
        int z;

        bool operator==(const WorldPos& other) const;
        glm::vec3 toVec() const;
    };

    struct WorldPosHash {
        std::size_t operator()(const core::WorldPos& pos) const;
    };
}