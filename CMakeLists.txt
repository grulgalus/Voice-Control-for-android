cmake_minimum_required(VERSION 3.20)

project(voice_control_for_android VERSION 1.0.0)

# Žádné hacky s cestami. Čisté nalezení SDK.
find_package(Geode REQUIRED)

# Nalezení a spojení tvých .cpp souborů do jedné knihovny
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS src/*.cpp)
add_library(${PROJECT_NAME} SHARED ${SOURCES})

# Provedení všech Geode maker
setup_geode_mod(${PROJECT_NAME})
