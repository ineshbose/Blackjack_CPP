cmake_minimum_required(VERSION "3.17.2")
project("Blackjack_CPP")

set(SOURCES src/card.cpp src/dealer.cpp src/deck.cpp src/game.cpp src/main.cpp src/player.cpp src/print.cpp src/statistics.cpp)

add_executable(${SOURCES})
target_include_directories(BLACKJACK PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/headers/)
target_compile_options(BLACKJACK PRIVATE ${FLAGS})

install(TARGETS BLACKJACK
  RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)

install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/data
        DESTINATION ${CMAKE_INSTALL_PREFIX})