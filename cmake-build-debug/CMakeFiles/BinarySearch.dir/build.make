# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.20

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

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

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.2.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.2.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\CLionProjects\BinarySearch

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\CLionProjects\BinarySearch\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles\BinarySearch.dir\depend.make
# Include the progress variables for this target.
include CMakeFiles\BinarySearch.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\BinarySearch.dir\flags.make

CMakeFiles\BinarySearch.dir\main.cpp.obj: CMakeFiles\BinarySearch.dir\flags.make
CMakeFiles\BinarySearch.dir\main.cpp.obj: ..\main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\CLionProjects\BinarySearch\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/BinarySearch.dir/main.cpp.obj"
	C:\PROGRA~1\MICROS~2\2022\COMMUN~1\VC\Tools\MSVC\1430~1.307\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\BinarySearch.dir\main.cpp.obj /FdCMakeFiles\BinarySearch.dir\ /FS -c D:\CLionProjects\BinarySearch\main.cpp
<<

CMakeFiles\BinarySearch.dir\main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BinarySearch.dir/main.cpp.i"
	C:\PROGRA~1\MICROS~2\2022\COMMUN~1\VC\Tools\MSVC\1430~1.307\bin\Hostx86\x86\cl.exe > CMakeFiles\BinarySearch.dir\main.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\CLionProjects\BinarySearch\main.cpp
<<

CMakeFiles\BinarySearch.dir\main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BinarySearch.dir/main.cpp.s"
	C:\PROGRA~1\MICROS~2\2022\COMMUN~1\VC\Tools\MSVC\1430~1.307\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\BinarySearch.dir\main.cpp.s /c D:\CLionProjects\BinarySearch\main.cpp
<<

# Object files for target BinarySearch
BinarySearch_OBJECTS = \
"CMakeFiles\BinarySearch.dir\main.cpp.obj"

# External object files for target BinarySearch
BinarySearch_EXTERNAL_OBJECTS =

BinarySearch.exe: CMakeFiles\BinarySearch.dir\main.cpp.obj
BinarySearch.exe: CMakeFiles\BinarySearch.dir\build.make
BinarySearch.exe: CMakeFiles\BinarySearch.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\CLionProjects\BinarySearch\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable BinarySearch.exe"
	"C:\Program Files\JetBrains\CLion 2021.2.3\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\BinarySearch.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100190~1.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100190~1.0\x86\mt.exe --manifests -- C:\PROGRA~1\MICROS~2\2022\COMMUN~1\VC\Tools\MSVC\1430~1.307\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\BinarySearch.dir\objects1.rsp @<<
 /out:BinarySearch.exe /implib:BinarySearch.lib /pdb:D:\CLionProjects\BinarySearch\cmake-build-debug\BinarySearch.pdb /version:0.0 /machine:X86 /debug /INCREMENTAL /subsystem:console  kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\BinarySearch.dir\build: BinarySearch.exe
.PHONY : CMakeFiles\BinarySearch.dir\build

CMakeFiles\BinarySearch.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\BinarySearch.dir\cmake_clean.cmake
.PHONY : CMakeFiles\BinarySearch.dir\clean

CMakeFiles\BinarySearch.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" D:\CLionProjects\BinarySearch D:\CLionProjects\BinarySearch D:\CLionProjects\BinarySearch\cmake-build-debug D:\CLionProjects\BinarySearch\cmake-build-debug D:\CLionProjects\BinarySearch\cmake-build-debug\CMakeFiles\BinarySearch.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\BinarySearch.dir\depend

