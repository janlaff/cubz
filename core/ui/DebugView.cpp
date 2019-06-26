#include "DebugView.h"
#include "ResourceManager.h"

#include <sstream>

namespace core::ui {
    DebugView::DebugView(const FreetypeFont &font)
        : m_positionText(font, core::ResourceManager::getInstance().getShader("text"))
        , m_directionText(font, core::ResourceManager::getInstance().getShader("text"))
        , m_textGrid(font.getHeight()) {
        m_positionText.setPosition(m_textGrid.getTextPosition(3));
        m_positionText.setColor({ 1, 1, 1 });
        m_directionText.setPosition(m_textGrid.getTextPosition(2));
        m_directionText.setColor({ 1, 1, 1 });
    }

    void DebugView::render(const core::Camera &camera) {
        m_positionText.setText(getPositionText(camera.getPosition()));
        m_directionText.setText(getDirectionText(camera.getYaw(), camera.getPitch()));

        m_positionText.render(camera);
        m_directionText.render(camera);
    }

    std::string DebugView::getPositionText(const glm::vec3 &position) {
        auto ss = std::ostringstream();
        ss << "x: " << position.x << "\n";
        ss << "y: " << position.y << "\n";
        ss << "z: " << position.z;

        return ss.str();
    }

    std::string DebugView::getDirectionText(float yaw, float pitch) {
        auto ss = std::ostringstream();
        ss << "yaw: " << yaw << "\n";
        ss << "pitch: " << pitch;

        return ss.str();
    }
}