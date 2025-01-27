cmake_minimum_required(VERSION 2.6 FATAL_ERROR)
project(XrayFilt)
set(CMAKE_PREFIX_PATH /opt/applications/geant4/geant4.10.04.p01-install/)
option(WITH_GEANT4_UIVIS "Build example with Geant4 UI and Vis drivers" ON)
if(WITH_GEANT4_UIVIS)
  find_package(Geant4 REQUIRED ui_all vis_all)
else()
  find_package(Geant4 REQUIRED)
endif()
include(${Geant4_USE_FILE})
include_directories(${PROJECT_SOURCE_DIR}/include)
file(GLOB sources ${PROJECT_SOURCE_DIR}/src/*.cpp)
file(GLOB headers ${PROJECT_SOURCE_DIR}/include/*.hh)
add_executable(XrayFilt XrayFilt.cpp ${sources} ${headers} src/SpectraManager.cpp include/SpectraManager.hh src/Config.cpp include/Config.hh)
target_link_libraries(XrayFilt ${Geant4_LIBRARIES})
set(EXAMPLE1_SCRIPTS
  run1.mac
  vis1.mac
  config.dat
  initialSpectra.dat
  )
foreach(_script ${EXAMPLE1_SCRIPTS})
  configure_file(
    ${PROJECT_SOURCE_DIR}/${_script}
    ${PROJECT_BINARY_DIR}/${_script}
    COPYONLY
    )
endforeach()
add_custom_target(ex1 DEPENDS XrayFilt)
install(TARGETS XrayFilt DESTINATION bin)