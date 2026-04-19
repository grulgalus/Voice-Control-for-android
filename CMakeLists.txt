cmake_minimum_required(VERSION 3.20)

project(voice_control_for_android VERSION 1.0.0)

# Geode SDK (žádné add_subdirectory hacky)
find_package(Geode REQUIRED)

# Připojení tvého kódu
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS src/*.cpp)
add_library(${PROJECT_NAME} SHARED ${SOURCES})

# Kouzlo, co to celé spojí
setup_geode_mod(${PROJECT_NAME})
