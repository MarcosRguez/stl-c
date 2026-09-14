file(GLOB_RECURSE H CONFIGURE_DEPENDS "h/*.h")
file(GLOB_RECURSE C CONFIGURE_DEPENDS "c/*.c")
if(H)
	add_library(${PROJECT_NAME})
	set_target_properties(${PROJECT_NAME} PROPERTIES
		C_STANDARD 23
		C_STANDARD_REQUIRED ON
		C_EXTENSIONS OFF
		LINKER_LANGUAGE C
	)
	target_sources(${PROJECT_NAME}
		PUBLIC ${H}
		PRIVATE ${C}
	)
	if(ipo_supported AND NOT (CMAKE_BUILD_TYPE STREQUAL "Debug"))
		set_target_properties(${PROJECT_NAME} PROPERTIES INTERPROCEDURAL_OPTIMIZATION TRUE)
	endif()
	target_compile_options(${PROJECT_NAME} PRIVATE
		-fmax-errors=1
		-fdiagnostics-parseable-fixits
		-fdiagnostics-generate-patch
		-fdiagnostics-text-art-charset=emoji
	)
	target_compile_options(${PROJECT_NAME} PRIVATE
		-Wall -Wextra -Wpedantic
		-Waligned-new
		-Wextra-semi
	)
endif()