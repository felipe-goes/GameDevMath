add_executable(Assignment2 main.cpp)

include_directories(include)

add_library(game "")

target_sources(game
  PRIVATE
    Game.cpp
    Algebra.cpp
    Player.cpp
  )

target_link_libraries(Assignment2
  PRIVATE
    game
  )
