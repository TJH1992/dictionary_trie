cmake_minimum_required(VERSION 3.23)
project(programming_assignment_1)

set(CMAKE_CXX_STANDARD 11)

add_executable(countprefix main.cpp dictionary.cpp dictionary.h countprefix.cpp)

#configure_file(${CMAKE_CURRENT_SOURCE_DIR}/vocabulary.txt
#        ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)
#
#configure_file(${CMAKE_CURRENT_SOURCE_DIR}/testfile1.txt
#        ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)

#add_custom_command(
#        TARGET countprefix
#        POST_BUILD
#        COMMAND ${CMAKE_CURRENT_BINARY_DIR}/countprefix ../vocabulary.txt ../testfile1.txt
#        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
#        DEPENDS countprefix
#)
