add_executable(dummy main-test.cpp)

target_link_libraries(dummy
  PRIVATE
    dummylib
  )

add_test(
  NAME
    dummy
  COMMAND
    $<TARGET_FILE:dummy>
  )
