#include "GrassBlock.h"

namespace core {
    Block::Tile GrassBlock::getTexturePosition(Direction direction) {
        if (direction == Direction::up) return { 2, 3 };
        if (direction == Direction::down) return { 1, 3 };
        return { 3, 3 };
    }
}