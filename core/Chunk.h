#pragma once

#include <array>
#include <memory>

#include "MeshData.h"
#include "Camera.h"
#include "ChunkRenderer.h"
#include "opengl/Texture.h"

namespace core {
    class Block;

    static const int chunkSize = 16;

    class Chunk {
    public:
        Chunk(const glm::vec3& position);

        void update();
        void render(const Camera& camera);
        void setBlock(std::shared_ptr<Block> block, int x, int y, int z);
        std::shared_ptr<Block> getBlock(int x, int y, int z) const;

    private:
        std::array<std::array<std::array<std::shared_ptr<Block>, chunkSize>, chunkSize>, chunkSize> m_blocks;
        ChunkRenderer m_chunkRenderer;
        glm::vec3 m_position;
    };
}