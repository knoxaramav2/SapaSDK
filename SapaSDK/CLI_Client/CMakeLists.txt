message(">> BUILDING CLI @ ${CMAKE_CURRENT_SOURCE_DIR}")

add_executable (CLI_Client)

#Include directories
target_include_directories(CLI_Client
PUBLIC
	include
	SAPA_SDK
	SIM_CORE
)

#Link libraries
target_link_libraries(CLI_Client
	
PRIVATE
	SAPA_SDK
)

#Inlcude Sources
target_sources(CLI_Client
PRIVATE
	CLI_Client.cpp
)

