#include "DebugView.h"
#include "ShaderManager.h"

#include <sstream>

namespace core::ui {
    DebugView::DebugView(const FreetypeFont &font)
        : m_positionText(font, core::ShaderManager::getInstance().getShader("text"))
        , m_directionText(font, core::ShaderManager::getInstance().getShader("text"))
        , m_textGrid(font.getHeight()) {
        m_positionText.setPosition(m_textGrid.getTextPosition());
        m_directionText.setPosition(m_textGrid.getTextPosition());
    }

    void DebugView::render(const core::Camera &camera) {
        m_positionText.setText(getPositionText(camera.getPosition()));
        m_directionText.setText(getDirectionText(camera.getYaw(), camera.getPitch()));

        m_positionText.render(camera);
        m_directionText.render(camera);
    }

    std::string DebugView::getPositionText(const glm::vec3 &position) {
        auto ss = std::ostringstream();
        ss << "x: " << position.x << "; ";
        ss << "y: " << position.y << "; ";
        ss << "z: " << position.z;

        return ss.str();
    }

    std::string DebugView::getDirectionText(float yaw, float pitch) {
        auto ss = std::ostringstream();
        ss << "yaw: " << yaw << "; ";
        ss << "pitch: " << pitch;

        return ss.str();
    }
}