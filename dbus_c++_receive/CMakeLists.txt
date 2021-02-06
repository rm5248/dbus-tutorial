add_executable(receive receive.cpp)
target_link_libraries(receive ${dbus-cxx_LDFLAGS})
target_include_directories(receive PRIVATE ${dbus-cxx_INCLUDE_DIRS})
