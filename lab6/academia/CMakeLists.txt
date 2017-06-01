
project(academia)

set(HEDEAR_FILES Student.h StudentRepository.h StudyYear.h)
set(SOURCE_FILES Student.cpp StudentRepository.cpp StudyYear.cpp)

add_library(libacademia STATIC ${SOURCE_FILES})
target_include_directories(libacademia PUBLIC .)

add_executable(academia ${SOURCE_FILES} main.cpp)

target_link_libraries(academia libacademia)

