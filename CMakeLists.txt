cmake_minimum_required (VERSION 3.16)

project(test-boost-log)

set(CMAKE_COLOR_MAKEFILE   ON)


IF (CMAKE_SYSTEM_NAME MATCHES "Windows")
    # 使用的时候，需要在环境变量里面配置 BOOST_PATH 
    include_directories( $ENV{BOOST_PATH})
    LINK_DIRECTORIES( $ENV{BOOST_PATH}/lib64-msvc-14.2/)
    add_compile_options("/std:c++17")
    
	add_compile_options("/MP")
    # 去掉4819 warning /w4是前缀
    add_compile_options(/w44819)
    add_compile_options(/w44251)
    add_compile_options(/w44244)

    add_definitions(-DWIN32)
    add_definitions(-DWIN32_LEAN_AND_MEAN)
    add_definitions(-DNOMINMAX)
    add_definitions(-D_WINSOCK_DEPRECATED_NO_WARNINGS)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
    add_definitions(-D_WIN32_WINNT=0x0601)
    add_definitions(-D_SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING)
    add_definitions(-D_USE_MATH_DEFINES)
	
ENDIF (CMAKE_SYSTEM_NAME MATCHES "Windows")

file(GLOB_RECURSE SRCFILES "src/*.cpp" "src/*.hpp" "src/*.h" "src/*.cc" )
add_executable(test-boost-log ${SRCFILES})

target_link_libraries(test-boost-log Iphlpapi.lib Psapi.lib Userenv.lib shlwapi.lib )