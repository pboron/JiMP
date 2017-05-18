
project(mean)

set(HEDEAR_FILES Mean.h)
set(SOURCE_FILES Mean.cpp)

add_library(libmean STATIC ${SOURCE_FILES})
target_include_directories(libmean PUBLIC .)

add_executable(mean ${SOURCE_FILES} main.cpp)

target_link_libraries(mean libmean)

