cmake_minimum_required(VERSION 3.16)

project(Checklist LANGUAGES CXX)

# Standard C++ version for Qt 6
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 1. Enable the "Qt Magic"
set(CMAKE_AUTOMOC ON) # Scans headers for Q_OBJECT
set(CMAKE_AUTOUIC ON) # Processes .ui files
set(CMAKE_AUTORCC ON) # Processes .qrc files

# 2. Find Qt 6 (Ensure the path to your Qt6 installation is in CMAKE_PREFIX_PATH)
find_package(Qt6 REQUIRED COMPONENTS Widgets)

# 3. Handle Directories
include_directories(include)

# Gather files
file(GLOB_RECURSE SOURCES "src/*.cpp")
file(GLOB_RECURSE HEADERS "include/*.h")
file(GLOB UI_FILES "*.ui")
file(GLOB QRC_FILES "*.qrc")

# 4. Create the executable
add_executable(${PROJECT_NAME} 
    ${SOURCES} 
    ${HEADERS} 
    ${UI_FILES} 
    ${QRC_FILES}
)

# 5. Link to Qt 6 Libraries
target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Widgets)

# 6. Windows-specific: Hide the console window for GUI apps
set_target_properties(${PROJECT_NAME} PROPERTIES
    WIN32_EXECUTABLE ON
)

set_target_properties(${PROJECT_NAME} PROPERTIES 
    AUTOUIC_SEARCH_PATHS "${CMAKE_CURRENT_SOURCE_DIR}"
)