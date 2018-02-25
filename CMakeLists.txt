cmake_minimum_required(VERSION 2.8)
project(Continuum)
include(modules/Utils.cmake)

message("Is MINGW build = ${MINGW}")
message("Is MSVC build = ${MSVC}")

# Re-set some CMake variables
if(MINGW)
	message("Setting GCC flags")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g -static-libgcc")
    # set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -std=c++11 -g")

    set(SDL2_PATH "${CMAKE_SOURCE_DIR}/dependencies/MinGW/SDL2/i686-w64-mingw32")
elseif(MSVC)
 	message("Setting MSVC flags")
 	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /Z7")

	# Path for the SDL2 dependencies
        set(SDL2_PATH "${CMAKE_SOURCE_DIR}/dependencies/MSVC/SDL2")
	# set(SDL2_image_PATH "${CMAKE_SOURCE_DIR}/dependencies/SDL2_image")
	# set(SDL2_TTF_PATH "${CMAKE_SOURCE_DIR}/dependencies/SDL2_ttf")
	# set(SDL2MIXERDIR "${CMAKE_SOURCE_DIR}/dependencies/SDL2_mixer")
else()

endif()


set(GSL_INCLUDE_PATH "${CMAKE_SOURCE_DIR}/dependencies/GSL/include") 

message("GSL_INCLUDE_PATH -> ${GSL_INCLUDE_PATH}")

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/modules")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")

# Dependecies
find_package(OpenGL REQUIRED)
find_package(SDL2 REQUIRED)
# find_package(SDL2_image REQUIRED)
# find_package(SDL2_ttf REQUIRED)
# find_package(SDL2_mixer REQUIRED)

# Generate our executable
file(GLOB_RECURSE CONTINUUM_SOURCES
	${CMAKE_SOURCE_DIR}/src/*.cpp 
	${CMAKE_SOURCE_DIR}/src/*.hpp 
	${CMAKE_SOURCE_DIR}/src/*.h
)
add_executable(Continuum ${CONTINUUM_SOURCES})

# Get our own header directories
HEADER_DIRECTORIES(CONTINUUM_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/src)

# Add the include directories to the build
include_directories(
	${CONTINUUM_INCLUDE_DIR}
    ${SDL2_INCLUDE_DIR}
    # ${SDL2_IMAGE_INCLUDE_DIR}
    # ${SDL2_TTF_INCLUDE_DIR}
    # ${SDL2_MIXER_INCLUDE_DIR}
	${GSL_INCLUDE_PATH}
)

# Tell which libraries we need to link with
target_link_libraries(Continuum
    ${SDL2_LIBRARY}
    # ${SDL2_IMAGE_LIBRARY}
    # ${SDL2_TTF_LIBRARY}
    # ${SDL2_MIXER_LIBRARY}
)