#include "AirBlock.h"

namespace core {
    void AirBlock::addToMesh(const core::Chunk &chunk, int x, int y, int z, core::MeshData &meshData) {}

    bool AirBlock::isSolid(core::Block::Direction direction) { return false; }
}