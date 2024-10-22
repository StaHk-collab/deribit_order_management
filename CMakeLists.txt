include("C:/Users/WELCOME/Documents/GoQuant/deribit_order_management/vcpkg/scripts/buildsystems/vcpkg.cmake")
cmake_minimum_required(VERSION 3.10)
project(DeribitOrderManagement)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_TOOLCHAIN_FILE "C:/Users/WELCOME/Documents/GoQuant/deribit_order_management/vcpkg/scripts/buildsystems/vcpkg.cmake")

find_package(CURL REQUIRED)
find_package(websocketpp CONFIG REQUIRED)
find_package(Boost REQUIRED)

add_executable(deribit_order_management 
    src/main.cpp
    src/order_manager.cpp
    src/websocket_server.cpp
    src/utils.cpp
)

target_include_directories(deribit_order_management PRIVATE include)

target_link_libraries(deribit_order_management PRIVATE CURL::libcurl)
target_link_libraries(deribit_order_management PRIVATE websocketpp::websocketpp)