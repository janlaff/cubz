#pragma once

#include "FreetypeText.h"
#include "Camera.h"

namespace graphics {
    class DebugView {
    public:
        DebugView(const FreetypeFont& font);

        void render(const Camera& camera);

    private:
        std::string getPositionText(const glm::vec3& position);
        std::string getDirectionText(float yaw, float pitch);

        graphics::FreetypeText m_positionText;
        graphics::FreetypeText m_directionText;
        graphics::FreetypeText m_disclaimerText;
    };
}