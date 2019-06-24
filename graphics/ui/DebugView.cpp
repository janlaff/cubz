#include "DebugView.h"
#include "ShaderManager.h"

#include <sstream>

namespace graphics {
    static const char *const disclaimer = "@proman0973 - GitHub";

    DebugView::DebugView(const graphics::FreetypeFont &font)
        : m_positionText(font, graphics::ShaderManager::getInstance().getShader("text"))
        , m_directionText(font, graphics::ShaderManager::getInstance().getShader("text"))
        , m_disclaimerText(font, graphics::ShaderManager::getInstance().getShader("text")) {
        m_disclaimerText.setText(disclaimer);

        m_positionText.setPosition(10.0f, 600.0f - m_positionText.getHeight() - 10.0f);
        m_directionText.setPosition(10.0f, 600.0f - m_directionText.getHeight() - m_positionText.getHeight() - 20.0f);
        m_disclaimerText.setPosition(10.0f, 10.0f);
    }

    void DebugView::render(const graphics::Camera &camera) {
        m_positionText.setText(getPositionText(camera.getPosition()));
        m_directionText.setText(getDirectionText(camera.getYaw(), camera.getPitch()));

        m_positionText.render(camera);
        m_directionText.render(camera);
        m_disclaimerText.render(camera);
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