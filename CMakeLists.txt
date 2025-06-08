cmake_minimum_required(VERSION 3.0.2)
project(quadratic_mpc)

include_directories(
  include
)

add_library(${PROJECT_NAME} SHARED
  src/quadratic_mpc.cpp
)

find_package(SymEngine REQUIRED)
find_package(PkgConfig REQUIRED)
pkg_check_modules(GMP REQUIRED gmp)

target_include_directories(${PROJECT_NAME} PRIVATE ${GMP_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PRIVATE symengine ${GMP_LIBRARIES})

install(TARGETS ${PROJECT_NAME}
        EXPORT ${PROJECT_NAME}Targets
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        RUNTIME DESTINATION bin
        INCLUDES DESTINATION include)

install(DIRECTORY include/ DESTINATION include)

install(EXPORT ${PROJECT_NAME}Targets
        FILE ${PROJECT_NAME}Targets.cmake
        NAMESPACE ${PROJECT_NAME}::
        DESTINATION lib/cmake/${PROJECT_NAME})

include(CMakePackageConfigHelpers)
write_basic_package_version_file(
  "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake"
  VERSION 1.0.0
  COMPATIBILITY AnyNewerVersion
)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/cmake/Config.cmake.in
               ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake
               @ONLY)

install(FILES
  "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
  "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake"
  DESTINATION lib/cmake/${PROJECT_NAME}
)

add_executable(main src/main.cpp)
target_link_libraries(main PRIVATE ${PROJECT_NAME})
target_include_directories(main PRIVATE include)