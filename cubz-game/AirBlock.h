#pragma once

#include "Block.h"

namespace cubz::game {
    class AirBlock : public Block {
    public:
        void addToMesh(const Chunk& chunk, int x, int y, int z, graphics::Mesh& meshData) override;
        bool isSolid(Direction direction) override;
    };
}