# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /export/servers/mixer2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /export/servers/mixer2/build

# Include any dependencies generated for this target.
include CMakeFiles/mixer_server.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/mixer_server.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/mixer_server.dir/flags.make

CMakeFiles/mixer_server.dir/test.cpp.o: CMakeFiles/mixer_server.dir/flags.make
CMakeFiles/mixer_server.dir/test.cpp.o: ../test.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /export/servers/mixer2/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/mixer_server.dir/test.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/mixer_server.dir/test.cpp.o -c /export/servers/mixer2/test.cpp

CMakeFiles/mixer_server.dir/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mixer_server.dir/test.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /export/servers/mixer2/test.cpp > CMakeFiles/mixer_server.dir/test.cpp.i

CMakeFiles/mixer_server.dir/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mixer_server.dir/test.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /export/servers/mixer2/test.cpp -o CMakeFiles/mixer_server.dir/test.cpp.s

CMakeFiles/mixer_server.dir/test.cpp.o.requires:
.PHONY : CMakeFiles/mixer_server.dir/test.cpp.o.requires

CMakeFiles/mixer_server.dir/test.cpp.o.provides: CMakeFiles/mixer_server.dir/test.cpp.o.requires
	$(MAKE) -f CMakeFiles/mixer_server.dir/build.make CMakeFiles/mixer_server.dir/test.cpp.o.provides.build
.PHONY : CMakeFiles/mixer_server.dir/test.cpp.o.provides

CMakeFiles/mixer_server.dir/test.cpp.o.provides.build: CMakeFiles/mixer_server.dir/test.cpp.o

CMakeFiles/mixer_server.dir/httpclient.cpp.o: CMakeFiles/mixer_server.dir/flags.make
CMakeFiles/mixer_server.dir/httpclient.cpp.o: ../httpclient.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /export/servers/mixer2/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/mixer_server.dir/httpclient.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/mixer_server.dir/httpclient.cpp.o -c /export/servers/mixer2/httpclient.cpp

CMakeFiles/mixer_server.dir/httpclient.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mixer_server.dir/httpclient.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /export/servers/mixer2/httpclient.cpp > CMakeFiles/mixer_server.dir/httpclient.cpp.i

CMakeFiles/mixer_server.dir/httpclient.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mixer_server.dir/httpclient.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /export/servers/mixer2/httpclient.cpp -o CMakeFiles/mixer_server.dir/httpclient.cpp.s

CMakeFiles/mixer_server.dir/httpclient.cpp.o.requires:
.PHONY : CMakeFiles/mixer_server.dir/httpclient.cpp.o.requires

CMakeFiles/mixer_server.dir/httpclient.cpp.o.provides: CMakeFiles/mixer_server.dir/httpclient.cpp.o.requires
	$(MAKE) -f CMakeFiles/mixer_server.dir/build.make CMakeFiles/mixer_server.dir/httpclient.cpp.o.provides.build
.PHONY : CMakeFiles/mixer_server.dir/httpclient.cpp.o.provides

CMakeFiles/mixer_server.dir/httpclient.cpp.o.provides.build: CMakeFiles/mixer_server.dir/httpclient.cpp.o

CMakeFiles/mixer_server.dir/fetcher.cpp.o: CMakeFiles/mixer_server.dir/flags.make
CMakeFiles/mixer_server.dir/fetcher.cpp.o: ../fetcher.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /export/servers/mixer2/build/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/mixer_server.dir/fetcher.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/mixer_server.dir/fetcher.cpp.o -c /export/servers/mixer2/fetcher.cpp

CMakeFiles/mixer_server.dir/fetcher.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mixer_server.dir/fetcher.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /export/servers/mixer2/fetcher.cpp > CMakeFiles/mixer_server.dir/fetcher.cpp.i

CMakeFiles/mixer_server.dir/fetcher.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mixer_server.dir/fetcher.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /export/servers/mixer2/fetcher.cpp -o CMakeFiles/mixer_server.dir/fetcher.cpp.s

CMakeFiles/mixer_server.dir/fetcher.cpp.o.requires:
.PHONY : CMakeFiles/mixer_server.dir/fetcher.cpp.o.requires

