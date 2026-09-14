if(${BUILD_TESTING})
	file(MAKE_DIRECTORY "${CMAKE_BINARY_DIR}/tmp/")
	file(MAKE_DIRECTORY "${EXTERNAL}/doctest/")
	file(DOWNLOAD
		"https://github.com/doctest/doctest/releases/download/v2.5.3/doctest-v2.5.3.tar.gz"
		"${CMAKE_BINARY_DIR}/tmp/doctest-v2.5.3.tar.gz"
		INACTIVITY_TIMEOUT 5
		LOG A
		SHOW_PROGRESS
		STATUS S
		TIMEOUT 5
		EXPECTED_HASH SHA256=eb4a39729d091e43d4d593888bf4d145ee9a0f0e13f7404484b6f2fb60d5d50f
	)
	message(STATUS ${A})
	message(STATUS ${S})
	file(ARCHIVE_EXTRACT 
		INPUT "${CMAKE_BINARY_DIR}/tmp/doctest-v2.5.3.tar.gz"
		DESTINATION "${CMAKE_BINARY_DIR}/tmp/doctest-v2.5.3/"
	)
	file(CREATE_LINK
		"${CMAKE_BINARY_DIR}/tmp/doctest-v2.5.3/doctest/doctest.h"
		"${EXTERNAL}/doctest/doctest.hpp"
		COPY_ON_ERROR
		SYMBOLIC
	)
	file(GLOB TESTS CONFIGURE_DEPENDS "*.c")
	foreach(TEST ${TESTS})
		get_filename_component(TEST_NAME ${TEST} NAME_WE)
		add_executable("${PROJECT_NAME}_${TEST_NAME}" ${TEST})
		set_target_properties("${PROJECT_NAME}_${TEST_NAME}" PROPERTIES
			C_STANDARD 23
			C_STANDARD_REQUIRED ON
			C_EXTENSIONS OFF
			LINKER_LANGUAGE C
		)
		target_compile_options("${PROJECT_NAME}_${TEST_NAME}" PRIVATE
			-fmax-errors=1
			-fdiagnostics-parseable-fixits
			-fdiagnostics-generate-patch
			-fdiagnostics-text-art-charset=emoji
		)
		if(ipo_supported AND NOT (CMAKE_BUILD_TYPE STREQUAL "Debug"))
			set_target_properties("${PROJECT_NAME}_${TEST_NAME}" PROPERTIES INTERPROCEDURAL_OPTIMIZATION TRUE)
		endif()
		target_compile_definitions("${PROJECT_NAME}_${TEST_NAME}" PRIVATE
			CMAKE_BUILD_TYPE="${CMAKE_BUILD_TYPE}"
			CMAKE_SOURCE_DIR="${CMAKE_SOURCE_DIR}"
		)
		target_link_libraries("${PROJECT_NAME}_${TEST_NAME}" PRIVATE
			${PROJECT_NAME})
		target_include_directories("${PROJECT_NAME}_${TEST_NAME}" PRIVATE
			"${EXTERNAL}")
		add_test(
			NAME "${TEST_NAME}"
			COMMAND "${PROJECT_NAME}_${TEST_NAME}")
	endforeach()
endif()