CMAKE_MINIMUM_REQUIRED(VERSION 3.13)
PROJECT(NCursesConnectN C)
ADD_COMPILE_OPTIONS(-std=c99 -O2)
SET(CMAKE_C_STANDARD 11)

ADD_EXECUTABLE(NCursesConnectN.out ./main.c window.c window.h game.c game.h Input.c Input.h)

TARGET_LINK_LIBRARIES( NCursesConnectN.out ncurses)



