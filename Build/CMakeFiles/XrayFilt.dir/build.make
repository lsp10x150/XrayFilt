# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/lsp10/workspace/G4WORK/GEANT4_Xray_Filt

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lsp10/workspace/G4WORK/GEANT4_Xray_Filt/Build

# Include any dependencies generated for this target.
include CMakeFiles/XrayFilt.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/XrayFilt.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/XrayFilt.dir/flags.make

CMakeFiles/XrayFilt.dir/XrayFilt.cpp.o: CMakeFiles/XrayFilt.dir/flags.make
CMakeFiles/XrayFilt.dir/XrayFilt.cpp.o: ../XrayFilt.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lsp10/workspace/G4WORK/GEANT4_Xray_Filt/Build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/XrayFilt.dir/XrayFilt.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/XrayFilt.dir/XrayFilt.cpp.o -c /home/lsp10/workspace/G4WORK/GEANT4_Xray_Filt/XrayFilt.cpp

CMakeFiles/XrayFilt.dir/XrayFilt.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/XrayFilt.dir/XrayFilt.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lsp10/workspace/G4WORK/GEANT4_Xray_Filt/XrayFilt.cpp > CMakeFiles/XrayFilt.dir/XrayFilt.cpp.i

CMakeFiles/XrayFilt.dir/XrayFilt.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/XrayFilt.dir/XrayFilt.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lsp10/workspace/G4WORK/GEANT4_Xray_Filt/XrayFilt.cpp -o CMakeFiles/XrayFilt.dir/XrayFilt.cpp.s

CMakeFiles/XrayFilt.dir/src/ActionInit.cpp.o: CMakeFiles/XrayFilt.dir/flags.make
CMakeFiles/XrayFilt.dir/src/ActionInit.cpp.o: ../src/ActionInit.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lsp10/workspace/G4WORK/GEANT4_Xray_Filt/Build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/XrayFilt.dir/src/ActionInit.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/XrayFilt.dir/src/ActionInit.cpp.o -c /home/lsp10/workspace/G4WORK/GEANT4_Xray_Filt/src/ActionInit.cpp

CMakeFiles/XrayFilt.dir/src/ActionInit.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/XrayFilt.dir/src/ActionInit.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lsp10/workspace/G4WORK/GEANT4_Xray_Filt/src/ActionInit.cpp > CMakeFiles/XrayFilt.dir/src/ActionInit.cpp.i

CMakeFiles/XrayFilt.dir/src/ActionInit.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/XrayFilt.dir/src/ActionInit.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lsp10/workspace/G4WORK/GEANT4_Xray_Filt/src/ActionInit.cpp -o CMakeFiles/XrayFilt.dir/src/ActionInit.cpp.s

CMakeFiles/XrayFilt.dir/src/Config.cpp.o: CMakeFiles/XrayFilt.dir/flags.make
CMakeFiles/XrayFilt.dir/src/Config.cpp.o: ../src/Config.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lsp10/workspace/G4WORK/GEANT4_Xray_Filt/Build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/XrayFilt.dir/src/Config.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/XrayFilt.dir/src/Config.cpp.o -c /home/lsp10/workspace/G4WORK/GEANT4_Xray_Filt/src/Config.cpp

CMakeFiles/XrayFilt.dir/src/Config.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/XrayFilt.dir/src/Config.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lsp10/workspace/G4WORK/GEANT4_Xray_Filt/src/Config.cpp > CMakeFiles/XrayFilt.dir/src/Config.cpp.i

CMakeFiles/XrayFilt.dir/src/Config.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/XrayFilt.dir/src/Config.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lsp10/workspace/G4WORK/GEANT4_Xray_Filt/src/Config.cpp -o CMakeFiles/XrayFilt.dir/src/Config.cpp.s

