add_executable(Sfml3.2 main.cpp)

target_include_directories(Sfml3.2 PRIVATE ${SFML_INCLUDE_DIR})
target_compile_features(Sfml3.2 PUBLIC cxx_std_17)
target_compile_definitions(Sfml3.2 PRIVATE SFML_STATIC)

target_link_libraries(Sfml3.2 ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})