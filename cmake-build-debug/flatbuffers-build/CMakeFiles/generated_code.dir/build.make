# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = /home/josiah/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/212.5080.54/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/josiah/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/212.5080.54/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/josiah/projects/code/impresario-systems/cosmographer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/josiah/projects/code/impresario-systems/cosmographer/cmake-build-debug

# Utility rule file for generated_code.

# Include any custom commands dependencies for this target.
include flatbuffers-build/CMakeFiles/generated_code.dir/compiler_depend.make

# Include the progress variables for this target.
include flatbuffers-build/CMakeFiles/generated_code.dir/progress.make

flatbuffers-build/CMakeFiles/generated_code: flatbuffers-build/tests/monster_test_generated.h
flatbuffers-build/CMakeFiles/generated_code: flatbuffers-src/tests/monster_test.bfbs
flatbuffers-build/CMakeFiles/generated_code: flatbuffers-build/tests/namespace_test/namespace_test1_generated.h
flatbuffers-build/CMakeFiles/generated_code: flatbuffers-build/tests/namespace_test/namespace_test2_generated.h
flatbuffers-build/CMakeFiles/generated_code: flatbuffers-build/tests/union_vector/union_vector_generated.h
flatbuffers-build/CMakeFiles/generated_code: flatbuffers-build/tests/native_type_test_generated.h
flatbuffers-build/CMakeFiles/generated_code: flatbuffers-build/tests/arrays_test_generated.h
flatbuffers-build/CMakeFiles/generated_code: flatbuffers-src/tests/arrays_test.bfbs
flatbuffers-build/CMakeFiles/generated_code: flatbuffers-build/tests/monster_test_bfbs_generated.h
flatbuffers-build/CMakeFiles/generated_code: flatbuffers-build/tests/monster_extra_generated.h
flatbuffers-build/CMakeFiles/generated_code: flatbuffers-build/samples/monster_generated.h
flatbuffers-build/CMakeFiles/generated_code: flatbuffers-src/samples/monster.bfbs
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/josiah/projects/code/impresario-systems/cosmographer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "All generated files were updated."

flatbuffers-build/samples/monster.bfbs: flatbuffers-build/flatc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/josiah/projects/code/impresario-systems/cosmographer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Run generation: 'samples/monster.bfbs'"
	cd /home/josiah/projects/code/impresario-systems/cosmographer/cmake-build-debug/flatbuffers-build && ./flatc -b --schema --bfbs-comments --bfbs-builtins -I /home/josiah/projects/code/impresario-systems/cosmographer/cmake-build-debug/flatbuffers-src/tests/include_test -o samples /home/josiah/projects/code/impresario-systems/cosmographer/cmake-build-debug/flatbuffers-src/samples/monster.fbs

flatbuffers-build/samples/monster_generated.h: flatbuffers-build/flatc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/josiah/projects/code/impresario-systems/cosmographer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Run generation: 'samples/monster_generated.h'"
	cd /home/josiah/projects/code/impresario-systems/cosmographer/cmake-build-debug/flatbuffers-build && ./flatc --cpp --gen-mutable --gen-object-api --reflect-names --cpp-ptr-type flatbuffers::unique_ptr --no-includes --gen-compare -I /home/josiah/projects/code/impresario-systems/cosmographer/cmake-build-debug/flatbuffers-src/tests/include_test -o samples /home/josiah/projects/code/impresario-systems/cosmographer/cmake-build-debug/flatbuffers-src/samples/monster.fbs

flatbuffers-build/tests/arrays_test.bfbs: flatbuffers-build/flatc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/josiah/projects/code/impresario-systems/cosmographer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Run generation: 'tests/arrays_test.bfbs'"
	cd /home/josiah/projects/code/impresario-systems/cosmographer/cmake-build-debug/flatbuffers-build && ./flatc -b --schema --bfbs-comments --bfbs-builtins -I /home/josiah/projects/code/impresario-systems/cosmographer/cmake-build-debug/flatbuffers-src/tests/include_test -o tests /home/josiah/projects/code/impresario-systems/cosmographer/cmake-build-debug/flatbuffers-src/tests/arrays_test.fbs