CMakeFiles/mixer_server.dir/fetcher.cpp.o.provides: CMakeFiles/mixer_server.dir/fetcher.cpp.o.requires
	$(MAKE) -f CMakeFiles/mixer_server.dir/build.make CMakeFiles/mixer_server.dir/fetcher.cpp.o.provides.build
.PHONY : CMakeFiles/mixer_server.dir/fetcher.cpp.o.provides

CMakeFiles/mixer_server.dir/fetcher.cpp.o.provides.build: CMakeFiles/mixer_server.dir/fetcher.cpp.o

CMakeFiles/mixer_server.dir/mixer_resource.cpp.o: CMakeFiles/mixer_server.dir/flags.make
CMakeFiles/mixer_server.dir/mixer_resource.cpp.o: ../mixer_resource.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /export/servers/mixer2/build/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/mixer_server.dir/mixer_resource.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/mixer_server.dir/mixer_resource.cpp.o -c /export/servers/mixer2/mixer_resource.cpp

CMakeFiles/mixer_server.dir/mixer_resource.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mixer_server.dir/mixer_resource.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /export/servers/mixer2/mixer_resource.cpp > CMakeFiles/mixer_server.dir/mixer_resource.cpp.i

CMakeFiles/mixer_server.dir/mixer_resource.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mixer_server.dir/mixer_resource.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /export/servers/mixer2/mixer_resource.cpp -o CMakeFiles/mixer_server.dir/mixer_resource.cpp.s

CMakeFiles/mixer_server.dir/mixer_resource.cpp.o.requires:
.PHONY : CMakeFiles/mixer_server.dir/mixer_resource.cpp.o.requires

CMakeFiles/mixer_server.dir/mixer_resource.cpp.o.provides: CMakeFiles/mixer_server.dir/mixer_resource.cpp.o.requires
	$(MAKE) -f CMakeFiles/mixer_server.dir/build.make CMakeFiles/mixer_server.dir/mixer_resource.cpp.o.provides.build
.PHONY : CMakeFiles/mixer_server.dir/mixer_resource.cpp.o.provides

CMakeFiles/mixer_server.dir/mixer_resource.cpp.o.provides.build: CMakeFiles/mixer_server.dir/mixer_resource.cpp.o

CMakeFiles/mixer_server.dir/merger.cpp.o: CMakeFiles/mixer_server.dir/flags.make
CMakeFiles/mixer_server.dir/merger.cpp.o: ../merger.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /export/servers/mixer2/build/CMakeFiles $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/mixer_server.dir/merger.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/mixer_server.dir/merger.cpp.o -c /export/servers/mixer2/merger.cpp

CMakeFiles/mixer_server.dir/merger.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mixer_server.dir/merger.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /export/servers/mixer2/merger.cpp > CMakeFiles/mixer_server.dir/merger.cpp.i

CMakeFiles/mixer_server.dir/merger.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mixer_server.dir/merger.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /export/servers/mixer2/merger.cpp -o CMakeFiles/mixer_server.dir/merger.cpp.s

CMakeFiles/mixer_server.dir/merger.cpp.o.requires:
.PHONY : CMakeFiles/mixer_server.dir/merger.cpp.o.requires

CMakeFiles/mixer_server.dir/merger.cpp.o.provides: CMakeFiles/mixer_server.dir/merger.cpp.o.requires
	$(MAKE) -f CMakeFiles/mixer_server.dir/build.make CMakeFiles/mixer_server.dir/merger.cpp.o.provides.build
.PHONY : CMakeFiles/mixer_server.dir/merger.cpp.o.provides

CMakeFiles/mixer_server.dir/merger.cpp.o.provides.build: CMakeFiles/mixer_server.dir/merger.cpp.o

CMakeFiles/mixer_server.dir/mixer_impl.cpp.o: CMakeFiles/mixer_server.dir/flags.make
CMakeFiles/mixer_server.dir/mixer_impl.cpp.o: ../mixer_impl.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /export/servers/mixer2/build/CMakeFiles $(CMAKE_PROGRESS_6)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/mixer_server.dir/mixer_impl.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/mixer_server.dir/mixer_impl.cpp.o -c /export/servers/mixer2/mixer_impl.cpp

