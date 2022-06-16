add_executable(collision main-test.cpp collision-test.cpp)
add_executable(looking main-test.cpp looking-test.cpp)
add_executable(localToWorld main-test.cpp localToWorld-test.cpp)

target_link_libraries(collision
  PRIVATE
    game
  )

target_link_libraries(looking
  PRIVATE
    game
  )

target_link_libraries(localToWorld
  PRIVATE
    game
  )

add_test(
  NAME
    collision
  COMMAND
    $<TARGET_FILE:collision>
  )

add_test(
  NAME
    looking
  COMMAND
    $<TARGET_FILE:looking>
  )

add_test(
  NAME
    localToWorld
  COMMAND
    $<TARGET_FILE:localToWorld>
  )
