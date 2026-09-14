add_executable(stratum-codec_tests test_core.cpp)
target_link_libraries(stratum-codec_tests PRIVATE work)
target_include_directories(stratum-codec_tests PRIVATE ${CMAKE_SOURCE_DIR}/include)
add_test(NAME core COMMAND stratum-codec_tests)
