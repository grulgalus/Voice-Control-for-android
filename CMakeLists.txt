cmake_minimum_required(VERSION 3.20)

project(voice_control_for_android)

# TOTO JE TEN TRIK: Vnutí kompilátoru, aby Geode SDK hledal tam, kam ho GitHub Action stáhl
if(DEFINED ENV{GEODE_SDK})
    list(APPEND CMAKE_PREFIX_PATH "$ENV{GEODE_SDK}")
endif()

# Teď už to na 100 % najde
find_package(Geode REQUIRED)

# Přidá tvůj hlavní C++ kód
add_library(${PROJECT_NAME} SHARED
    src/main.cpp
)

# Propojí tvůj mód s Geode knihovnami
target_link_libraries(${PROJECT_NAME} Geode::Geode)

# Nastaví mód pro sestavení
setup_geode_mod(${PROJECT_NAME})
