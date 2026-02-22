message(">> BUILDING SDK @ ${CMAKE_CURRENT_SOURCE_DIR}")

add_library (SAPA_SDK STATIC)

#Include directories
target_include_directories(SAPA_SDK
PUBLIC
	include
)

#Inlcude Sources
target_sources(SAPA_SDK
PRIVATE
	neuron.cpp
	structure.cpp
PUBLIC
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
 )

