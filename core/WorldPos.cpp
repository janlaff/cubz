#include "WorldPos.h"

namespace core {
    bool WorldPos::operator==(const core::WorldPos &other) const {
        return x == other.x && y == other.y && z == other.z;
    }

    glm::vec3 WorldPos::toVec() const {
        return { x, y, z };
    }

    std::size_t WorldPosHash::operator()(const core::WorldPos &pos) const {
        auto hash0 = std::hash<int>{}(pos.x);
        auto hash1 = std::hash<int>{}(pos.y) ^ (hash0 << 1);
        auto hash2 = std::hash<int>{}(pos.z) ^ (hash1 << 1);

        return hash2;
    }
}