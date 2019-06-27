#include "WorldPos.h"

#include <sstream>
#include <iomanip>

namespace cubz::game {
    bool WorldPos::operator==(const WorldPos &other) const {
        return x == other.x && y == other.y && z == other.z;
    }

    glm::vec3 WorldPos::toVec() const {
        return { x, y, z };
    }

    std::string WorldPos::toStr() const {
        auto ss = std::ostringstream();
        ss << "{ x: " << x;
        ss << " y: " << y;
        ss << " z: " << z << " }";

        return ss.str();
    }

    std::size_t WorldPosHash::operator()(const WorldPos &pos) const {
        auto hash0 = std::hash<int>{}(pos.x);
        auto hash1 = std::hash<int>{}(pos.y) ^ (hash0 << 1);
        auto hash2 = std::hash<int>{}(pos.z) ^ (hash1 << 1);

        return hash2;
    }
}