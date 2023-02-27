cmake_minimum_required(VERSION 3.1)

# here we specify that the project is C language only, so the default
# C compiler on the system will be used
project(hangman C)

add_executable(main src/hangman/main.c)
