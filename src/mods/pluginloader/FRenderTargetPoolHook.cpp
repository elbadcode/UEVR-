#include "FRenderTargetPoolHook.hpp"
#include "../mods/VR.hpp"


namespace uevr {
void render_target_pool_hook::activate() {
    const auto& vr = VR::get();
    if (auto& hook = vr->get_render_target_pool_hook(); hook != nullptr) {
        hook->activate();
    }
}

UEVR_IPooledRenderTargetHandle render_target_pool_hook::get_render_target(const wchar_t* name) {
    const auto& vr = VR::get();
    if (auto& hook = vr->get_render_target_pool_hook(); hook != nullptr) {
        return (UEVR_IPooledRenderTargetHandle)hook->get_render_target(name);
    }

    return nullptr;
}

UEVR_FRenderTargetPoolHookFunctions render_target_pool_hook::functions{
    .activate = &render_target_pool_hook::activate, .get_render_target = &render_target_pool_hook::get_render_target};
} // namespace uevr