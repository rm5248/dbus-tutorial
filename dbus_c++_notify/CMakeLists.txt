add_executable(notify notify.cpp)
target_link_libraries(notify ${dbus-cxx_LDFLAGS})
target_include_directories(notify PRIVATE ${dbus-cxx_INCLUDE_DIRS})
