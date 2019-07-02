#include "StoneBlock.h"

namespace cubz::game {
    Block::Tile StoneBlock::getTexturePosition(Direction direction) {
        return { 1, 0 };
    }
}