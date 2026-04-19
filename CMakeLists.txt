cmake_minimum_required(VERSION 3.20)

project(voice_control_for_android)

# ZDE JE TA ZMĚNA: HINTS $ENV{GEODE_SDK} řekne kompilátoru, kde přesně SDK leží
find_package(Geode REQUIRED HINTS $ENV{GEODE_SDK})

# Přidá tvůj hlavní C++ kód
add_library(${PROJECT_NAME} SHARED
    src/main.cpp
)

# Propojí tvůj mód s Geode knihovnami
target_link_libraries(${PROJECT_NAME} Geode::Geode)

# Nastaví mód pro sestavení
setup_geode_mod(${PROJECT_NAME})
