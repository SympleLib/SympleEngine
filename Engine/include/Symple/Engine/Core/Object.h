#pragma once

#include <memory>

namespace Symple::Engine
{
    template<typename T>
    using Scope     = std::unique_ptr<T>;

    template<typename T>
    using GlobalRef = std::shared_ptr<T>;

    template<typename T>
    using LocalRef  = std::weak_ptr<T>;


    template<typename T, typename... Args>
    Scope<T> MakeScope(Args&&... args)
    { return std::make_unique(std::forward(args)...); }

    template<typename T, typename... Args>
    GlobalRef<T> MakeRef(Args&&... args)
    { return std::make_shared(std::forward(args)...); }
}