
set(TARGET hordes)
set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(STATES_SRC_DIR ${SRC_DIR}/states)
set(ENTITIES_SRC_DIR ${SRC_DIR}/entities)
set(SRCS
    src/main.cpp
    src/game.h
    src/game.cpp
    src/algorithm.h
    ${ENTITIES_SRC_DIR}/entity.h
    ${ENTITIES_SRC_DIR}/hero.h
    ${ENTITIES_SRC_DIR}/hero.cpp
    ${STATES_SRC_DIR}/state.h
    ${STATES_SRC_DIR}/state.cpp
    ${STATES_SRC_DIR}/game_state.h
    ${STATES_SRC_DIR}/game_state.cpp
)

set(PROJECT_RESOURCE_DIR ./resources)
message(STATUS "PROJECT_RESOURCE_DIR = ${PROJECT_RESOURCE_DIR}")
message(STATUS "SRC_DIR = ${SRC_DIR}")

get_filename_component(RESOURCE_DIR ${PROJECT_RESOURCE_DIR} REALPATH)
configure_file(conf.h.in ${SRC_DIR}/conf.h)

add_executable(${TARGET} ${SRCS})

target_link_directories(${TARGET} PRIVATE ${SFML_LIBRARY_DIR})
target_include_directories(${TARGET} PRIVATE ${SFML_INCLUDE_DIR} ${SRC_DIR})
target_link_libraries(${TARGET} ${SFML_LIBS})



