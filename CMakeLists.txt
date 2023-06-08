cmake_minimum_required(VERSION 3.24)
project(PRACTICA_EDA_II C)

set(CMAKE_C_STANDARD 11)

add_executable(PRACTICA_EDA_II main.c implementations/menu.c implementations/printer.c implementations/user.c implementations/file_reader.c headers/user.h headers/menu.h headers/globals.h headers/menu.h headers/printer.h headers/file_reader.h)
