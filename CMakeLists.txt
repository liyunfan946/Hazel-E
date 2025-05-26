cmake_minimum_required(VERSION 3.10)
project(Hazel-E VERSION 1.0 LANGUAGES CXX)

# 设置解决方案文件夹属性
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

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
    ${CMAKE_SOURCE_DIR}/Hazel_E/additional/glfw/include
    ${CMAKE_SOURCE_DIR}/Hazel_E/src/event
)

# 添加spdlog子模块头文件路径
add_subdirectory(${CMAKE_SOURCE_DIR}/Hazel_E/additional/spdlog)

# 添加GLFW子模块
option(GLFW_BUILD_DOCS OFF)
option(GLFW_BUILD_TESTS OFF)
option(GLFW_BUILD_EXAMPLES OFF)
option(GLFW_INSTALL OFF)
add_subdirectory(${CMAKE_SOURCE_DIR}/Hazel_E/additional/glfw)

# 收集Hazel源文件
file(GLOB_RECURSE HAZEL_SOURCES 
    "${CMAKE_SOURCE_DIR}/Hazel_E/src/*.cpp"
    "${CMAKE_SOURCE_DIR}/Hazel_E/src/*.h"
    "${CMAKE_SOURCE_DIR}/Hazel_E/src/event/*.h"
    "${CMAKE_SOURCE_DIR}/Hazel_E/src/event/*.hpp"
    "${CMAKE_SOURCE_DIR}/Hazel_E/src/event/*.cpp"
)

# 从源文件列表中排除不需要的文件
list(FILTER HAZEL_SOURCES EXCLUDE REGEX ".*_test\.cpp$|.*\.vcxproj.*|.*\.filters$")

# 分离源文件和头文件
set(HAZEL_CPP_FILES)
set(HAZEL_HEADER_FILES)

foreach(file ${HAZEL_SOURCES})
    if (${file} MATCHES ".*\.h$")
        list(APPEND HAZEL_HEADER_FILES ${file})
    else()
        list(APPEND HAZEL_CPP_FILES ${file})
    endif()
endforeach()

# 定义项目库
add_library(Hazel-E SHARED
    ${HAZEL_SOURCES}
    ${HAZEL_HEADERS}
)

# 组织源文件
source_group(TREE ${CMAKE_SOURCE_DIR}/Hazel_E/src FILES ${HAZEL_CPP_FILES} ${HAZEL_HEADER_FILES})

# 为头文件创建筛选器
foreach(header ${HAZEL_HEADER_FILES})
    # 获取相对于src的路径
    file(RELATIVE_PATH header_path "${CMAKE_SOURCE_DIR}/Hazel_E/src" ${header})
    # 获取目录部分
    get_filename_component(header_dir "${header_path}" DIRECTORY)
    # 替换路径分隔符为反斜杠
    string(REPLACE "/" "\\" header_group "${header_dir}")
    # 设置源组
    source_group("Header Files\\${header_group}" FILES ${header})
endforeach()

# 为源文件创建筛选器
foreach(source ${HAZEL_CPP_FILES})
    # 获取相对于src的路径
    file(RELATIVE_PATH source_path "${CMAKE_SOURCE_DIR}/Hazel_E/src" ${source})
    # 获取目录部分
    get_filename_component(source_dir "${source_path}" DIRECTORY)
    # 替换路径分隔符为反斜杠
    string(REPLACE "/" "\\" source_group "${source_dir}")
    # 设置源组
    source_group("Source Files\\${source_group}" FILES ${source})
endforeach()

# 设置项目文件夹
set_property(TARGET Hazel-E PROPERTY FOLDER "Hazel")
set_property(TARGET glfw PROPERTY FOLDER "ThirdParty")
set_property(TARGET spdlog PROPERTY FOLDER "ThirdParty")
set_property(TARGET update_mappings PROPERTY FOLDER "ThirdParty")

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

# 链接GLFW库
target_link_libraries(Hazel-E PRIVATE 
    glfw
    spdlog::spdlog
)

# 收集T-1源文件
file(GLOB_RECURSE T1_SOURCES 
    "${CMAKE_SOURCE_DIR}/T-1/src/*.cpp"
    "${CMAKE_SOURCE_DIR}/T-1/src/*.h"
    "${CMAKE_SOURCE_DIR}/T-1/src/**/*.h"
)

# 分离源文件和头文件
set(T1_CPP_FILES)
set(T1_HEADER_FILES)

foreach(file ${T1_SOURCES})
    if (${file} MATCHES ".*\.h$")
        list(APPEND T1_HEADER_FILES ${file})
    else()
        list(APPEND T1_CPP_FILES ${file})
    endif()
endforeach()

# 定义可执行文件
add_executable(T-1 ${T1_CPP_FILES} ${T1_HEADER_FILES})

# 组织T-1源文件
foreach(source ${T1_CPP_FILES})
    # 获取相对于T-1/src的路径
    file(RELATIVE_PATH source_path "${CMAKE_SOURCE_DIR}/T-1/src" ${source})
    # 获取目录部分
    get_filename_component(source_dir "${source_path}" DIRECTORY)
    # 替换路径分隔符为反斜杠
    string(REPLACE "/" "\\" source_group "${source_dir}")
    # 设置源组
    source_group("Source Files\\${source_group}" FILES ${source})
endforeach()

# 组织T-1头文件
foreach(header ${T1_HEADER_FILES})
    # 获取相对于T-1/src的路径
    file(RELATIVE_PATH header_path "${CMAKE_SOURCE_DIR}/T-1/src" ${header})
    # 获取目录部分
    get_filename_component(header_dir "${header_path}" DIRECTORY)
    # 替换路径分隔符为反斜杠
    string(REPLACE "/" "\\" header_group "${header_dir}")
    # 设置源组
    source_group("Header Files\\${header_group}" FILES ${header})
endforeach()

# 设置项目文件夹
set_property(TARGET T-1 PROPERTY FOLDER "Samples")

# 链接T-1到Hazel-E
target_link_libraries(T-1 PRIVATE Hazel-E)

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