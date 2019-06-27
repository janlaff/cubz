#include "AirBlock.h"

namespace cubz::game {
    void AirBlock::addToMesh(const Chunk &chunk, int x, int y, int z, graphics::Mesh &meshData) {}

    bool AirBlock::isSolid(Block::Direction direction) { return false; }
}