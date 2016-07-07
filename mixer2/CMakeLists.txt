PROJECT(mixer_server)

cmake_minimum_required(VERSION 2.8)

SET(SRC_LIST test.cpp httpclient.cpp fetcher.cpp mixer_resource.cpp merger.cpp mixer_impl.cpp)

#aux_source_directory(. SRC_LIST)

INCLUDE_DIRECTORIES(/usr/local/include)

MESSAGE(STATUS "This is BINARY dir "${PROJECT_BINARY_DIR})

SET(LIBRARIES libcurl.so libhelloredis.so)

LINK_DIRECTORIES(/usr/local/lib)
LINK_DIRECTORIES(/usr/lib)
LINK_DIRECTORIES(${CMAKE_SOURCE_DIR}/lib/)

add_library(mixerAdRe SHARED ${SRC_LIST})

ADD_EXECUTABLE(mixer_server ${SRC_LIST})
TARGET_LINK_LIBRARIES( mixer_server ${LIBRARIES} )

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
