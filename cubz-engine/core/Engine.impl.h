//#include "Engine.h"

namespace cubz::core {
    template<typename T, typename ... Args>
    std::shared_ptr<T> Engine::instantiate(Args&&... args) {
        return std::make_shared<T>(this, std::forward<Args>(args)...);
    }
}