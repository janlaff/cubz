#pragma once

#include "Block.h"

namespace cubz::game {
    class DirtBlock : public Block {
    public:
        Tile getTexturePosition(Direction direction) override;
    };
}