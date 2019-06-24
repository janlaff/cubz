#pragma once

#include "Block.h"

namespace core {
    class AirBlock : public Block {
    public:
        void addToMesh(const Chunk& chunk, int x, int y, int z, MeshData& meshData) override;
        bool isSolid(Direction direction) override;
    };
}