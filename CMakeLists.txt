cmake_minimum_required(VERSION 3.14)
project(Colloquium_OS_1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Общие исходные файлы
set(COMMON_SOURCES
    fact.cpp
    delete_duplicates.cpp
    reverse_list.cpp
)

# Основной исполняемый файл
add_executable(Colloquium_OS_1 
    "Colloquium OS 1.cpp"
    ${COMMON_SOURCES}
)

target_include_directories(Colloquium_OS_1 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# Исполняемый файл для тестов
add_executable(Colloquium_OS_1_Tests
    "test_fact.cpp"
    "test_delete_duplicates.cpp"
    "test_reverse_list.cpp"
    ${COMMON_SOURCES}
)

target_include_directories(Colloquium_OS_1_Tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(Colloquium_OS_1_Tests gtest gtest_main)

enable_testing()
add_test(NAME Colloquium_OS_1_Tests COMMAND Colloquium_OS_1_Tests)