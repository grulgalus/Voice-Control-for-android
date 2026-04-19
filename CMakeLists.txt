cmake_minimum_required(VERSION 3.20)

project(voice_control_for_adnroid)

# Najde Geode automaticky bez jakýchkoliv HINTS nebo dalších cest
find_package(Geode REQUIRED)

# Přidá tvůj kód
add_library(${PROJECT_NAME} SHARED
    src/main.cpp
)

# Tohle udělá všechnu černou magii za nás (samo to propojí knihovny i Android)
setup_geode_mod(${PROJECT_NAME})
