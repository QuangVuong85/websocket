cmake_minimum_required(VERSION 3.9)
project(websocket-chat VERSION 0.0.1 DESCRIPTION "websocket-chat")
set(CMAKE_BUILD_TYPE Release)

set(CMAKE_CXX_STANDARD 11)

file(GLOB APP_FILES
        ../includes/chat_message.hpp)

add_executable(chat_server chat_server.cpp ${APP_FILES})
add_executable(chat_client chat_client.cpp ${APP_FILES})
target_link_libraries(chat_server pthread)
target_link_libraries(chat_client pthread)
