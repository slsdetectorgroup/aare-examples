cmake_minimum_required(VERSION 3.14)
project(example)
set(CMAKE_CXX_STANDARD 17) 
find_package(aare REQUIRED)


#How do we deal with these targets? 
find_package(fmt REQUIRED)
find_package(nlohmann_json 3.11.3 REQUIRED)



add_executable(file_info file_info.cpp)
target_link_libraries(file_info PRIVATE aare_core)
set_target_properties(file_info PROPERTIES 
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}
)

