project(my_chat)
cmake_minimum_required(VERSION 2.6)
find_package(Qt4 REQUIRED)

include_directories(${QT_INCLUDES} ${CMAKE_CURRENT_BINARY_DIR})

set(my_chat_SRCS my_chat.cpp main.cpp)
qt4_automoc(${my_chat_SRCS})
add_executable(my_chat ${my_chat_SRCS})
target_link_libraries(my_chat ${QT_QTCORE_LIBRARY} ${QT_QTGUI_LIBRARY})
