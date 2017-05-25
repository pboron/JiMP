
project(unorderedmap)

set(HEDEAR_FILES UnorderedMap.h)
set(SOURCE_FILES UnorderedMap.cpp)

add_library(libunorderedmap STATIC ${SOURCE_FILES})
target_include_directories(libunorderedmap PUBLIC .)

add_executable(unorderedmap ${SOURCE_FILES} main.cpp)

target_link_libraries(unorderedmap libunorderedmap)

