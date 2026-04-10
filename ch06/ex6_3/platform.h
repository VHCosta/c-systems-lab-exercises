#ifndef PLATFORM_H
#define PLATFORM_H

/* TODO: detect the OS using predefined macros and define:
 *   PLATFORM_LINUX   (when __linux__ is set)
 *   PLATFORM_MACOS   (when __APPLE__ is set)
 *   PLATFORM_WINDOWS (when _WIN32 or _WIN64 is set)
 *   PLATFORM_NAME    (string: "linux", "macos", or "windows")
 * Use #error if no known OS is detected. */

/* TODO: detect pointer width and define either:
 *   PLATFORM_64BIT (pointer size is 8 bytes)
 *   PLATFORM_32BIT (pointer size is 4 bytes) */

#endif /* PLATFORM_H */
