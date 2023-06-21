cmake_minimum_required(VERSION 3.8)
project(activityJournal)
set(CMAKE_CXX_STANDARD 11)

# WX WIDGETS
find_package(wxWidgets REQUIRED net gl core base)
include(${wxWidgets_USE_FILE})

# UNIT TESTING
add_subdirectory(test)


#add_executable(activityJournal MyScrollView.h MyFrame.cpp MyFrame.h MyApp.cpp MyApp.h ActivityManager.cpp ActivityManager.h Utils.h Day.h Activity.h Form.cpp Form.h Subject.h Observer.h)
#target_link_libraries(activityJournal ${wxWidgets_LIBRARIES})



set(SOURCE_FILES MyScrollView.h MyFrame.cpp MyFrame.h ActivityManager.cpp ActivityManager.h Utils.h Day.h Activity.h Form.cpp Form.h Subject.h Observer.h)
add_executable(activityJournal MyApp.cpp MyApp.h)
add_library(core ${SOURCE_FILES})
target_link_libraries(activityJournal ${wxWidgets_LIBRARIES} core)


####add_executable(activityJournal MyScrollView.h MyFrame.cpp MyFrame.h MyApp.cpp MyApp.h ActivityManager.cpp ActivityManager.h Utils.h Day.h Activity.h Form.cpp Form.h Subject.h Observer.h)
####target_link_libraries(activityJournal ${wxWidgets_LIBRARIES})