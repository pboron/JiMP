
project(repository)

set(HEDEAR_FILES Repository.h)
set(SOURCE_FILES Repository.cpp)

add_library(librepository STATIC ${SOURCE_FILES})
target_include_directories(librepository PUBLIC .)

add_executable(repository ${SOURCE_FILES} main.cpp)

target_link_libraries(repository librepository)

