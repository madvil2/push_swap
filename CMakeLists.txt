cmake_minimum_required(VERSION 3.27)
project(push_swap LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g") # Add debug information

# Define paths
set(SRC_PATH "srcs/")
set(INC_PATH "includes/")
set(LIB_PATH "libft/")
set(OBJ_PATH "${CMAKE_BINARY_DIR}/obj/") # CMake's binary dir for output

# Include directories for compiler
include_directories(${INC_PATH})
include_directories(${LIB_PATH})

# File globs for sources and headers
file(GLOB_RECURSE SRC_FILES "${SRC_PATH}*.c")
file(GLOB_RECURSE HEADER_FILES "${INC_PATH}*.h")

# Add the executable
add_executable(${PROJECT_NAME} ${SRC_FILES} ${HEADER_FILES})


# Link libraries
target_link_libraries(${PROJECT_NAME}
        ${CMAKE_SOURCE_DIR}/${LIB_PATH}libft.a
)
