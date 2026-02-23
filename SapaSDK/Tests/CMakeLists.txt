message(">> BUILDING TESTS @ ${CMAKE_CURRENT_SOURCE_DIR}")

add_executable (SAPA_TESTS)

#Include directories
target_include_directories(SAPA_TESTS
PUBLIC
	include
	SAPA_SDK
	SIM_CORE
	SAPA_LANG
)

#Link libraries
target_link_libraries(SAPA_TESTS
	
PRIVATE
	SAPA_SDK
	SIM_CORE
	SAPA_LANG
)

#Inlcude Sources
target_sources(SAPA_TESTS
PRIVATE
	TestMain.cpp
)

