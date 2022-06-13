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
  src/TestInitClient.cpp
  src/TestInitCore.cpp
  src/TestInitGame.cpp
  src/TestInitInventory.cpp
  src/TestInitMap.cpp
  src/TestInitServer.cpp
  src/TestInitTeam.cpp
  src/TestInitTrantorian.cpp
  src/TestParseParams.cpp

  ../server/src/manage_struct/manage_client.c
  ../server/src/manage_struct/manage_core.c
  ../server/src/manage_struct/manage_game.c
  ../server/src/manage_struct/manage_inventory.c
  ../server/src/manage_struct/manage_map.c
  ../server/src/manage_struct/manage_server.c
  ../server/src/manage_struct/manage_team.c
  ../server/src/manage_struct/manage_trantorian.c
  ../server/src/utils/parse_params.c
  ../server/src/utils/set_fds.c
  ../server/src/server_handling/server_handling.c
  ../server/src/server_handling/start_server.c
  ../server/src/client_handling/client_update.c
  ../server/src/client_handling/client_def_exec_command.c
  ../server/src/client_handling/default_commands/forward.c
  ../server/src/client_handling/default_commands/right.c
  ../server/src/client_handling/default_commands/left.c
  ../server/src/client_handling/default_commands/look.c
  ../server/src/client_handling/default_commands/inventory.c
  ../server/src/client_handling/default_commands/broadcast.c
  ../server/src/client_handling/default_commands/connect_nbr.c
  ../server/src/client_handling/default_commands/fork.c
  ../server/src/client_handling/default_commands/eject.c
  ../server/src/client_handling/default_commands/take.c
  ../server/src/client_handling/default_commands/set.c
  ../server/src/client_handling/default_commands/incantation.c
  ../server/src/utils/command_utils.c
  ../server/src/client_handling/client_command_utils.c
  ../server/src/client_handling/gui_commands/msz.c
  ../server/src/client_handling/gui_commands/bct.c
  ../server/src/client_handling/gui_commands/mct.c
  ../server/src/client_handling/gui_commands/tna.c
  ../server/src/client_handling/gui_commands/ppo.c
  ../server/src/client_handling/gui_commands/plv.c
  ../server/src/client_handling/gui_commands/pin.c
  ../server/src/client_handling/gui_commands/sgt.c
  ../server/src/client_handling/gui_commands/sst.c
  ../server/src/client_handling/client_define_type.c
  ../server/src/client_handling/client_gui_exec_command.c
)

target_include_directories(unit-tests PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/include/
  ${CMAKE_CURRENT_SOURCE_DIR}/../server/include/
  ${CMAKE_CURRENT_SOURCE_DIR}/../include/
)

target_link_directories(unit-tests
  PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/../libs
)

target_link_libraries(unit-tests
  PRIVATE
  list
  nlib
  uuid
)
target_link_libraries(unit-tests PRIVATE ${CONAN_LIBS})
target_link_libraries(unit-tests PRIVATE ${CMAKE_DL_LIBS})

ENABLE_TESTING()
ADD_TEST(tests bin/unit-tests)
