#pragma once

#include <string_view>
#include <unordered_map>

#include "SDK/Recv.h"

class Netvars final {
public:
    Netvars() noexcept;

    auto operator[](const std::string_view netvar) noexcept
    {
        return offsets[netvar];
    }
private:
    void loadTable(RecvTable*, const std::size_t = 0) noexcept;
    void hookProperty(RecvProp*, recvProxy) noexcept;
    std::unordered_map<std::string_view, std::size_t> offsets;
};

extern Netvars netvars;
