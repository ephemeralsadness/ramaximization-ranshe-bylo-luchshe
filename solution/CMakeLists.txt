cmake_minimum_required(VERSION 3.16)
project(ramaximization-ranshe-bylo-luchshe)

set(CMAKE_CXX_STANDARD 17)

add_executable(ramaximize main.cpp Solver.cpp Solver.h Reader.cpp Reader.h constants.h data/InputData.h data/InputData.cpp
               data/Request.cpp data/Request.h data/Staff.h data/Staff.cpp data/Qualification.h data/Qualification.cpp
               data/OutputData.cpp data/OutputData.h data/Month.h data/Month.cpp)