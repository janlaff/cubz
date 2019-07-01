#pragma once

#include "Block.h"

namespace cubz::game {
    class AirBlock : public Block {
    public:
        void addToMesh(ChunkMeshBuilder& meshBuilder, int x, int y, int z) override;
        bool isSolid(Direction direction) override;
    };
}