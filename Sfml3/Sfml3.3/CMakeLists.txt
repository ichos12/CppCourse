add_executable(Sfml3.3 main.cpp)

target_include_directories(Sfml3.3 PRIVATE ${SFML_INCLUDE_DIR})
target_compile_features(Sfml3.3 PUBLIC cxx_std_17)
target_compile_definitions(Sfml3.3 PRIVATE SFML_STATIC)

target_link_libraries(Sfml3.3 ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})