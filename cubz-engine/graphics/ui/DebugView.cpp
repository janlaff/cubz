#include "DebugView.h"
#include "ResourceManager.h"

#include <sstream>

namespace cubz::graphics::ui {
    DebugView::DebugView(FreetypeCharMap &charMap)
        : m_positionText(charMap)
        , m_directionText(charMap)
        , m_fpsText(charMap)
        , m_textGrid(charMap.getChar('X')->getHeight()) {
        m_fpsText.setPosition(m_textGrid.getTextPosition());
        m_fpsText.setColor({ 1, 0, 0 });
        m_positionText.setPosition(m_textGrid.getTextPosition(3));
        m_positionText.setColor({ 0, 0, 0 });
        m_directionText.setPosition(m_textGrid.getTextPosition(2));
        m_directionText.setColor({ 0, 0, 0 });
    }

    void DebugView::update(float deltaTime) {
        m_positionText.setText(getVecText(m_position));
        m_directionText.setText(getVecText(m_direction));
        m_fpsText.setText(getFpsText(deltaTime));

        m_fpsText.update();
        m_positionText.update();
        m_directionText.update();
    }

    void DebugView::render(const cubz::graphics::Camera &camera) {
        m_position = camera.getPosition();
        m_direction = camera.getDirection();

        m_fpsText.render(camera);
        m_positionText.render(camera);
        m_directionText.render(camera);
    }

    std::string DebugView::getFpsText(float deltaTime) {
        int fps = static_cast<int>(1.0f / deltaTime);
        return "Fps: " + std::to_string(fps);
    }

    std::string DebugView::getVecText(const glm::vec3 &position) {
        auto ss = std::ostringstream();
        ss << "x: " << position.x << "\n";
        ss << "y: " << position.y << "\n";
        ss << "z: " << position.z;

        return ss.str();
    }
}