#pragma once

#include "Block.h"

namespace core {
    class DirtBlock : public Block {
    public:
        Tile getTexturePosition(Direction direction) override;
    };
}