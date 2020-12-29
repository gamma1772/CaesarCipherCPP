cmake_minimum_required (VERSION 3.18)

project (caesar_cipher)

add_executable (caesar-cipher caesar_cipher.cpp)

install (TARGETS caesar-cipher DESTINATION caesar-cipher/bin)