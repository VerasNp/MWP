set(TestsToRun
    "${CMAKE_CURRENT_SOURCE_DIR}/Matrix.test.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Vector.test.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/LinSys.test.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/MathUtils.test.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/MatrixCSR.test.cpp"
)

foreach(test ${TestsToRun})
    get_filename_component(TName ${test} NAME_WE)
    message(${TName})
    add_executable(${TName} ${test} "${CMAKE_CURRENT_SOURCE_DIR}/main.cpp")
    target_compile_features(${TName} PRIVATE cxx_std_17)
    target_link_libraries(${TName} PRIVATE Doctest MWP)
    add_test(NAME ${TName} COMMAND ${TName})
endforeach()