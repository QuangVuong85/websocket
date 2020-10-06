cmake_minimum_required(VERSION 3.9)
project(websocket-chat-multi VERSION 0.0.1 DESCRIPTION "websocket-chat-multi")
set(CMAKE_BUILD_TYPE Release)

set(CMAKE_CXX_STANDARD 11)

file(GLOB APP_FILES
        ../includes/beast.hpp
        http_session.cpp
        ../includes/http_session.hpp
        listener.cpp
        ../includes/listener.hpp
        ../includes/net.hpp
        shared_state.cpp
        ../includes/shared_state.hpp
        websocket_session.cpp
        ../includes/websocket_session.hpp
        )
add_executable(websocket-chat-multi main.cpp ${APP_FILES})
target_link_libraries(websocket-chat-multi pthread)


#add_executable(chat_server chat_server.cpp ../includes/chat_message.hpp)
#add_executable(chat_client chat_client.cpp ../includes/chat_message.hpp)
#target_link_libraries (chat_server pthread)
#target_link_libraries (chat_client pthread)
