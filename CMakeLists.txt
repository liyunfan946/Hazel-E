cmake_minimum_required(VERSION 3.10)
project(Hazel-E VERSION 1.0 LANGUAGES CXX)

# 设置C++标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# 设置项目输出目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# 包含目录设置
include_directories(
    ${CMAKE_SOURCE_DIR}/Hazel_E/src
    ${CMAKE_SOURCE_DIR}/Hazel_E/additional/spdlog/include
)

# 添加spdlog子模块头文件路径
add_subdirectory(${CMAKE_SOURCE_DIR}/Hazel_E/additional/spdlog)

# 定义项目库
add_library(Hazel-E SHARED
    ${CMAKE_SOURCE_DIR}/Hazel_E/src/Log.cpp
    ${CMAKE_SOURCE_DIR}/Hazel_E/src/Application.cpp
    ${CMAKE_SOURCE_DIR}/Hazel_E/src/EntryPoint.h
    ${CMAKE_SOURCE_DIR}/Hazel_E/src/event/Event.h
    ${CMAKE_SOURCE_DIR}/Hazel_E/src/event/WindowEvent.h
    ${CMAKE_SOURCE_DIR}/Hazel_E/src/event/ApplicationEvent.h
    ${CMAKE_SOURCE_DIR}/Hazel_E/src/event/KeyEvent.h
    ${CMAKE_SOURCE_DIR}/Hazel_E/src/event/MouseEvent.h)

# 设置预编译头文件
target_precompile_headers(Hazel-E PRIVATE
    "${CMAKE_SOURCE_DIR}/Hazel_E/src/HZPCH.h"
)

# 设置项目库属性
set_target_properties(Hazel-E PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
    CXX_VISIBILITY_PRESET hidden
    VISIBILITY_INLINES_HIDDEN ON
)

# 定义可执行文件
add_executable(T-1
    ${CMAKE_SOURCE_DIR}/T-1/src/stratsandbox.cpp
    ${CMAKE_SOURCE_DIR}/Hazel_E/src/event/Event.h
    ${CMAKE_SOURCE_DIR}/Hazel_E/src/event/WindowEvent.h
    ${CMAKE_SOURCE_DIR}/Hazel_E/src/event/ApplicationEvent.h
    ${CMAKE_SOURCE_DIR}/Hazel_E/src/event/KeyEvent.h
    ${CMAKE_SOURCE_DIR}/Hazel_E/src/event/MouseEvent.h)

# 设置可执行文件的预编译头文件
target_precompile_headers(T-1 PRIVATE
    "${CMAKE_SOURCE_DIR}/Hazel_E/src/HZPCH.h"
)

# 链接库
target_link_libraries(T-1 PRIVATE Hazel-E)

# 编译选项设置
if(MSVC)
    # Windows特定选项
    target_compile_definitions(Hazel-E PRIVATE 
        HZ_PLATFORM_WINDOWS 
        HZ_BUILD_DLL
    )
    target_compile_definitions(T-1 PRIVATE 
        WIN32 
        _WINDOWS 
        UNICODE 
        _UNICODE 
        _CRT_SECURE_NO_WARNINGS
    )
    target_compile_options(Hazel-E PRIVATE /utf-8)
    target_compile_options(T-1 PRIVATE /utf-8)
else()
    # 其他平台选项
    target_compile_definitions(Hazel-E PRIVATE 
        HZ_PLATFORM_LINUX
    )
endif()

# 包含目录设置（更现代的方式）
target_include_directories(Hazel-E PRIVATE
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/Hazel_E/src>
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/Hazel_E/additional/spdlog/include>
)

# 链接spdlog
target_link_libraries(Hazel-E PRIVATE spdlog::spdlog)

# 定义导出宏（如果需要）
if(MSVC)
    target_compile_definitions(Hazel-E PRIVATE HZ_BUILD_DLL)
    target_compile_definitions(T-1 PRIVATE HZ_PLATFORM_WINDOWS)
endif()

# 设置输出目录
set_target_properties(Hazel-E PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

set_target_properties(T-1 PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

# 添加预处理器定义
target_compile_definitions(Hazel-E PRIVATE 
    HZ_PLATFORM_WINDOWS 
    HZ_BUILD_DLL)

# 确保静态成员变量正确链接
# （不需要特殊处理，只要在.cpp中定义即可）

# 添加UTF-8编码支持
if(MSVC)
    target_compile_options(Hazel-E PRIVATE /utf-8)
    target_compile_options(T-1 PRIVATE /utf-8)
endif()

# 编译选项设置
if(MSVC)
    # Windows特定选项
    target_compile_definitions(Hazel-E PRIVATE 
        HZ_PLATFORM_WINDOWS 
        HZ_BUILD_DLL
    )
    target_compile_definitions(T-1 PRIVATE 
        WIN32 
        _WINDOWS 
        UNICODE 
        _UNICODE 
        _CRT_SECURE_NO_WARNINGS
    )
    target_compile_options(Hazel-E PRIVATE /utf-8)
    target_compile_options(T-1 PRIVATE /utf-8)
else()
    # 其他平台选项
    target_compile_definitions(Hazel-E PRIVATE 
        HZ_PLATFORM_LINUX
    )
endif()

# 包含目录设置（更现代的方式）
target_include_directories(Hazel-E PRIVATE
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/Hazel_E/src>
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/Hazel_E/additional/spdlog/include>
)

# 链接spdlog
target_link_libraries(Hazel-E PRIVATE spdlog::spdlog)

# 定义导出宏（如果需要）
if(MSVC)
    target_compile_definitions(Hazel-E PRIVATE HZ_BUILD_DLL)
    target_compile_definitions(T-1 PRIVATE HZ_PLATFORM_WINDOWS)
endif()

# 设置输出目录
set_target_properties(Hazel-E PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

set_target_properties(T-1 PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

# 添加预处理器定义
target_compile_definitions(Hazel-E PRIVATE 
    HZ_PLATFORM_WINDOWS 
    HZ_BUILD_DLL)

# 确保静态成员变量正确链接
# （不需要特殊处理，只要在.cpp中定义即可）

# 添加UTF-8编码支持
if(MSVC)
    target_compile_options(Hazel-E PRIVATE /utf-8)
    target_compile_options(T-1 PRIVATE /utf-8)
endif()

# 禁用不必要的生成项目
set(CMAKE_SKIP_INSTALL_ALL_DEPENDENCY TRUE)
set(CMAKE_SKIP_RPATH TRUE)

# 设置项目版本
set_target_properties(Hazel-E PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION 1
)

# 安装规则（如果需要）
install(TARGETS Hazel-E T-1
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
)