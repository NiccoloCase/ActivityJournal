# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.24

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/niccolocaselli/Desktop/uni/Laboratorio di programmazione/activityJournal"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/niccolocaselli/Desktop/uni/Laboratorio di programmazione/activityJournal/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/activityJournal.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/activityJournal.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/activityJournal.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/activityJournal.dir/flags.make

CMakeFiles/activityJournal.dir/MyFrame.cpp.o: CMakeFiles/activityJournal.dir/flags.make
CMakeFiles/activityJournal.dir/MyFrame.cpp.o: /Users/niccolocaselli/Desktop/uni/Laboratorio\ di\ programmazione/activityJournal/MyFrame.cpp
CMakeFiles/activityJournal.dir/MyFrame.cpp.o: CMakeFiles/activityJournal.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/niccolocaselli/Desktop/uni/Laboratorio di programmazione/activityJournal/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/activityJournal.dir/MyFrame.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/activityJournal.dir/MyFrame.cpp.o -MF CMakeFiles/activityJournal.dir/MyFrame.cpp.o.d -o CMakeFiles/activityJournal.dir/MyFrame.cpp.o -c "/Users/niccolocaselli/Desktop/uni/Laboratorio di programmazione/activityJournal/MyFrame.cpp"

CMakeFiles/activityJournal.dir/MyFrame.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/activityJournal.dir/MyFrame.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/niccolocaselli/Desktop/uni/Laboratorio di programmazione/activityJournal/MyFrame.cpp" > CMakeFiles/activityJournal.dir/MyFrame.cpp.i

CMakeFiles/activityJournal.dir/MyFrame.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/activityJournal.dir/MyFrame.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/niccolocaselli/Desktop/uni/Laboratorio di programmazione/activityJournal/MyFrame.cpp" -o CMakeFiles/activityJournal.dir/MyFrame.cpp.s

CMakeFiles/activityJournal.dir/MyApp.cpp.o: CMakeFiles/activityJournal.dir/flags.make
CMakeFiles/activityJournal.dir/MyApp.cpp.o: /Users/niccolocaselli/Desktop/uni/Laboratorio\ di\ programmazione/activityJournal/MyApp.cpp
CMakeFiles/activityJournal.dir/MyApp.cpp.o: CMakeFiles/activityJournal.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/niccolocaselli/Desktop/uni/Laboratorio di programmazione/activityJournal/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/activityJournal.dir/MyApp.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/activityJournal.dir/MyApp.cpp.o -MF CMakeFiles/activityJournal.dir/MyApp.cpp.o.d -o CMakeFiles/activityJournal.dir/MyApp.cpp.o -c "/Users/niccolocaselli/Desktop/uni/Laboratorio di programmazione/activityJournal/MyApp.cpp"

CMakeFiles/activityJournal.dir/MyApp.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/activityJournal.dir/MyApp.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/niccolocaselli/Desktop/uni/Laboratorio di programmazione/activityJournal/MyApp.cpp" > CMakeFiles/activityJournal.dir/MyApp.cpp.i

CMakeFiles/activityJournal.dir/MyApp.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/activityJournal.dir/MyApp.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/niccolocaselli/Desktop/uni/Laboratorio di programmazione/activityJournal/MyApp.cpp" -o CMakeFiles/activityJournal.dir/MyApp.cpp.s

CMakeFiles/activityJournal.dir/ActivityManager.cpp.o: CMakeFiles/activityJournal.dir/flags.make
CMakeFiles/activityJournal.dir/ActivityManager.cpp.o: /Users/niccolocaselli/Desktop/uni/Laboratorio\ di\ programmazione/activityJournal/ActivityManager.cpp
CMakeFiles/activityJournal.dir/ActivityManager.cpp.o: CMakeFiles/activityJournal.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/niccolocaselli/Desktop/uni/Laboratorio di programmazione/activityJournal/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/activityJournal.dir/ActivityManager.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/activityJournal.dir/ActivityManager.cpp.o -MF CMakeFiles/activityJournal.dir/ActivityManager.cpp.o.d -o CMakeFiles/activityJournal.dir/ActivityManager.cpp.o -c "/Users/niccolocaselli/Desktop/uni/Laboratorio di programmazione/activityJournal/ActivityManager.cpp"

