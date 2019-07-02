#pragma once

#include "Block.h"

namespace cubz::game {
    class StoneBlock : public Block {
    public:
        Tile getTexturePosition(Direction direction) override;
    };
}