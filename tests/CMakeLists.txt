add_executable(collision main-test.cpp collision-test.cpp)
add_executable(looking main-test.cpp looking-test.cpp)
add_executable(localToWorld main-test.cpp localToWorld-test.cpp)
add_executable(worldToLocal main-test.cpp worldToLocal-test.cpp)
add_executable(reflect main-test.cpp reflect-test.cpp)
add_executable(mesharea main-test.cpp mesharea-test.cpp)
add_executable(turrent main-test.cpp turrent-test.cpp)

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
target_link_libraries(worldToLocal
  PRIVATE
    game
  )
target_link_libraries(reflect
  PRIVATE
    game
  )
target_link_libraries(mesharea
  PRIVATE
    game
  )
target_link_libraries(turrent
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
add_test(
  NAME
    worldToLocal
  COMMAND
    $<TARGET_FILE:worldToLocal>
  )
add_test(
  NAME
    reflect
  COMMAND
    $<TARGET_FILE:reflect>
  )
add_test(
  NAME
    mesharea
  COMMAND
    $<TARGET_FILE:mesharea>
  )
add_test(
  NAME
    turrent
  COMMAND
    $<TARGET_FILE:turrent>
  )
