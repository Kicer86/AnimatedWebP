
cmake_minimum_required(VERSION 3.16)

find_package(Qt6 COMPONENTS Gui)
if (NOT Qt6_FOUND)
    find_package(Qt5 5.15 REQUIRED COMPONENTS Gui)
endif()

find_package(WebP CONFIG QUIET)

if(WebP_FOUND)
    set(WEBP_LIBRARIES WebP::libwebpmux)
else()
    find_package(PkgConfig REQUIRED)

    pkg_check_modules(WEBP REQUIRED libwebpmux)
endif()

include(GenerateExportHeader)

add_library(AnimatedWebP
    webp_generator.cpp
)

target_link_libraries(AnimatedWebP
    PUBLIC
        Qt::Gui
    PRIVATE
        ${WEBP_LIBRARIES}
)

target_include_directories(AnimatedWebP
    PUBLIC
        ${CMAKE_CURRENT_BINARY_DIR}
    INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}
)

generate_export_header(AnimatedWebP)

install(TARGETS AnimatedWebP)
