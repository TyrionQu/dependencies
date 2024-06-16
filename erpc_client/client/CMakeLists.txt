
project(client)
message(STATUS "start Building client")
message(STATUS "CMAKE_CURRENT_SOURCE_DIR: ${CMAKE_CURRENT_SOURCE_DIR}")
# message(STATUS "CMAKE_CURRENT_BINARY_DIR: ${CMAKE_CURRENT_BINARY_DIR}")
# message(STATUS "CMAKE_EXECUTABLE_OUTPUT_DIRECTORY: ${CMAKE_EXECUTABLE_OUTPUT_DIRECTORY}")
# message(STATUS "CMAKE_PROJECT_NAME: ${CMAKE_PROJECT_NAME}")
# message(STATUS "PROJECT_NAME: ${PROJECT_NAME}")
# message(STATUS "CMAKE_BINARY_DIR: ${CMAKE_BINARY_DIR}")
message(STATUS "CMAKE_SOURCE_DIR: ${CMAKE_SOURCE_DIR}")
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} SRC_LIST)

add_executable(client ${SRC_LIST})
target_link_libraries(client erpc_share)
# target_include_directories(client PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../include)
target_include_directories(client PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../ERPC_C/config)
target_include_directories(client PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../ERPC_C/infra)
target_include_directories(client PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../ERPC_C/setup)
target_include_directories(client PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../ERPC_C/transport)
target_include_directories(client PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../ERPC_C/port)

#设置目标属性
target_compile_features(client PRIVATE cxx_std_98)

message(STATUS "end Building client")
