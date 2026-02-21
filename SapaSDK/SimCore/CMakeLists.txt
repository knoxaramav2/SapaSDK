message(">> BUILDING SimCore @ ${CMAKE_CURRENT_SOURCE_DIR}")

add_library (SIM_CORE SHARED)

#Include directories
target_include_directories(SIM_CORE
PUBLIC
	include
	SAPA_SDK
)

#Inlcude Sources
target_sources(SIM_CORE
PRIVATE
	runner.cpp
PUBLIC
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)
