#include "GrassBlock.h"

namespace core {
    Block::Tile GrassBlock::getTexturePosition(Direction direction) {
        if (direction == Direction::up) return { 0, 0 };
        if (direction == Direction::down) return { 2, 0 };
        return { 3, 0 };
    }
}