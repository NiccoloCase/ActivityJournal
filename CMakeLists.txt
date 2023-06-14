cmake_minimum_required(VERSION 3.8)
project(activityJournal)

set(CMAKE_CXX_STANDARD 11)

find_package(wxWidgets REQUIRED net gl core base)
include(${wxWidgets_USE_FILE})

add_executable(activityJournal main.cpp MyScrollView.h)
target_link_libraries(activityJournal ${wxWidgets_LIBRARIES})