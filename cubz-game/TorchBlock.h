#pragma once

#include "Block.h"

namespace cubz::game {
    class TorchBlock : public Block {
    public:
        void addToMesh(const Chunk& chunk, int x, int y, int z, graphics::Mesh& meshData) override;
        bool isSolid(Direction direction) override;
        Tile getTexturePosition(Direction direction) override;
        void faceDataNorth(int x, int y, int z, graphics::Mesh& meshData) override;
        void faceDataEast(int x, int y, int z, graphics::Mesh& meshData) override;
    };
}