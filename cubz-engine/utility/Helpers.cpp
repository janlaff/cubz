#include "Helpers.h"

#include <sstream>

namespace cubz::utility {
    std::string vectorToString(const glm::vec3& vec) {
        auto ss = std::ostringstream();
        ss << "x: " << vec.x << "; ";
        ss << "y: " << vec.y << "; ";
        ss << "z: " << vec.z;

        return ss.str();
    }
}