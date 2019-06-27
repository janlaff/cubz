#pragma once

#include "Block.h"

namespace cubz::game {
    class GrassBlock : public Block {
    public:
        Tile getTexturePosition(Direction direction) override;
    };
}