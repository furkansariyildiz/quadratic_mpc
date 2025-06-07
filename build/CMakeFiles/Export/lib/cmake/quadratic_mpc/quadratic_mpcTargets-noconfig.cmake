#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "quadratic_mpc::quadratic_mpc" for configuration ""
set_property(TARGET quadratic_mpc::quadratic_mpc APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(quadratic_mpc::quadratic_mpc PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libquadratic_mpc.so"
  IMPORTED_SONAME_NOCONFIG "libquadratic_mpc.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS quadratic_mpc::quadratic_mpc )
list(APPEND _IMPORT_CHECK_FILES_FOR_quadratic_mpc::quadratic_mpc "${_IMPORT_PREFIX}/lib/libquadratic_mpc.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
