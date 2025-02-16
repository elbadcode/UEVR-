#include  "../../include/reshade/reshade.hpp"
#include "../../include/reshade/reshade_api.hpp"
#include "../../include/reshade/reshade_events.hpp"
#include "../../include/reshade/reshade_events.hpp"
#include "../../include/reshade/reshade_api_device.hpp"
#include "../../include/reshade/reshade_api_resource.hpp"
#include "../../include/reshade/reshade_api_format.hpp"
#include "../../include/reshade/reshade_api_pipeline.hpp"




// class reshadevr;
// static void on_init_swapchain(swapchain *swapchain);

// static void on_destroy_swapchain(swapchain *swapchain);

// static void on_init_sampler(device *device, const sampler_desc &desc, sampler handle);

// static void on_destroy_sampler(device *device, sampler handle);

// static void on_init_resource(device *device, const resource_desc &desc, const subresource_data *, resource_usage, resource handle);

// static void on_destroy_resource(device *device, resource handle);

// static void on_init_resource_view(device *device, resource resource, resource_usage usage_type, const resource_view_desc &desc, resource_view handle);

// static void on_destroy_resource_view(device *device, resource_view handle);

// static void on_init_pipeline(device *device, pipeline_layout, uint32_t, const pipeline_subobject *, pipeline handle);

// static void on_destroy_pipeline(device *device, pipeline handle);

// static void on_barrier(command_list *, uint32_t num_resources, const resource *resources, const resource_usage *old_states, const resource_usage *new_states);

// static void on_begin_render_pass(command_list *, uint32_t count, const render_pass_render_target_desc *rts, const render_pass_depth_stencil_desc *ds);

// static void on_end_render_pass(command_list *);

// static void on_bind_render_targets_and_depth_stencil(command_list *, uint32_t count, const resource_view *rtvs, resource_view dsv);

// static void on_bind_pipeline(command_list *, pipeline_stage type, pipeline pipeline);

// static void on_bind_pipeline_states(command_list *, uint32_t count, const dynamic_state *states, const uint32_t *values);

// static void on_bind_viewports(command_list *, uint32_t first, uint32_t count, const viewport *viewports);

// static void on_bind_scissor_rects(command_list *, uint32_t first, uint32_t count, const rect *rects);

// static void on_push_constants(command_list *, shader_stage stages, pipeline_layout layout, uint32_t param_index, uint32_t first, uint32_t count, const void *values);

// static void on_push_descriptors(command_list *, shader_stage stages, pipeline_layout layout, uint32_t param_index, const descriptor_table_update &update);

// static void on_bind_descriptor_tables(command_list *, shader_stage stages, pipeline_layout layout, uint32_t first, uint32_t count, const descriptor_table *tables);

// static void on_bind_index_buffer(command_list *, resource buffer, uint64_t offset, uint32_t index_size);

// static void on_bind_vertex_buffers(command_list *, uint32_t first, uint32_t count, const resource *buffers, const uint64_t *offsets, const uint32_t *strides);

// static bool on_draw(command_list *, uint32_t vertices, uint32_t instances, uint32_t first_vertex, uint32_t first_instance);

// static bool on_draw_indexed(command_list *, uint32_t indices, uint32_t instances, uint32_t first_index, int32_t vertex_offset, uint32_t first_instance);

// static bool on_dispatch(command_list *, uint32_t group_count_x, uint32_t group_count_y, uint32_t group_count_z);

// static bool on_dispatch_mesh(command_list *, uint32_t group_count_x, uint32_t group_count_y, uint32_t group_count_z);

// static bool on_dispatch_rays(command_list *, resource raygen, uint64_t raygen_offset, uint64_t raygen_size, resource miss, uint64_t miss_offset, uint64_t miss_size, uint64_t miss_stride, resource hit_group, uint64_t hit_group_offset, uint64_t hit_group_size, uint64_t hit_group_stride, resource callable, uint64_t callable_offset, uint64_t callable_size, uint64_t callable_stride, uint32_t width, uint32_t height, uint32_t depth);

// static bool on_draw_or_dispatch_indirect(command_list *, indirect_command type, resource buffer, uint64_t offset, uint32_t draw_count, uint32_t stride);

// static bool on_copy_resource(command_list *, resource src, resource dst);

// static bool on_copy_buffer_region(command_list *, resource src, uint64_t src_offset, resource dst, uint64_t dst_offset, uint64_t size);

// static bool on_copy_buffer_to_texture(command_list *, resource src, uint64_t src_offset, uint32_t row_length, uint32_t slice_height, resource dst, uint32_t dst_subresource, const subresource_box *);

// static bool on_copy_texture_region(command_list *, resource src, uint32_t src_subresource, const subresource_box *, resource dst, uint32_t dst_subresource, const subresource_box *, filter_mode filter);

// static bool on_copy_texture_to_buffer(command_list *, resource src, uint32_t src_subresource, const subresource_box *, resource dst, uint64_t dst_offset, uint32_t row_length, uint32_t slice_height);

// static bool on_resolve_texture_region(command_list *, resource src, uint32_t src_subresource, const subresource_box *, resource dst, uint32_t dst_subresource, uint32_t dst_x, uint32_t dst_y, uint32_t dst_z, format format);

// static bool on_clear_depth_stencil_view(command_list *, resource_view dsv, const float *depth, const uint8_t *stencil, uint32_t, const rect *);

// static bool on_clear_render_target_view(command_list *, resource_view rtv, const float color[4], uint32_t, const rect *);

// static bool on_clear_unordered_access_view_uint(command_list *, resource_view uav, const uint32_t values[4], uint32_t, const rect *);

// static bool on_clear_unordered_access_view_float(command_list *, resource_view uav, const float values[4], uint32_t, const rect *);

// static bool on_copy_acceleration_structure(command_list *, resource_view source, resource_view dest, acceleration_structure_copy_mode mode);

// static bool on_build_acceleration_structure(command_list *, acceleration_structure_type type, acceleration_structure_build_flags flags, uint32_t input_count, const acceleration_structure_build_input *inputs, resource scratch, uint64_t scratch_offset, resource_view source, resource_view dest, acceleration_structure_build_mode mode);

// static bool on_generate_mipmaps(command_list *, resource_view srv);

// static bool on_begin_query(command_list *cmd_list, query_heap heap, query_type type, uint32_t index);

// static bool on_end_query(command_list *cmd_list, query_heap heap, query_type type, uint32_t index);

// static bool on_copy_query_heap_results(command_list *cmd_list, query_heap heap, query_type type, uint32_t first, uint32_t count, resource dest, uint64_t dest_offset, uint32_t stride);

// static void on_present(effect_runtime *runtime);
