
project(zipperiterator)

set(HEDEAR_FILES Zipper.h Iterator.h)
set(SOURCE_FILES Zipper.cpp Iterator.cpp)

add_library(libzipperiterator STATIC ${SOURCE_FILES})
target_include_directories(libzipperiterator PUBLIC .)

add_executable(zipperiterator ${SOURCE_FILES} main.cpp)

target_link_libraries(zipperiterator libzipperiterator)

