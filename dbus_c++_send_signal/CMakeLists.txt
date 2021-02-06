add_executable(send_sig send_sig.cpp)
target_link_libraries(send_sig ${dbus-cxx_LDFLAGS})
target_include_directories(send_sig PRIVATE ${dbus-cxx_INCLUDE_DIRS})
