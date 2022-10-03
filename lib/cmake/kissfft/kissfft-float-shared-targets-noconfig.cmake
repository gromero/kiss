#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "kissfft::kissfft-float" for configuration ""
set_property(TARGET kissfft::kissfft-float APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(kissfft::kissfft-float PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libkissfft-float.so.131.1.0"
  IMPORTED_SONAME_NOCONFIG "libkissfft-float.so.131"
  )

list(APPEND _IMPORT_CHECK_TARGETS kissfft::kissfft-float )
list(APPEND _IMPORT_CHECK_FILES_FOR_kissfft::kissfft-float "${_IMPORT_PREFIX}/lib/libkissfft-float.so.131.1.0" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
