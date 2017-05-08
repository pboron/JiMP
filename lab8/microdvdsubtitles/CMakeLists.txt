
project(microdvdsubtitles)

set(HEDEAR_FILES MicroDVDSubtitles.h)
set(SOURCE_FILES MicroDVDSubtitles.cpp)

add_library(libmicrodvdsubtitles STATIC ${SOURCE_FILES})
target_include_directories(libmicrodvdsubtitles PUBLIC .)

add_executable(microdvdsubtitles ${SOURCE_FILES} main.cpp)

target_link_libraries(microdvdsubtitles libmicrodvdsubtitles)

