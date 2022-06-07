cmake_minimum_required(VERSION 3.10)

# Project name
project(Zappy_Server)

set(CMAKE_CXX_STANDARD 20)

# Conan
include(${CMAKE_CURRENT_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(unit-tests
  src/main.cpp
  src/test_random.cpp
)

target_include_directories(unit-tests PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/include/
  ${CMAKE_CURRENT_SOURCE_DIR}/../server/include/
)

set(LIBS
    -L${CMAKE_CURRENT_SOURCE_DIR}/../libs/
    -llist
    -lnlib
)

target_link_libraries(unit-tests PRIVATE ${LIBS})
target_link_libraries(unit-tests PRIVATE ${CONAN_LIBS})
target_link_libraries(unit-tests PRIVATE ${CMAKE_DL_LIBS})

ENABLE_TESTING()
ADD_TEST(tests bin/unit-tests)
