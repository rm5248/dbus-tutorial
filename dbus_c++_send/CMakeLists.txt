add_executable(send send.cpp)
target_link_libraries(send ${dbus-cxx_LDFLAGS})
target_include_directories(send PRIVATE ${dbus-cxx_INCLUDE_DIRS})
