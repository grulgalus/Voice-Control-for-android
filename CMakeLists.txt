cmake_minimum_required(VERSION 3.20)

project(voice_control_for_android)

# Najde nainstalované Geode SDK
find_package(Geode REQUIRED)

# Přidá tvůj hlavní C++ kód
add_library(${PROJECT_NAME} SHARED
    src/main.cpp
)

# Propojí tvůj mód s Geode knihovnami
target_link_libraries(${PROJECT_NAME} Geode::Geode)

# Nastaví mód pro sestavení
setup_geode_mod(${PROJECT_NAME})
