#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "trace_picas::trace_picas" for configuration ""
set_property(TARGET trace_picas::trace_picas APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(trace_picas::trace_picas PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_NOCONFIG "CXX"
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libtrace_picas.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS trace_picas::trace_picas )
list(APPEND _IMPORT_CHECK_FILES_FOR_trace_picas::trace_picas "${_IMPORT_PREFIX}/lib/libtrace_picas.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