CMakeFiles/mixer_server.dir/mixer_impl.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mixer_server.dir/mixer_impl.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /export/servers/mixer2/mixer_impl.cpp > CMakeFiles/mixer_server.dir/mixer_impl.cpp.i

CMakeFiles/mixer_server.dir/mixer_impl.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mixer_server.dir/mixer_impl.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /export/servers/mixer2/mixer_impl.cpp -o CMakeFiles/mixer_server.dir/mixer_impl.cpp.s

CMakeFiles/mixer_server.dir/mixer_impl.cpp.o.requires:
.PHONY : CMakeFiles/mixer_server.dir/mixer_impl.cpp.o.requires

CMakeFiles/mixer_server.dir/mixer_impl.cpp.o.provides: CMakeFiles/mixer_server.dir/mixer_impl.cpp.o.requires
	$(MAKE) -f CMakeFiles/mixer_server.dir/build.make CMakeFiles/mixer_server.dir/mixer_impl.cpp.o.provides.build
.PHONY : CMakeFiles/mixer_server.dir/mixer_impl.cpp.o.provides

CMakeFiles/mixer_server.dir/mixer_impl.cpp.o.provides.build: CMakeFiles/mixer_server.dir/mixer_impl.cpp.o

# Object files for target mixer_server
mixer_server_OBJECTS = \
"CMakeFiles/mixer_server.dir/test.cpp.o" \
"CMakeFiles/mixer_server.dir/httpclient.cpp.o" \
"CMakeFiles/mixer_server.dir/fetcher.cpp.o" \
"CMakeFiles/mixer_server.dir/mixer_resource.cpp.o" \
"CMakeFiles/mixer_server.dir/merger.cpp.o" \
"CMakeFiles/mixer_server.dir/mixer_impl.cpp.o"

# External object files for target mixer_server
mixer_server_EXTERNAL_OBJECTS =

bin/mixer_server: CMakeFiles/mixer_server.dir/test.cpp.o
bin/mixer_server: CMakeFiles/mixer_server.dir/httpclient.cpp.o
bin/mixer_server: CMakeFiles/mixer_server.dir/fetcher.cpp.o
bin/mixer_server: CMakeFiles/mixer_server.dir/mixer_resource.cpp.o
bin/mixer_server: CMakeFiles/mixer_server.dir/merger.cpp.o
bin/mixer_server: CMakeFiles/mixer_server.dir/mixer_impl.cpp.o
bin/mixer_server: CMakeFiles/mixer_server.dir/build.make
bin/mixer_server: CMakeFiles/mixer_server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable bin/mixer_server"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mixer_server.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/mixer_server.dir/build: bin/mixer_server
.PHONY : CMakeFiles/mixer_server.dir/build

CMakeFiles/mixer_server.dir/requires: CMakeFiles/mixer_server.dir/test.cpp.o.requires
CMakeFiles/mixer_server.dir/requires: CMakeFiles/mixer_server.dir/httpclient.cpp.o.requires
CMakeFiles/mixer_server.dir/requires: CMakeFiles/mixer_server.dir/fetcher.cpp.o.requires
CMakeFiles/mixer_server.dir/requires: CMakeFiles/mixer_server.dir/mixer_resource.cpp.o.requires
CMakeFiles/mixer_server.dir/requires: CMakeFiles/mixer_server.dir/merger.cpp.o.requires
CMakeFiles/mixer_server.dir/requires: CMakeFiles/mixer_server.dir/mixer_impl.cpp.o.requires
.PHONY : CMakeFiles/mixer_server.dir/requires

CMakeFiles/mixer_server.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/mixer_server.dir/cmake_clean.cmake
.PHONY : CMakeFiles/mixer_server.dir/clean

CMakeFiles/mixer_server.dir/depend:
	cd /export/servers/mixer2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /export/servers/mixer2 /export/servers/mixer2 /export/servers/mixer2/build /export/servers/mixer2/build /export/servers/mixer2/build/CMakeFiles/mixer_server.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/mixer_server.dir/depend

