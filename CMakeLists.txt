cmake_minimum_required(VERSION 3.1.0)

project(LV_simulation)

# Tell CMake to run moc when necessary
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(SFML_DIR "/usr/share/SFML/cmake/SFML")
find_package(SFML 2.5 COMPONENTS graphics REQUIRED)

# Include the headers
include_directories(include)

# Define the source files
set(SOURCE_FILES src/generate_data.cpp src/LVSimulator.cpp)

# Add an executable with the above sources
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} sfml-graphics)

