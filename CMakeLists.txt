cmake_minimum_required(VERSION 3.14)
project(example)
set(CMAKE_CXX_STANDARD 17) 
find_package(aare REQUIRED)


#How do we deal with these targets? 
find_package(fmt REQUIRED)
find_package(nlohmann_json 3.11.3 REQUIRED)



set(ExampleSrc
    00-NDArray.cpp
    01-NDView.cpp
    02-file_info.cpp
    03-File.cpp
)

foreach(FILE ${ExampleSrc})
    get_filename_component(EXENAME ${FILE} NAME_WE)
    add_executable(${EXENAME} ${FILE})
    target_link_libraries(${EXENAME}  aare_core)
    set_target_properties(${EXENAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
endforeach()