CMakeFiles/XrayFilt.dir/src/DetSD.cpp.o: CMakeFiles/XrayFilt.dir/flags.make
CMakeFiles/XrayFilt.dir/src/DetSD.cpp.o: ../src/DetSD.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lsp10/workspace/G4WORK/GEANT4_Xray_Filt/Build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/XrayFilt.dir/src/DetSD.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/XrayFilt.dir/src/DetSD.cpp.o -c /home/lsp10/workspace/G4WORK/GEANT4_Xray_Filt/src/DetSD.cpp

CMakeFiles/XrayFilt.dir/src/DetSD.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/XrayFilt.dir/src/DetSD.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lsp10/workspace/G4WORK/GEANT4_Xray_Filt/src/DetSD.cpp > CMakeFiles/XrayFilt.dir/src/DetSD.cpp.i

CMakeFiles/XrayFilt.dir/src/DetSD.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/XrayFilt.dir/src/DetSD.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lsp10/workspace/G4WORK/GEANT4_Xray_Filt/src/DetSD.cpp -o CMakeFiles/XrayFilt.dir/src/DetSD.cpp.s

CMakeFiles/XrayFilt.dir/src/DetectorConstr.cpp.o: CMakeFiles/XrayFilt.dir/flags.make
CMakeFiles/XrayFilt.dir/src/DetectorConstr.cpp.o: ../src/DetectorConstr.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lsp10/workspace/G4WORK/GEANT4_Xray_Filt/Build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/XrayFilt.dir/src/DetectorConstr.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/XrayFilt.dir/src/DetectorConstr.cpp.o -c /home/lsp10/workspace/G4WORK/GEANT4_Xray_Filt/src/DetectorConstr.cpp

CMakeFiles/XrayFilt.dir/src/DetectorConstr.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/XrayFilt.dir/src/DetectorConstr.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lsp10/workspace/G4WORK/GEANT4_Xray_Filt/src/DetectorConstr.cpp > CMakeFiles/XrayFilt.dir/src/DetectorConstr.cpp.i

CMakeFiles/XrayFilt.dir/src/DetectorConstr.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/XrayFilt.dir/src/DetectorConstr.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lsp10/workspace/G4WORK/GEANT4_Xray_Filt/src/DetectorConstr.cpp -o CMakeFiles/XrayFilt.dir/src/DetectorConstr.cpp.s

CMakeFiles/XrayFilt.dir/src/PrimaryGenAction.cpp.o: CMakeFiles/XrayFilt.dir/flags.make
CMakeFiles/XrayFilt.dir/src/PrimaryGenAction.cpp.o: ../src/PrimaryGenAction.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lsp10/workspace/G4WORK/GEANT4_Xray_Filt/Build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/XrayFilt.dir/src/PrimaryGenAction.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/XrayFilt.dir/src/PrimaryGenAction.cpp.o -c /home/lsp10/workspace/G4WORK/GEANT4_Xray_Filt/src/PrimaryGenAction.cpp

CMakeFiles/XrayFilt.dir/src/PrimaryGenAction.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/XrayFilt.dir/src/PrimaryGenAction.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lsp10/workspace/G4WORK/GEANT4_Xray_Filt/src/PrimaryGenAction.cpp > CMakeFiles/XrayFilt.dir/src/PrimaryGenAction.cpp.i

CMakeFiles/XrayFilt.dir/src/PrimaryGenAction.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/XrayFilt.dir/src/PrimaryGenAction.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lsp10/workspace/G4WORK/GEANT4_Xray_Filt/src/PrimaryGenAction.cpp -o CMakeFiles/XrayFilt.dir/src/PrimaryGenAction.cpp.s

CMakeFiles/XrayFilt.dir/src/SpectraManager.cpp.o: CMakeFiles/XrayFilt.dir/flags.make
CMakeFiles/XrayFilt.dir/src/SpectraManager.cpp.o: ../src/SpectraManager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lsp10/workspace/G4WORK/GEANT4_Xray_Filt/Build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/XrayFilt.dir/src/SpectraManager.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/XrayFilt.dir/src/SpectraManager.cpp.o -c /home/lsp10/workspace/G4WORK/GEANT4_Xray_Filt/src/SpectraManager.cpp

