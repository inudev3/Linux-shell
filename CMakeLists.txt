cmake_minimum_required(VERSION 3.20)
project(myshell C)

set(CMAKE_C_STANDARD 11)

add_executable(myshell
        main.c redirect.c background.c run.c tokenize.c)
