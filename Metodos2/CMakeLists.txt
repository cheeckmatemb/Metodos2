cmake_minimum_required(VERSION 3.10)
project(BusquedaSecuencial LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(BusquedaSecuencial
    src/main.cpp
    src/BusquedaArreglo.cpp
    src/BusquedaCentinela.cpp
    src/ListaEnlazada.cpp
    src/Menu.cpp
)

if(MSVC)
    target_compile_options(BusquedaSecuencial PRIVATE /utf-8 /W4)
    target_compile_definitions(BusquedaSecuencial PRIVATE _CRT_SECURE_NO_WARNINGS)
endif()
