cmake_minimum_required(VERSION 3.10)

find_package(bullet CONFIG REQUIRED)

set(
        PHYSICS_SOURCE_FILES
        PhysicsSystem.cpp
)

add_library(physics STATIC ${PHYSICS_SOURCE_FILES})
target_link_libraries(
        physics
        core
        bullet::Bullet3Common
        bullet::BulletCollision
        bullet::BulletDynamics
        bullet::BulletInverseDynamics
        bullet::BulletSoftBody
        bullet::LinearMath
)