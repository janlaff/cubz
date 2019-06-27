#pragma once

#include <functional>
#include <glm/vec3.hpp>

namespace cubz::game {
    struct WorldPos {
        int x;
        int y;
        int z;

        bool operator==(const WorldPos& other) const;
        glm::vec3 toVec() const;
        std::string toStr() const;
    };

    struct WorldPosHash {
        std::size_t operator()(const WorldPos& pos) const;
    };

    template<typename T>
    using WorldPosMap = std::unordered_map<WorldPos, T, WorldPosHash>;
}