// GameObject.h
#pragma once

#include <unordered_map>
#include <memory>
#include <typeindex>

#include "Component.h"

class GameObject
{
public:
    template <typename T>
    void AddComponent(const T &component);

    template <typename T>
    T *GetComponent();

private:
    std::unordered_map<std::type_index, std::unique_ptr<Component>> components;
};