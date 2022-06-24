add_executable(Assignment7 main.cpp)

include_directories(include)

add_library(game "")

target_sources(game
  PRIVATE
    Game.cpp
    Algebra.cpp
    Player.cpp
    UnityMesh.cpp
  )

target_link_libraries(Assignment7
  PRIVATE
    game
  )
