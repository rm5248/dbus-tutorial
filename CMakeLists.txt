cmake_minimum_required(VERSION 3.13)
project(dbus-cxx-tutorial LANGUAGES CXX)

#
# Find dbus-cxx on the system
#
include(FindPkgConfig)
pkg_check_modules(dbus-cxx REQUIRED dbus-cxx-2.0)

#
# Make sure we are c++17
#
set(CMAKE_CXX_STANDARD 17)
set(CXX_STANDARD_REQUIRED ON)

#
# Add in the subdirectories that contain the actual code
#
add_subdirectory(dbus_c++_receive)
add_subdirectory(dbus_c++_send)
add_subdirectory(dbus_c++_notify)
add_subdirectory(dbus_c++_receive_signal)
add_subdirectory(dbus_c++_send_signal)
