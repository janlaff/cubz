#include "Text.h"
#include "ui/TextData.h"
#include "ui/TextRenderer.h"

namespace cubz::core {
    Text::Text(cubz::core::Engine *engine) : GameObject(engine) {
        addComponent<graphics::ui::TextData>(graphics::ui::TextData {
            "",
            { 10, 10 },
            { 1, 1, 1 }
        });

        addComponent<graphics::ui::TextRenderer>(graphics::ui::TextRenderer());
    }

    void Text::setColor(const glm::vec3 &color) {
        getComponent<graphics::ui::TextData>().color = color;
        updateEntity();
    }

    void Text::setText(const std::string &text) {
        getComponent<graphics::ui::TextData>().value = text;
        updateEntity();
    }

    void Text::setPosition(const glm::vec2 &position) {
        getComponent<graphics::ui::TextData>().position = position;
        updateEntity();
    }
}