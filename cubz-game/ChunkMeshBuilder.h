#pragma once

#include <memory>

#include <graphics/Mesh.h>

#include "ChunkData.h"

namespace cubz::game {
    class Block;

    class ChunkMeshBuilder {
    public:
        explicit ChunkMeshBuilder(const ChunkData& chunkData);

        Block* getBlock(int x, int y, int z);
        Block* getBlockRenderer(BlockType type);
        graphics::Mesh& getMesh();

    private:
        graphics::Mesh m_mesh;
        ChunkData m_chunkData;
        std::unordered_map<BlockType, std::shared_ptr<Block>> m_blockRenderers;
    };
}