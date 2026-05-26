# CMakeList.txt: proyecto de CMake para Metodos2, incluya el origen y defina
# la lógica específica del proyecto aquí.
#

# Agregue un origen al ejecutable de este proyecto.
add_executable (Metodos2 "Metodos2.cpp" "Metodos2.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Metodos2 PROPERTY CXX_STANDARD 20)
endif()

# TODO: Agregue pruebas y destinos de instalación si es necesario.
