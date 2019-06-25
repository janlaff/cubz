#pragma once

#include <array>
#include <memory>

#include "MeshData.h"
#include "Camera.h"
#include "Renderer.h"
#include "TorchRenderer.h"
#include "WorldPos.h"
#include "opengl/Texture.h"

namespace core {
    class Block;
    class World;

    static const int chunkSize = 16;

    class Chunk {
    public:
        Chunk(World* world, const WorldPos& position);

        void update();
        void render(const Camera& camera);
        void setBlock(std::shared_ptr<Block> block, int x, int y, int z);
        std::shared_ptr<Block> getBlock(int x, int y, int z) const;
        const WorldPos& getPosition() const;

    private:
        bool inRange(int index) const;

        std::array<std::array<std::array<std::shared_ptr<Block>, chunkSize>, chunkSize>, chunkSize> m_blocks;
        Renderer m_chunkRenderer;
        TorchRenderer m_torchRenderer;
        WorldPos m_position;
        bool m_update;
        World* m_world;
    };
}