# CMakeList.txt: проект CMake для Colloquium OS 1; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#

# Добавьте источник в исполняемый файл этого проекта.
add_executable (CMakeTarget "Colloquium OS 1.cpp" "Colloquium OS 1.h" "fact.cpp" "fact.h" "delete_duplicates.cpp" "delete_duplicates.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET CMakeTarget PROPERTY CXX_STANDARD 20)
endif()

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
