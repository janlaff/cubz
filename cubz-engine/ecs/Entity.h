/*
 * This entity component system is oriented on the tutorial posted here:
 * https://austinmorlan.com/posts/entity_component_system/
 */

#pragma once

// STL
#include <cstdint>
#include <bitset>

namespace cubz::ecs {
    // Entity is simply an index to components
    using Entity = std::uint32_t;
    // Maximum possible count of registered m_entities
    const Entity MAX_ENTITIES = 5000;

    // Component type index
    using ComponentType = std::uint8_t;
    // Maximum possible count of components
    const ComponentType MAX_COMPONENTS = 32;
    // Signature of the components
    using Signature = std::bitset<MAX_COMPONENTS>;
}