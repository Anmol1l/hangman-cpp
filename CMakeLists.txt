cmake_minimum_required(VERSION 4.3)
project(hangman-cpp)

set(CMAKE_CXX_STANDARD 20)

add_executable(hangman-cpp src/main.cpp
        src/Random.h
        src/Wordlist.h
        src/Session.h
        src/Session.cpp
)
