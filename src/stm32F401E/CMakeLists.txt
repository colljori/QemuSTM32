cmake_minimum_required(VERSION 2.6)
project(Rabbits_STM32F401E_Platform)

find_package(Rabbits REQUIRED)

add_subdirectory(components)

rabbits_add_configs(stm32F401E.yml)

rabbits_add_dynlib(stm32F401E)