flatbuffers-build/tests/arrays_test_generated.h: flatbuffers-build/flatc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/josiah/projects/code/impresario-systems/cosmographer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Run generation: 'tests/arrays_test_generated.h'"
	cd /home/josiah/projects/code/impresario-systems/cosmographer/cmake-build-debug/flatbuffers-build && ./flatc --cpp --gen-mutable --gen-object-api --reflect-names --cpp-ptr-type flatbuffers::unique_ptr --scoped-enums --gen-compare -I /home/josiah/projects/code/impresario-systems/cosmographer/cmake-build-debug/flatbuffers-src/tests/include_test -o tests /home/josiah/projects/code/impresario-systems/cosmographer/cmake-build-debug/flatbuffers-src/tests/arrays_test.fbs

flatbuffers-build/tests/monster_extra_generated.h: flatbuffers-build/flatc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/josiah/projects/code/impresario-systems/cosmographer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Run generation: 'tests/monster_extra_generated.h'"
	cd /home/josiah/projects/code/impresario-systems/cosmographer/cmake-build-debug/flatbuffers-build && ./flatc --cpp --gen-mutable --gen-object-api --reflect-names --cpp-ptr-type flatbuffers::unique_ptr --no-includes --gen-compare -I /home/josiah/projects/code/impresario-systems/cosmographer/cmake-build-debug/flatbuffers-src/tests/include_test -o tests /home/josiah/projects/code/impresario-systems/cosmographer/cmake-build-debug/flatbuffers-src/tests/monster_extra.fbs

flatbuffers-build/tests/monster_test.bfbs: flatbuffers-build/flatc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/josiah/projects/code/impresario-systems/cosmographer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Run generation: 'tests/monster_test.bfbs'"
	cd /home/josiah/projects/code/impresario-systems/cosmographer/cmake-build-debug/flatbuffers-build && ./flatc -b --schema --bfbs-comments --bfbs-builtins -I /home/josiah/projects/code/impresario-systems/cosmographer/cmake-build-debug/flatbuffers-src/tests/include_test -o tests /home/josiah/projects/code/impresario-systems/cosmographer/cmake-build-debug/flatbuffers-src/tests/monster_test.fbs

flatbuffers-build/tests/monster_test_bfbs_generated.h: flatbuffers-build/flatc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/josiah/projects/code/impresario-systems/cosmographer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Run generation: 'tests/monster_test_bfbs_generated.h'"
	cd /home/josiah/projects/code/impresario-systems/cosmographer/cmake-build-debug/flatbuffers-build && ./flatc --cpp --gen-mutable --gen-object-api --reflect-names --cpp-ptr-type flatbuffers::unique_ptr --no-includes --gen-compare --bfbs-comments --bfbs-builtins --bfbs-gen-embed -I /home/josiah/projects/code/impresario-systems/cosmographer/cmake-build-debug/flatbuffers-src/tests/include_test -o tests /home/josiah/projects/code/impresario-systems/cosmographer/cmake-build-debug/flatbuffers-src/tests/monster_test.fbs

flatbuffers-build/tests/monster_test_generated.h: flatbuffers-build/flatc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/josiah/projects/code/impresario-systems/cosmographer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Run generation: 'tests/monster_test_generated.h'"
	cd /home/josiah/projects/code/impresario-systems/cosmographer/cmake-build-debug/flatbuffers-build && ./flatc --cpp --gen-mutable --gen-object-api --reflect-names --cpp-ptr-type flatbuffers::unique_ptr --no-includes --gen-compare -I /home/josiah/projects/code/impresario-systems/cosmographer/cmake-build-debug/flatbuffers-src/tests/include_test -o tests /home/josiah/projects/code/impresario-systems/cosmographer/cmake-build-debug/flatbuffers-src/tests/monster_test.fbs

flatbuffers-build/tests/namespace_test/namespace_test1_generated.h: flatbuffers-build/flatc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/josiah/projects/code/impresario-systems/cosmographer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Run generation: 'tests/namespace_test/namespace_test1_generated.h'"
	cd /home/josiah/projects/code/impresario-systems/cosmographer/cmake-build-debug/flatbuffers-build && ./flatc --cpp --gen-mutable --gen-object-api --reflect-names --cpp-ptr-type flatbuffers::unique_ptr --no-includes --gen-compare -I /home/josiah/projects/code/impresario-systems/cosmographer/cmake-build-debug/flatbuffers-src/tests/include_test -o tests/namespace_test /home/josiah/projects/code/impresario-systems/cosmographer/cmake-build-debug/flatbuffers-src/tests/namespace_test/namespace_test1.fbs

