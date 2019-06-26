#pragma once

#include <array>
#include <memory>

#include "MeshData.h"
#include "Camera.h"
#include "MeshRenderer.h"
#include "WorldPos.h"
#include "TorchRenderer.h"
#include "opengl/Texture.h"

namespace core {
    class World;
    class Block;

    enum class BlockType {
        air = 0,
        grass,
        dirt,
        torch,
    };

    static const int chunkSize = 16;

    class Chunk {
    public:
        Chunk(World* world, const WorldPos& position);

        void update();
        void render(const Camera& camera);
        void setBlockType(BlockType block, int x, int y, int z);
        BlockType getBlockType(int x, int y, int z) const;
        std::shared_ptr<Block> getBlock(int x, int y, int z) const;
        const WorldPos& getPosition() const;

    private:
        bool inRange(int index) const;

        std::array<std::array<std::array<BlockType, chunkSize>, chunkSize>, chunkSize> m_blocks;
        MeshRenderer m_chunkRenderer;
        TorchRenderer m_torchRenderer;
        WorldPos m_position;
        bool m_update;
        World* m_world;
    };
}