CMakeFiles/activityJournal.dir/ActivityManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/activityJournal.dir/ActivityManager.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/niccolocaselli/Desktop/uni/Laboratorio di programmazione/activityJournal/ActivityManager.cpp" > CMakeFiles/activityJournal.dir/ActivityManager.cpp.i

CMakeFiles/activityJournal.dir/ActivityManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/activityJournal.dir/ActivityManager.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/niccolocaselli/Desktop/uni/Laboratorio di programmazione/activityJournal/ActivityManager.cpp" -o CMakeFiles/activityJournal.dir/ActivityManager.cpp.s

CMakeFiles/activityJournal.dir/Form.cpp.o: CMakeFiles/activityJournal.dir/flags.make
CMakeFiles/activityJournal.dir/Form.cpp.o: /Users/niccolocaselli/Desktop/uni/Laboratorio\ di\ programmazione/activityJournal/Form.cpp
CMakeFiles/activityJournal.dir/Form.cpp.o: CMakeFiles/activityJournal.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/niccolocaselli/Desktop/uni/Laboratorio di programmazione/activityJournal/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/activityJournal.dir/Form.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/activityJournal.dir/Form.cpp.o -MF CMakeFiles/activityJournal.dir/Form.cpp.o.d -o CMakeFiles/activityJournal.dir/Form.cpp.o -c "/Users/niccolocaselli/Desktop/uni/Laboratorio di programmazione/activityJournal/Form.cpp"

CMakeFiles/activityJournal.dir/Form.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/activityJournal.dir/Form.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/niccolocaselli/Desktop/uni/Laboratorio di programmazione/activityJournal/Form.cpp" > CMakeFiles/activityJournal.dir/Form.cpp.i

CMakeFiles/activityJournal.dir/Form.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/activityJournal.dir/Form.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/niccolocaselli/Desktop/uni/Laboratorio di programmazione/activityJournal/Form.cpp" -o CMakeFiles/activityJournal.dir/Form.cpp.s

# Object files for target activityJournal
activityJournal_OBJECTS = \
"CMakeFiles/activityJournal.dir/MyFrame.cpp.o" \
"CMakeFiles/activityJournal.dir/MyApp.cpp.o" \
"CMakeFiles/activityJournal.dir/ActivityManager.cpp.o" \
"CMakeFiles/activityJournal.dir/Form.cpp.o"

# External object files for target activityJournal
activityJournal_EXTERNAL_OBJECTS =

activityJournal: CMakeFiles/activityJournal.dir/MyFrame.cpp.o
activityJournal: CMakeFiles/activityJournal.dir/MyApp.cpp.o
activityJournal: CMakeFiles/activityJournal.dir/ActivityManager.cpp.o
activityJournal: CMakeFiles/activityJournal.dir/Form.cpp.o
activityJournal: CMakeFiles/activityJournal.dir/build.make
activityJournal: CMakeFiles/activityJournal.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/niccolocaselli/Desktop/uni/Laboratorio di programmazione/activityJournal/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable activityJournal"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/activityJournal.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/activityJournal.dir/build: activityJournal
.PHONY : CMakeFiles/activityJournal.dir/build

CMakeFiles/activityJournal.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/activityJournal.dir/cmake_clean.cmake
.PHONY : CMakeFiles/activityJournal.dir/clean

CMakeFiles/activityJournal.dir/depend:
	cd "/Users/niccolocaselli/Desktop/uni/Laboratorio di programmazione/activityJournal/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/niccolocaselli/Desktop/uni/Laboratorio di programmazione/activityJournal" "/Users/niccolocaselli/Desktop/uni/Laboratorio di programmazione/activityJournal" "/Users/niccolocaselli/Desktop/uni/Laboratorio di programmazione/activityJournal/cmake-build-debug" "/Users/niccolocaselli/Desktop/uni/Laboratorio di programmazione/activityJournal/cmake-build-debug" "/Users/niccolocaselli/Desktop/uni/Laboratorio di programmazione/activityJournal/cmake-build-debug/CMakeFiles/activityJournal.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/activityJournal.dir/depend

