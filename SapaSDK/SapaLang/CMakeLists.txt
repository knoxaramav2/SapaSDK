message(">> BUILDING SDK @ ${CMAKE_CURRENT_SOURCE_DIR}")

add_library (SAPA_LANG STATIC)

#Include directories
target_include_directories(SAPA_LANG
PUBLIC
	include
)

#Inlcude Sources
target_sources(SAPA_LANG
PRIVATE
	sapa_lang.cpp
PUBLIC
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
 )