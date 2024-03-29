#include "Block.h"

namespace cubz::game {
    const float Block::tileSize = 1.0f / 16.0f;

    void Block::addToMesh(ChunkMeshBuilder& meshBuilder, int x, int y, int z) {
        if (!meshBuilder.getBlock(x, y + 1, z)->isSolid(Direction::down)) {
            faceDataUp(x, y, z, meshBuilder.getMesh());
        }

        if (!meshBuilder.getBlock(x, y - 1, z)->isSolid(Direction::up)) {
            faceDataDown(x, y, z, meshBuilder.getMesh());
        }

        if (!meshBuilder.getBlock(x, y, z + 1)->isSolid(Direction::south)) {
            faceDataNorth(x, y, z, meshBuilder.getMesh());
        }

        if (!meshBuilder.getBlock(x, y, z - 1)->isSolid(Direction::north)) {
            faceDataSouth(x, y, z, meshBuilder.getMesh());
        }

        if (!meshBuilder.getBlock(x + 1, y, z)->isSolid(Direction::west)) {
            faceDataEast(x, y, z, meshBuilder.getMesh());
        }

        if (!meshBuilder.getBlock(x - 1, y, z)->isSolid(Direction::east)) {
            faceDataWest(x, y, z, meshBuilder.getMesh());
        }
    }

    bool Block::isSolid(Block::Direction direction) {
        // Every side is solid
        return true;
    }

    void Block::faceDataUp(int x, int y, int z, graphics::Mesh &meshData) {
        meshData.vertices.emplace_back(x - 0.5f, y + 0.5f, z - 0.5f);
        meshData.vertices.emplace_back(x + 0.5f, y + 0.5f, z - 0.5f);
        meshData.vertices.emplace_back(x + 0.5f, y + 0.5f, z + 0.5f);
        meshData.vertices.emplace_back(x - 0.5f, y + 0.5f, z + 0.5f);
        meshData.addQuadTriangles();
        meshData.addQuadNormals(glm::vec3(0, 1, 0));
        faceUVs(Direction::up, meshData);
    }

    void Block::faceDataDown(int x, int y, int z, graphics::Mesh &meshData) {
        meshData.vertices.emplace_back(x - 0.5f, y - 0.5f, z + 0.5f);
        meshData.vertices.emplace_back(x + 0.5f, y - 0.5f, z + 0.5f);
        meshData.vertices.emplace_back(x + 0.5f, y - 0.5f, z - 0.5f);
        meshData.vertices.emplace_back(x - 0.5f, y - 0.5f, z - 0.5f);
        meshData.addQuadTriangles();
        meshData.addQuadNormals(glm::vec3(0, -1, 0));
        faceUVs(Direction::down, meshData);
    }

    void Block::faceDataNorth(int x, int y, int z, graphics::Mesh &meshData) {
        meshData.vertices.emplace_back(x - 0.5f, y + 0.5f, z + 0.5f);
        meshData.vertices.emplace_back(x + 0.5f, y + 0.5f, z + 0.5f);
        meshData.vertices.emplace_back(x + 0.5f, y - 0.5f, z + 0.5f);
        meshData.vertices.emplace_back(x - 0.5f, y - 0.5f, z + 0.5f);
        meshData.addQuadTriangles();
        meshData.addQuadNormals(glm::vec3(0, 0, 1));
        faceUVs(Direction::north, meshData);
    }

    void Block::faceDataSouth(int x, int y, int z, graphics::Mesh &meshData) {
        meshData.vertices.emplace_back(x + 0.5f, y + 0.5f, z - 0.5f);
        meshData.vertices.emplace_back(x - 0.5f, y + 0.5f, z - 0.5f);
        meshData.vertices.emplace_back(x - 0.5f, y - 0.5f, z - 0.5f);
        meshData.vertices.emplace_back(x + 0.5f, y - 0.5f, z - 0.5f);
        meshData.addQuadTriangles();
        meshData.addQuadNormals(glm::vec3(0, 0, -1));
        faceUVs(Direction::south, meshData);
    }

    void Block::faceDataEast(int x, int y, int z, graphics::Mesh &meshData) {
        meshData.vertices.emplace_back(x + 0.5f, y + 0.5f, z + 0.5f);
        meshData.vertices.emplace_back(x + 0.5f, y + 0.5f, z - 0.5f);
        meshData.vertices.emplace_back(x + 0.5f, y - 0.5f, z - 0.5f);
        meshData.vertices.emplace_back(x + 0.5f, y - 0.5f, z + 0.5f);
        meshData.addQuadTriangles();
        meshData.addQuadNormals(glm::vec3(1, 0, 0));
        faceUVs(Direction::east, meshData);
    }

    void Block::faceDataWest(int x, int y, int z, graphics::Mesh &meshData) {
        meshData.vertices.emplace_back(x - 0.5f, y + 0.5f, z - 0.5f);
        meshData.vertices.emplace_back(x - 0.5f, y + 0.5f, z + 0.5f);
        meshData.vertices.emplace_back(x - 0.5f, y - 0.5f, z + 0.5f);
        meshData.vertices.emplace_back(x - 0.5f, y - 0.5f, z - 0.5f);
        meshData.addQuadTriangles();
        meshData.addQuadNormals(glm::vec3(-1, 0, 0));
        faceUVs(Direction::west, meshData);
    }

    Block::Tile Block::getTexturePosition(Block::Direction direction) {
        return { 0, 0 };
    }

    void Block::faceUVs(Block::Direction direction, graphics::Mesh &meshData) {
        auto tile = getTexturePosition(direction);
        auto pixelSize = tileSize * tileSize;
        auto marginTop = (16.0f - tile.pxHeight) / 2.0f * pixelSize;
        auto marginLeft = (16.0f - tile.pxWidth) / 2.0f * pixelSize;

        meshData.uvs.emplace_back(tileSize * tile.x + marginLeft, tileSize * tile.y + marginTop);
        meshData.uvs.emplace_back(tileSize * tile.x + tileSize - marginLeft, tileSize * tile.y + marginTop);
        meshData.uvs.emplace_back(tileSize * tile.x + tileSize - marginLeft, tileSize * tile.y + tileSize);
        meshData.uvs.emplace_back(tileSize * tile.x + marginLeft, tileSize * tile.y + tileSize);
    }
}