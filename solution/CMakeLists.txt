cmake_minimum_required(VERSION 3.16)
project(ramaximization-ranshe-bylo-luchshe)

set(CMAKE_CXX_STANDARD 17)

add_executable(ramaximize main.cpp Solver.cpp Solver.h Reader.cpp Reader.h constants.h input/InputData.h input/InputData.cpp
        input/Request.cpp input/Request.h input/Staff.h input/Staff.cpp input/Qualification.h input/Qualification.cpp
        output/OutputData.cpp output/OutputData.h input/Month.h input/Month.cpp output/OutputData.h output/OutputData.cpp
        output/PersonalRest.cpp output/PersonalRest.h output/TotalRest.cpp output/TotalRest.h)