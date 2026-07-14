cmake_minimum_required(VERSION 3.28)

# Принудительно задаем инструменты Visual Studio 2019
set(CMAKE_GENERATOR_TOOLSET "v142" CACHE STRING "Platform Toolset" FORCE)

project(SFMLTest1 LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.1.0
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

add_executable(main src/main.cpp)
target_compile_features(main PRIVATE cxx_std_17)
target_link_libraries(main PRIVATE 
                        SFML::Graphics
                        SFML::Window
                        SFML::System
)

# АВТОМАТИЧЕСКОЕ КОПИРОВАНИЕ DLL В ПАПКУ BIN ПОСЛЕ СБОРКИ
add_custom_command(TARGET main POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:SFML::Graphics>
        $<TARGET_FILE:SFML::Window>
        $<TARGET_FILE:SFML::System>
        ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
    COMMENT "Copying SFML DLLs to execution directory..."
)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT main)