
set(TARGET hordes)
set(SRC_DIR ./src)
set(SRCS
    src/main.cpp
    src/game.h
    src/game.cpp
)

add_executable(${TARGET} ${SRCS})

target_link_directories(${TARGET} PRIVATE ${SFML_LIBRARY_DIR})
target_include_directories(${TARGET} PRIVATE ${SFML_INCLUDE_DIR} ${SRC_DIR})
target_link_libraries(${TARGET} ${SFML_LIBS})



