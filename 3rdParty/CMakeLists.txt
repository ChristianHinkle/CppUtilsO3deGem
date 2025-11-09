# Copyright (c) 2023-2025 Christian Hinkle, Brian Hinkle.

include(FetchContent)

FetchContent_Declare(CppUtils
    SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/CppUtils"
)

FetchContent_MakeAvailable(CppUtils)
