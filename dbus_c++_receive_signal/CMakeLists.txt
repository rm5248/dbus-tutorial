add_executable(recv_sig recv_sig.cpp)
target_link_libraries(recv_sig ${dbus-cxx_LDFLAGS})
target_include_directories(recv_sig PRIVATE ${dbus-cxx_INCLUDE_DIRS})

