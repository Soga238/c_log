cmake_minimum_required(VERSION 3.17)
project(c_log C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(c_log
        log.c
        log.h
        log_cfg.h
        log_port.c
        main.c log_port.h)
