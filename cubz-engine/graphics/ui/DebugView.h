#pragma once

#include "FreetypeText.h"
#include "Camera.h"
#include "TextGrid.h"

namespace cubz::graphics::ui {
    class DebugView {
    public:
        DebugView(FreetypeCharMap& charMap);

        void update(float deltaTime);
        void render(const Camera& camera);

    private:
        std::string getFpsText(float deltaTime);
        std::string getVecText(const glm::vec3 &position);

        FreetypeText m_positionText;
        FreetypeText m_directionText;
        FreetypeText m_fpsText;
        TextGrid m_textGrid;

        float m_deltaTime;
        glm::vec3 m_direction;
        glm::vec3 m_position;
    };
}