CMakeFiles/XrayFilt.dir/src/SpectraManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/XrayFilt.dir/src/SpectraManager.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lsp10/workspace/G4WORK/GEANT4_Xray_Filt/src/SpectraManager.cpp > CMakeFiles/XrayFilt.dir/src/SpectraManager.cpp.i

CMakeFiles/XrayFilt.dir/src/SpectraManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/XrayFilt.dir/src/SpectraManager.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lsp10/workspace/G4WORK/GEANT4_Xray_Filt/src/SpectraManager.cpp -o CMakeFiles/XrayFilt.dir/src/SpectraManager.cpp.s

# Object files for target XrayFilt
XrayFilt_OBJECTS = \
"CMakeFiles/XrayFilt.dir/XrayFilt.cpp.o" \
"CMakeFiles/XrayFilt.dir/src/ActionInit.cpp.o" \
"CMakeFiles/XrayFilt.dir/src/Config.cpp.o" \
"CMakeFiles/XrayFilt.dir/src/DetSD.cpp.o" \
"CMakeFiles/XrayFilt.dir/src/DetectorConstr.cpp.o" \
"CMakeFiles/XrayFilt.dir/src/PrimaryGenAction.cpp.o" \
"CMakeFiles/XrayFilt.dir/src/SpectraManager.cpp.o"

# External object files for target XrayFilt
XrayFilt_EXTERNAL_OBJECTS =

