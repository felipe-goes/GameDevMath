add_executable(collision main-test.cpp collision-test.cpp)

target_link_libraries(collision
  PRIVATE
    game
  )

add_test(
  NAME
    collision
  COMMAND
    $<TARGET_FILE:collision>
  )
