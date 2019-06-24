#pragma once

#include "Chunk.h"
#include "MeshData.h"

namespace core {
    class Block {
    public:
        enum class Direction {
            north, east, south, west, up, down
        };

        struct Tile {
            int x;
            int y;
        };

        virtual void addToMesh(const Chunk& chunk, int x, int y, int z, MeshData& meshData);
        virtual bool isSolid(Direction direction);

    protected:
        virtual void faceDataUp(int x, int y, int z, MeshData& meshData);
        virtual void faceDataDown(int x, int y, int z, MeshData& meshData);
        virtual void faceDataNorth(int x, int y, int z, MeshData& meshData);
        virtual void faceDataEast(int x, int y, int z, MeshData& meshData);
        virtual void faceDataSouth(int x, int y, int z, MeshData& meshData);
        virtual void faceDataWest(int x, int y, int z, MeshData& meshData);
        virtual void faceUVs(Direction direction, MeshData& meshData);
        virtual Tile getTexturePosition(Direction direction);
    };
}