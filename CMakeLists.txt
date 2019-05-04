cmake_minimum_required(VERSION 3.13)
project(NCursesConnectN C)

set(CMAKE_C_STANDARD 11)

add_executable(NCursesConnectN main.c move.c board.c win.c WindowTrackCursor.c WindowTrackCursor.h board.h move.h win.h ValidInput.c ValidInput.h)
