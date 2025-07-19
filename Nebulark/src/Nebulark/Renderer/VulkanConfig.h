#pragma once
#include <vector>

namespace Nebulark
{
    constexpr bool enableValidationLayers =
#ifdef NDEBUG
        false;
#else
        true;
#endif

    inline const std::vector<const char*> validationLayers = {
        "VK_LAYER_KHRONOS_validation"
    };
}
