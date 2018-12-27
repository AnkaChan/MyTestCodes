cmake_minimum_required(VERSION 3.1.0) 
PROJECT (HDF5MyApp)

set(HDF5_USE_STATIC_LIBRARIES ON)
find_package(HDF5 REQUIRED  COMPONENTS C CXX)
include_directories(${HDF5_INCLUDE_DIRS})

add_executable( HDF5MyApp hdf_example.cpp )

target_link_libraries( HDF5MyApp ${HDF5_CXX_LIBRARIES} ${HDF5_LIBRARIES})
