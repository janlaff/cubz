#include "TorchBlock.h"

namespace cubz::game {
    void TorchBlock::addToMesh(const Chunk &chunk, int x, int y, int z, graphics::Mesh &meshData) {
        faceDataNorth(x, y, z, meshData);
        faceDataEast(x, y, z, meshData);
    }

    bool TorchBlock::isSolid(Block::Direction direction) {
        return false;
    }

    Block::Tile TorchBlock::getTexturePosition(TorchBlock::Direction direction) {
        return { 0, 5, 4, 11 };
    }

    void TorchBlock::faceDataNorth(int x, int y, int z, graphics::Mesh &meshData) {
        meshData.vertices.emplace_back(x - 0.1f, y + 0.4f, z + 0.1f);
        meshData.vertices.emplace_back(x + 0.1f, y + 0.4f, z - 0.1f);
        meshData.vertices.emplace_back(x + 0.1f, y - 0.5f, z - 0.1f);
        meshData.vertices.emplace_back(x - 0.1f, y - 0.5f, z + 0.1f);
        meshData.addQuadTriangles();
        meshData.addQuadNormals(glm::vec3(1, 0, 1)); // Check if shader option could fix this
        faceUVs(Direction::north, meshData);
    }

    void TorchBlock::faceDataEast(int x, int y, int z, graphics::Mesh &meshData) {
        meshData.vertices.emplace_back(x + 0.1f, y + 0.4f, z + 0.1f);
        meshData.vertices.emplace_back(x - 0.1f, y + 0.4f, z - 0.1f);
        meshData.vertices.emplace_back(x - 0.1f, y - 0.5f, z - 0.1f);
        meshData.vertices.emplace_back(x + 0.1f, y - 0.5f, z + 0.1f);
        meshData.addQuadTriangles();
        meshData.addQuadNormals(glm::vec3(1, 0, 0));
        faceUVs(Direction::east, meshData);
    }
}