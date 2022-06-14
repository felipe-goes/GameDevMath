add_executable(ProjectName main.cpp)

include_directories(include)

add_library(dummylib "")

target_sources(dummylib
  PRIVATE
    DummyLib.cpp
  )

target_link_libraries(ProjectName
  PRIVATE
    dummylib
  )
