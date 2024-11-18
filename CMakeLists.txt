cmake_minimum_required(VERSION 3.14)
project(example)
set(CMAKE_CXX_STANDARD 17) 

#Use cmake to find aare
find_package(aare REQUIRED)


#List of examples to be compiled
set(ExampleSrc
    00-NDArray.cpp
    01-NDView.cpp
    02-file_info.cpp
    03-File.cpp
)

#Iterate over the list of examples and compile them
foreach(FILE ${ExampleSrc})
    get_filename_component(EXENAME ${FILE} NAME_WE)
    add_executable(${EXENAME} ${FILE})
    target_link_libraries(${EXENAME}  aare_core)
    set_target_properties(${EXENAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
endforeach()


#Some examples require ROOT. Only enable them if the user requests it
option(ENABLE_ROOT_EXAMPLES "Enable ROOT examples" OFF)


if(ENABLE_ROOT_EXAMPLES)
    find_package(ROOT CONFIG REQUIRED)

    set(RootExampleSrc
        04-TH1.cpp
    )

    foreach(FILE ${RootExampleSrc})
        get_filename_component(EXENAME ${FILE} NAME_WE)
        add_executable(${EXENAME} ${FILE})
        target_link_libraries(${EXENAME}  aare_core ROOT::Hist ROOT::Graf ROOT::Gpad ROOT::Core)
        set_target_properties(${EXENAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
    endforeach()
endif()