#include "Block.h"

namespace core {
    const float tileSize = 0.25f;

    void Block::addToMesh(const core::Chunk &chunk, int x, int y, int z, core::MeshData &meshData) {
        if (!chunk.getBlock(x, y + 1, z)->isSolid(Direction::down)) {
            faceDataUp(x, y, z, meshData);
        }

        if (!chunk.getBlock(x, y - 1, z)->isSolid(Direction::up)) {
            faceDataDown(x, y, z, meshData);
        }

        if (!chunk.getBlock(x, y, z + 1)->isSolid(Direction::south)) {
            faceDataNorth(x, y, z, meshData);
        }

        if (!chunk.getBlock(x, y, z - 1)->isSolid(Direction::north)) {
            faceDataSouth(x, y, z, meshData);
        }

        if (!chunk.getBlock(x + 1, y, z)->isSolid(Direction::west)) {
            faceDataEast(x, y, z, meshData);
        }

        if (!chunk.getBlock(x - 1, y, z)->isSolid(Direction::east)) {
            faceDataWest(x, y, z, meshData);
        }
    }

    bool Block::isSolid(core::Block::Direction direction) {
        // Every side is solid
        return true;
    }

    void Block::faceDataUp(int x, int y, int z, core::MeshData &meshData) {
        meshData.vertices.emplace_back(x - 0.5f, y + 0.5f, z - 0.5f);
        meshData.vertices.emplace_back(x + 0.5f, y + 0.5f, z - 0.5f);
        meshData.vertices.emplace_back(x + 0.5f, y + 0.5f, z + 0.5f);
        meshData.vertices.emplace_back(x - 0.5f, y + 0.5f, z + 0.5f);
        meshData.addQuadTriangles();
        faceUVs(Direction::up, meshData);
    }

    void Block::faceDataDown(int x, int y, int z, core::MeshData &meshData) {
        meshData.vertices.emplace_back(x - 0.5f, y - 0.5f, z + 0.5f);
        meshData.vertices.emplace_back(x + 0.5f, y - 0.5f, z + 0.5f);
        meshData.vertices.emplace_back(x + 0.5f, y - 0.5f, z - 0.5f);
        meshData.vertices.emplace_back(x - 0.5f, y - 0.5f, z - 0.5f);
        meshData.addQuadTriangles();
        faceUVs(Direction::down, meshData);
    }

    void Block::faceDataNorth(int x, int y, int z, core::MeshData &meshData) {
        meshData.vertices.emplace_back(x - 0.5f, y + 0.5f, z + 0.5f);
        meshData.vertices.emplace_back(x + 0.5f, y + 0.5f, z + 0.5f);
        meshData.vertices.emplace_back(x + 0.5f, y - 0.5f, z + 0.5f);
        meshData.vertices.emplace_back(x - 0.5f, y - 0.5f, z + 0.5f);
        meshData.addQuadTriangles();
        faceUVs(Direction::north, meshData);
    }

    void Block::faceDataSouth(int x, int y, int z, core::MeshData &meshData) {
        meshData.vertices.emplace_back(x + 0.5f, y + 0.5f, z - 0.5f);
        meshData.vertices.emplace_back(x - 0.5f, y + 0.5f, z - 0.5f);
        meshData.vertices.emplace_back(x - 0.5f, y - 0.5f, z - 0.5f);
        meshData.vertices.emplace_back(x + 0.5f, y - 0.5f, z - 0.5f);
        meshData.addQuadTriangles();
        faceUVs(Direction::south, meshData);
    }

    void Block::faceDataEast(int x, int y, int z, core::MeshData &meshData) {
        meshData.vertices.emplace_back(x + 0.5f, y + 0.5f, z + 0.5f);
        meshData.vertices.emplace_back(x + 0.5f, y + 0.5f, z - 0.5f);
        meshData.vertices.emplace_back(x + 0.5f, y - 0.5f, z - 0.5f);
        meshData.vertices.emplace_back(x + 0.5f, y - 0.5f, z + 0.5f);
        meshData.addQuadTriangles();
        faceUVs(Direction::east, meshData);
    }

    void Block::faceDataWest(int x, int y, int z, core::MeshData &meshData) {
        meshData.vertices.emplace_back(x - 0.5f, y + 0.5f, z - 0.5f);
        meshData.vertices.emplace_back(x - 0.5f, y + 0.5f, z + 0.5f);
        meshData.vertices.emplace_back(x - 0.5f, y - 0.5f, z + 0.5f);
        meshData.vertices.emplace_back(x - 0.5f, y - 0.5f, z - 0.5f);
        meshData.addQuadTriangles();
        faceUVs(Direction::west, meshData);
    }

    Block::Tile Block::getTexturePosition(core::Block::Direction direction) {
        return { 0, 0 };
    }

    void Block::faceUVs(core::Block::Direction direction, core::MeshData &meshData) {
        auto tilePos = getTexturePosition(direction);

        meshData.uvs.emplace_back(tileSize * tilePos.x, tileSize * tilePos.y);
        meshData.uvs.emplace_back(tileSize * tilePos.x + tileSize, tileSize * tilePos.y);
        meshData.uvs.emplace_back(tileSize * tilePos.x + tileSize, tileSize * tilePos.y + tileSize);
        meshData.uvs.emplace_back(tileSize * tilePos.x, tileSize * tilePos.y + tileSize);
    }
}