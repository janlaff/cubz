#include "TextRenderSystem.h"
#include "ui/TextData.h"
#include "ui/TextRenderer.h"

namespace cubz::core {
    void TextRenderSystem::update() {
        for (const auto& entity : m_updatedEntities) {
            const auto& text = m_ecs->getComponent<graphics::ui::TextData>(entity);
            auto& textRenderer = m_ecs->getComponent<graphics::ui::TextRenderer>(entity);

            textRenderer.update(text);
        }

        m_updatedEntities.clear();
    }

    void TextRenderSystem::render(const graphics::Camera &camera, const graphics::ui::FreetypeCharMap& charMap) {
        for (const auto& entity : m_entities) {
            auto& textRenderer = m_ecs->getComponent<graphics::ui::TextRenderer>(entity);
            textRenderer.render(camera, charMap);
        }
    }
}