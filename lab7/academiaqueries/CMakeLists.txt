
project(academiaqueries)

set(HEDEAR_FILES Student.h StudentRepositoryQueries.h StudyYear.h)
set(SOURCE_FILES Student.cpp StudentRepositoryQueries.cpp StudyYear.cpp)

add_library(libacademiaqueries STATIC ${SOURCE_FILES})
target_include_directories(libacademiaqueries PUBLIC .)

add_executable(academiaqueries ${SOURCE_FILES} main.cpp)

target_link_libraries(academiaqueries libacademiaqueries)

