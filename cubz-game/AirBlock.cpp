#include "AirBlock.h"

namespace cubz::game {
    void AirBlock::addToMesh(ChunkMeshBuilder& meshBuilder, int x, int y, int z) {}

    bool AirBlock::isSolid(Block::Direction direction) { return false; }
}