flatbuffers-build/tests/namespace_test/namespace_test2_generated.h: flatbuffers-build/flatc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/josiah/projects/code/impresario-systems/cosmographer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Run generation: 'tests/namespace_test/namespace_test2_generated.h'"
	cd /home/josiah/projects/code/impresario-systems/cosmographer/cmake-build-debug/flatbuffers-build && ./flatc --cpp --gen-mutable --gen-object-api --reflect-names --cpp-ptr-type flatbuffers::unique_ptr --no-includes --gen-compare -I /home/josiah/projects/code/impresario-systems/cosmographer/cmake-build-debug/flatbuffers-src/tests/include_test -o tests/namespace_test /home/josiah/projects/code/impresario-systems/cosmographer/cmake-build-debug/flatbuffers-src/tests/namespace_test/namespace_test2.fbs

flatbuffers-build/tests/native_type_test_generated.h: flatbuffers-build/flatc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/josiah/projects/code/impresario-systems/cosmographer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Run generation: 'tests/native_type_test_generated.h'"
	cd /home/josiah/projects/code/impresario-systems/cosmographer/cmake-build-debug/flatbuffers-build && ./flatc --cpp --gen-mutable --gen-object-api --reflect-names --cpp-ptr-type flatbuffers::unique_ptr -I /home/josiah/projects/code/impresario-systems/cosmographer/cmake-build-debug/flatbuffers-src/tests/include_test -o tests /home/josiah/projects/code/impresario-systems/cosmographer/cmake-build-debug/flatbuffers-src/tests/native_type_test.fbs

flatbuffers-build/tests/union_vector/union_vector_generated.h: flatbuffers-build/flatc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/josiah/projects/code/impresario-systems/cosmographer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Run generation: 'tests/union_vector/union_vector_generated.h'"
	cd /home/josiah/projects/code/impresario-systems/cosmographer/cmake-build-debug/flatbuffers-build && ./flatc --cpp --gen-mutable --gen-object-api --reflect-names --cpp-ptr-type flatbuffers::unique_ptr --no-includes --gen-compare -I /home/josiah/projects/code/impresario-systems/cosmographer/cmake-build-debug/flatbuffers-src/tests/include_test -o tests/union_vector /home/josiah/projects/code/impresario-systems/cosmographer/cmake-build-debug/flatbuffers-src/tests/union_vector/union_vector.fbs

generated_code: flatbuffers-build/CMakeFiles/generated_code
generated_code: flatbuffers-build/samples/monster.bfbs
generated_code: flatbuffers-build/samples/monster_generated.h
generated_code: flatbuffers-build/tests/arrays_test.bfbs
generated_code: flatbuffers-build/tests/arrays_test_generated.h
generated_code: flatbuffers-build/tests/monster_extra_generated.h
generated_code: flatbuffers-build/tests/monster_test.bfbs
generated_code: flatbuffers-build/tests/monster_test_bfbs_generated.h
generated_code: flatbuffers-build/tests/monster_test_generated.h
generated_code: flatbuffers-build/tests/namespace_test/namespace_test1_generated.h
generated_code: flatbuffers-build/tests/namespace_test/namespace_test2_generated.h
generated_code: flatbuffers-build/tests/native_type_test_generated.h
generated_code: flatbuffers-build/tests/union_vector/union_vector_generated.h
generated_code: flatbuffers-build/CMakeFiles/generated_code.dir/build.make
.PHONY : generated_code

# Rule to build all files generated by this target.
flatbuffers-build/CMakeFiles/generated_code.dir/build: generated_code
.PHONY : flatbuffers-build/CMakeFiles/generated_code.dir/build

flatbuffers-build/CMakeFiles/generated_code.dir/clean:
	cd /home/josiah/projects/code/impresario-systems/cosmographer/cmake-build-debug/flatbuffers-build && $(CMAKE_COMMAND) -P CMakeFiles/generated_code.dir/cmake_clean.cmake
.PHONY : flatbuffers-build/CMakeFiles/generated_code.dir/clean

flatbuffers-build/CMakeFiles/generated_code.dir/depend:
	cd /home/josiah/projects/code/impresario-systems/cosmographer/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/josiah/projects/code/impresario-systems/cosmographer /home/josiah/projects/code/impresario-systems/cosmographer/cmake-build-debug/flatbuffers-src /home/josiah/projects/code/impresario-systems/cosmographer/cmake-build-debug /home/josiah/projects/code/impresario-systems/cosmographer/cmake-build-debug/flatbuffers-build /home/josiah/projects/code/impresario-systems/cosmographer/cmake-build-debug/flatbuffers-build/CMakeFiles/generated_code.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : flatbuffers-build/CMakeFiles/generated_code.dir/depend

