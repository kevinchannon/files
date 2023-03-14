cmake_minimum_required(VERSION 3.12)

Include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.3.2 # or a later release
)

FetchContent_MakeAvailable(Catch2)

enable_testing()

add_executable(files_test
  "csv.test.cpp"
)

target_compile_options(files_test PRIVATE
	$<$<CXX_COMPILER_ID:MSVC>:/W4 /WX>
	$<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wall -Wextra -Wpedantic -Werror>
)

target_include_directories(files_test
  PUBLIC
	  ${CMAKE_SOURCE_DIR}
)

IF(CMAKE_BUILD_TYPE MATCHES Debug)
ENDIF(CMAKE_BUILD_TYPE MATCHES Debug)

target_link_libraries(files_test
  PRIVATE
    Catch2::Catch2WithMain
)

list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)
include(CTest)
include(Catch)

catch_discover_tests(files_test)
