cmake_minimum_required(VERSION 3.8)

PROJECT(HarmonyTrainer)

INCLUDE (FetchContent)

SET(CMAKE_CXX_STANDARD 17)
SET(CMAKE_EXPORT_COMPILE_COMMANDS ON)
SET(SFML_VERSION "2.6.0")
SET(FETCHCONTENT_QUIET FALSE)

FetchContent_Declare(
	sfml
	GIT_REPOSITORY 	"https://github.com/SFML/SFML.git"
	GIT_TAG 		"${SFML_VERSION}"
	GIT_PROGRESS TRUE
	)

FetchContent_GetProperties(sfml)
if (NOT sfml_POPULATED)
	FetchContent_Populate(sfml)
	add_subdirectory(${sfml_SOURCE_DIR} ${sfml_BINARY_DIR})
endif()

find_package(SFML ${SFML_VERSION} COMPONENTS system window graphics audio)

include_directories(
	include
	include/display/
	include/display/pages
	include/display/components
	src
	src/display
	src/display/pages
	src/display/components
	)

add_executable(${PROJECT_NAME}
	main.cpp

	src/display/pages/menu.cpp
	src/display/pages/customTraining.cpp
	src/display/components/rectangle.cpp
	src/display/components/circle.cpp
	src/display/components/text.cpp
	src/display/components/option.cpp

	src/notes.cpp
	src/manager.cpp
	)

target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-window sfml-system sfml-audio)



