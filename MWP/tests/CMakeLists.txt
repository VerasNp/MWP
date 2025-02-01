set(TestsToRun
    "${CMAKE_CURRENT_SOURCE_DIR}/Vector.test.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Matrix.test.cpp"
)

foreach(test ${TestsToRun})
    get_filename_component(TName ${test} NAME_WE)
    add_executable(${TName} ${test} "${CMAKE_CURRENT_SOURCE_DIR}/main.cpp")
    target_compile_features(${TName} PRIVATE cxx_std_17)
    target_link_libraries(${TName} PRIVATE Doctest MWP)
    add_test(NAME ${TName} COMMAND ${TName})
endforeach()