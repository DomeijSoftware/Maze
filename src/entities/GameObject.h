// GameObject.h
#pragma once

#include <unordered_map>
#include <memory>
#include <typeindex>

#include "../components/Component.h"
#include "../components/TransformComponent.h"
#include "../components/SpriteComponent.h"

class GameObject
{
public:
    template <typename T>
    void AddComponent(std::unique_ptr<T> component)
    {
        static_assert(std::is_base_of<Component, T>::value, "T must derive from Component");
        components[typeid(T)] = std::move(component);
    }

    template <typename T>
    T *GetComponent()
    {
        if (auto it = components.find(typeid(T)) != components.end())
            return static_cast<T *>(it->second.get());
        return nullptr;
    }

private:
    std::unordered_map<std::type_index, std::unique_ptr<Component>> components;

    template <typename T>
    bool HasComponent() const
    {
        return components.find(typeid(T)) != components.end();
    }
};
