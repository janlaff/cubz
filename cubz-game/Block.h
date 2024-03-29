#pragma once

#include "ChunkMeshBuilder.h"

namespace cubz::game {
    class Block {
    public:
        static const float tileSize;

        enum class Direction {
            north, east, south, west, up, down
        };

        struct Tile {
            int x;
            int y;
            float pxWidth = 15.9f; // Fix invalid textures
            float pxHeight = 15.9f;
        };

        virtual void addToMesh(ChunkMeshBuilder& meshBuilder, int x, int y, int z);
        virtual bool isSolid(Direction direction);

    protected:
        virtual void faceDataUp(int x, int y, int z, graphics::Mesh& meshData);
        virtual void faceDataDown(int x, int y, int z, graphics::Mesh& meshData);
        virtual void faceDataNorth(int x, int y, int z, graphics::Mesh& meshData);
        virtual void faceDataEast(int x, int y, int z, graphics::Mesh& meshData);
        virtual void faceDataSouth(int x, int y, int z, graphics::Mesh& meshData);
        virtual void faceDataWest(int x, int y, int z, graphics::Mesh& meshData);
        virtual void faceUVs(Direction direction, graphics::Mesh& meshData);
        virtual Tile getTexturePosition(Direction direction);
    };
}