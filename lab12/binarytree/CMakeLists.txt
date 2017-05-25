
project(binarytree)

set(HEDEAR_FILES BinaryTree.h)
set(SOURCE_FILES BinaryTree.cpp)

add_library(libbinarytree STATIC ${SOURCE_FILES})
target_include_directories(libbinarytree PUBLIC .)

add_executable(binarytree ${SOURCE_FILES} main.cpp)

target_link_libraries(binarytree libbinarytree)

