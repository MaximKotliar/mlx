// Copyright © 2023-2024 Apple Inc.

#pragma once

#include <string>
#include <unordered_map>
#include <variant>

namespace mlx::core::metal {

/* Check if the Metal backend is available. */
bool is_available();

/** Capture a GPU trace, saving it to an absolute file `path` */
void start_capture(std::string path = "");
void stop_capture();

/** Get information about the GPU and system settings. */
const std::unordered_map<std::string, std::variant<std::string, size_t>>&
device_info();

/** Get the maximum command buffer count for command queues.
 * Returns -1 if not set (uses Metal default). */
int max_command_buffer_count();

/** Set the maximum command buffer count for command queues.
 * Set to -1 to use Metal default (unlimited). */
void set_max_command_buffer_count(int count);

} // namespace mlx::core::metal
