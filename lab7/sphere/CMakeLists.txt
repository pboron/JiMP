
project(sphere)

set(HEDEAR_FILES Sphere.h)
set(SOURCE_FILES Sphere.cpp)

add_library(libsphere STATIC ${SOURCE_FILES})
target_include_directories(libsphere PUBLIC .)

add_executable(sphere ${SOURCE_FILES} main.cpp)

target_link_libraries(sphere libsphere)

