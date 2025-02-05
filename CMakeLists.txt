cmake_minimum_required(VERSION 3.25.1)

project(sfml_collection VERSION 0.0.1)

include(CheckTypeSize)
include(cmake/Functions.cmake)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SFML_DIR "${CMAKE_SOURCE_DIR}/SFML")
set(SFML_INCLUDE_DIR "${SFML_DIR}/include")

check_type_size(void* SIZEOF_VOID_PTR)
if(${SIZEOF_VOID_PTR} STREQUAL "4")
	set(ARCH_32BITS 1)
elseif(${SIZEOF_VOID_PTR} STREQUAL "8")
	set(ARCH_64BITS 1)
endif()

if (UNIX)
	if (ARCH_64BITS)
		set(SFML_LIBRARY_DIR "${SFML_DIR}/lib/linux")
		get_file_name_list("${SFML_LIBRARY_DIR}" "*.so" False SFML_LIBS)
	elseif(ARCH_32BITS)
		message(FATAL_ERROR "No supported libs for x86 system.")
	endif()
elseif(WIN32)
	if (ARCH_64BITS)
		set(SFML_LIBRARY_DIR "${SFML_DIR}/lib/windows")
		get_file_name_list("${SFML_LIBRARY_DIR}" "*.lib" False SFML_LIBS)
		get_file_name_list("${SFML_LIBRARY_DIR}" "*.dll" True SFML_DLL_LIBS_FOR_COPY)
	elseif(ARCH_32BITS)
		message(FATAL_ERROR "No supported libs for x86 system")
	endif()
endif()

add_subdirectory(hordes)

