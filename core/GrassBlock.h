#pragma once

#include "Block.h"

namespace core {
    class GrassBlock : public Block {
    public:
        Tile getTexturePosition(Direction direction) override;
    };
}