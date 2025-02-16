// dllmain
#include "../../include/reshade/reshade.hpp"

#include <cstdint>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/spdlog.h>
#include <windows.h>

#include <utility/Thread.hpp>

#include "Framework.hpp"
#include "ReShadeAddon.hpp"
#include <cassert>
#include <shared_mutex>
#include <sstream>
#include <unordered_set>

// bool reshade_startup(){
//          reshade::register_event<reshade::addon_event::init_swapchain>(on_init_swapchain);
// 		reshade::register_event<reshade::addon_event::destroy_swapchain>(on_destroy_swapchain);
// 		reshade::register_event<reshade::addon_event::init_sampler>(on_init_sampler);
// 		reshade::register_event<reshade::addon_event::destroy_sampler>(on_destroy_sampler);
// 		reshade::register_event<reshade::addon_event::init_resource>(on_init_resource);
// 		reshade::register_event<reshade::addon_event::destroy_resource>(on_destroy_resource);
// 		reshade::register_event<reshade::addon_event::init_resource_view>(on_init_resource_view);
// 		reshade::register_event<reshade::addon_event::destroy_resource_view>(on_destroy_resource_view);
// 		reshade::register_event<reshade::addon_event::init_pipeline>(on_init_pipeline);
// 		reshade::register_event<reshade::addon_event::destroy_pipeline>(on_destroy_pipeline);

// 		reshade::register_event<reshade::addon_event::barrier>(on_barrier);
// 		reshade::register_event<reshade::addon_event::begin_render_pass>(on_begin_render_pass);
// 		reshade::register_event<reshade::addon_event::end_render_pass>(on_end_render_pass);
// 		reshade::register_event<reshade::addon_event::bind_render_targets_and_depth_stencil>(on_bind_render_targets_and_depth_stencil);
// 		reshade::register_event<reshade::addon_event::bind_pipeline>(on_bind_pipeline);
// 		reshade::register_event<reshade::addon_event::bind_pipeline_states>(on_bind_pipeline_states);
// 		reshade::register_event<reshade::addon_event::bind_viewports>(on_bind_viewports);
// 		reshade::register_event<reshade::addon_event::bind_scissor_rects>(on_bind_scissor_rects);
// 		reshade::register_event<reshade::addon_event::push_constants>(on_push_constants);
// 		reshade::register_event<reshade::addon_event::push_descriptors>(on_push_descriptors);
// 		reshade::register_event<reshade::addon_event::bind_descriptor_tables>(on_bind_descriptor_tables);
// 		reshade::register_event<reshade::addon_event::bind_index_buffer>(on_bind_index_buffer);
// 		reshade::register_event<reshade::addon_event::bind_vertex_buffers>(on_bind_vertex_buffers);
// 		reshade::register_event<reshade::addon_event::draw>(on_draw);
// 		reshade::register_event<reshade::addon_event::draw_indexed>(on_draw_indexed);
// 		reshade::register_event<reshade::addon_event::dispatch>(on_dispatch);
// 		reshade::register_event<reshade::addon_event::dispatch_mesh>(on_dispatch_mesh);
// 		reshade::register_event<reshade::addon_event::dispatch_rays>(on_dispatch_rays);
// 		reshade::register_event<reshade::addon_event::draw_or_dispatch_indirect>(on_draw_or_dispatch_indirect);
// 		reshade::register_event<reshade::addon_event::copy_resource>(on_copy_resource);
// 		reshade::register_event<reshade::addon_event::copy_buffer_region>(on_copy_buffer_region);
// 		reshade::register_event<reshade::addon_event::copy_buffer_to_texture>(on_copy_buffer_to_texture);
// 		reshade::register_event<reshade::addon_event::copy_texture_region>(on_copy_texture_region);
// 		reshade::register_event<reshade::addon_event::copy_texture_to_buffer>(on_copy_texture_to_buffer);
// 		reshade::register_event<reshade::addon_event::resolve_texture_region>(on_resolve_texture_region);
// 		reshade::register_event<reshade::addon_event::clear_depth_stencil_view>(on_clear_depth_stencil_view);
// 		reshade::register_event<reshade::addon_event::clear_render_target_view>(on_clear_render_target_view);
// 		reshade::register_event<reshade::addon_event::clear_unordered_access_view_uint>(on_clear_unordered_access_view_uint);
// 		reshade::register_event<reshade::addon_event::clear_unordered_access_view_float>(on_clear_unordered_access_view_float);
// 		reshade::register_event<reshade::addon_event::copy_acceleration_structure>(on_copy_acceleration_structure);
// 		reshade::register_event<reshade::addon_event::build_acceleration_structure>(on_build_acceleration_structure);
// 		reshade::register_event<reshade::addon_event::generate_mipmaps>(on_generate_mipmaps);
// 		reshade::register_event<reshade::addon_event::begin_query>(on_begin_query);
// 		reshade::register_event<reshade::addon_event::end_query>(on_end_query);
// 		reshade::register_event<reshade::addon_event::copy_query_heap_results>(on_copy_query_heap_results);

// 		reshade::register_event<reshade::addon_event::reshade_present>(on_present);
// }

void startup_thread(HMODULE poc_module) {
    g_framework = std::make_unique<Framework>(poc_module);
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD fdwreason, LPVOID) {
    if (fdwreason == DLL_PROCESS_ATTACH) {
        if (!reshade::register_addon(hModule, nullptr))
            return FALSE;
        CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)startup_thread, hModule, 0, nullptr);
    }
    return true;
}

// BOOL APIENTRY DllMain(HANDLE handle, DWORD reason, LPVOID reserved) {
//     if (reason == DLL_PROCESS_ATTACH) {

//         CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)startup_thread, handle, 0, nullptr);
//     }

//     return TRUE;
// }