XrayFilt: CMakeFiles/XrayFilt.dir/XrayFilt.cpp.o
XrayFilt: CMakeFiles/XrayFilt.dir/src/ActionInit.cpp.o
XrayFilt: CMakeFiles/XrayFilt.dir/src/Config.cpp.o
XrayFilt: CMakeFiles/XrayFilt.dir/src/DetSD.cpp.o
XrayFilt: CMakeFiles/XrayFilt.dir/src/DetectorConstr.cpp.o
XrayFilt: CMakeFiles/XrayFilt.dir/src/PrimaryGenAction.cpp.o
XrayFilt: CMakeFiles/XrayFilt.dir/src/SpectraManager.cpp.o
XrayFilt: CMakeFiles/XrayFilt.dir/build.make
XrayFilt: /opt/applications/geant4/geant4.10.04.p01-install/lib/libG4Tree.so
XrayFilt: /opt/applications/geant4/geant4.10.04.p01-install/lib/libG4GMocren.so
XrayFilt: /opt/applications/geant4/geant4.10.04.p01-install/lib/libG4visHepRep.so
XrayFilt: /opt/applications/geant4/geant4.10.04.p01-install/lib/libG4RayTracer.so
XrayFilt: /opt/applications/geant4/geant4.10.04.p01-install/lib/libG4VRML.so
XrayFilt: /opt/applications/geant4/geant4.10.04.p01-install/lib/libG4OpenGL.so
XrayFilt: /opt/applications/geant4/geant4.10.04.p01-install/lib/libG4gl2ps.so
XrayFilt: /opt/applications/geant4/geant4.10.04.p01-install/lib/libG4interfaces.so
XrayFilt: /opt/applications/geant4/geant4.10.04.p01-install/lib/libG4persistency.so
XrayFilt: /opt/applications/geant4/geant4.10.04.p01-install/lib/libG4error_propagation.so
XrayFilt: /opt/applications/geant4/geant4.10.04.p01-install/lib/libG4readout.so
XrayFilt: /opt/applications/geant4/geant4.10.04.p01-install/lib/libG4physicslists.so
XrayFilt: /opt/applications/geant4/geant4.10.04.p01-install/lib/libG4parmodels.so
XrayFilt: /opt/applications/geant4/geant4.10.04.p01-install/lib/libG4FR.so
XrayFilt: /opt/applications/geant4/geant4.10.04.p01-install/lib/libG4vis_management.so
XrayFilt: /opt/applications/geant4/geant4.10.04.p01-install/lib/libG4modeling.so
XrayFilt: /usr/lib/x86_64-linux-gnu/libXm.so
XrayFilt: /usr/lib/x86_64-linux-gnu/libSM.so
XrayFilt: /usr/lib/x86_64-linux-gnu/libICE.so
XrayFilt: /usr/lib/x86_64-linux-gnu/libX11.so
XrayFilt: /usr/lib/x86_64-linux-gnu/libXext.so
XrayFilt: /usr/lib/x86_64-linux-gnu/libXt.so
XrayFilt: /usr/lib/x86_64-linux-gnu/libXmu.so
XrayFilt: /usr/lib/x86_64-linux-gnu/libGL.so
XrayFilt: /usr/lib/x86_64-linux-gnu/libGLU.so
XrayFilt: /usr/lib/x86_64-linux-gnu/libQtOpenGL.so
XrayFilt: /usr/lib/x86_64-linux-gnu/libQtGui.so
XrayFilt: /usr/lib/x86_64-linux-gnu/libQtCore.so
XrayFilt: /usr/lib/x86_64-linux-gnu/libxerces-c.so
XrayFilt: /opt/applications/geant4/geant4.10.04.p01-install/lib/libG4run.so
XrayFilt: /opt/applications/geant4/geant4.10.04.p01-install/lib/libG4event.so
XrayFilt: /opt/applications/geant4/geant4.10.04.p01-install/lib/libG4tracking.so
XrayFilt: /opt/applications/geant4/geant4.10.04.p01-install/lib/libG4processes.so
XrayFilt: /opt/applications/geant4/geant4.10.04.p01-install/lib/libG4analysis.so
XrayFilt: /opt/applications/geant4/geant4.10.04.p01-install/lib/libG4zlib.so
XrayFilt: /usr/lib/x86_64-linux-gnu/libexpat.so
XrayFilt: /opt/applications/geant4/geant4.10.04.p01-install/lib/libG4digits_hits.so
XrayFilt: /opt/applications/geant4/geant4.10.04.p01-install/lib/libG4track.so
XrayFilt: /opt/applications/geant4/geant4.10.04.p01-install/lib/libG4particles.so
XrayFilt: /opt/applications/geant4/geant4.10.04.p01-install/lib/libG4geometry.so
XrayFilt: /opt/applications/geant4/geant4.10.04.p01-install/lib/libG4materials.so
XrayFilt: /opt/applications/geant4/geant4.10.04.p01-install/lib/libG4graphics_reps.so
XrayFilt: /opt/applications/geant4/geant4.10.04.p01-install/lib/libG4intercoms.so
XrayFilt: /opt/applications/geant4/geant4.10.04.p01-install/lib/libG4global.so
XrayFilt: /opt/applications/geant4/geant4.10.04.p01-install/lib/libG4clhep.so
XrayFilt: CMakeFiles/XrayFilt.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lsp10/workspace/G4WORK/GEANT4_Xray_Filt/Build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable XrayFilt"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/XrayFilt.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/XrayFilt.dir/build: XrayFilt

.PHONY : CMakeFiles/XrayFilt.dir/build

CMakeFiles/XrayFilt.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/XrayFilt.dir/cmake_clean.cmake
.PHONY : CMakeFiles/XrayFilt.dir/clean

CMakeFiles/XrayFilt.dir/depend:
	cd /home/lsp10/workspace/G4WORK/GEANT4_Xray_Filt/Build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lsp10/workspace/G4WORK/GEANT4_Xray_Filt /home/lsp10/workspace/G4WORK/GEANT4_Xray_Filt /home/lsp10/workspace/G4WORK/GEANT4_Xray_Filt/Build /home/lsp10/workspace/G4WORK/GEANT4_Xray_Filt/Build /home/lsp10/workspace/G4WORK/GEANT4_Xray_Filt/Build/CMakeFiles/XrayFilt.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/XrayFilt.dir/depend

