cmake_minimum_required(VERSION 3.20)

project(voice_control_for_android)

# Najdi SDK přímo přes CLI (tohle vyřeší tu chybu s chybějícím FindGeode)
find_package(Geode REQUIRED HINTS ${CMAKE_CURRENT_SOURCE_DIR}/geode)

# Přidá tvůj hlavní C++ kód
add_library(${PROJECT_NAME} SHARED
    src/main.cpp
)

# Propojí tvůj mód s Geode knihovnami
target_link_libraries(${PROJECT_NAME} Geode::Geode)

# Nastaví mód pro sestavení (s novou syntaxí)
setup_geode_mod(${PROJECT_NAME})
