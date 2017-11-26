add_executable(Sfml2.1 main.cpp)

set(SFML_STATIC_LIBRARIES TRUE)

find_package(Freetype REQUIRED)
find_package(JPEG REQUIRED)
find_package(SFML 2 COMPONENTS window graphics system REQUIRED)

target_include_directories(Sfml2.1 PRIVATE ${SFML_INCLUDE_DIR})
target_compile_features(Sfml2.1 PUBLIC cxx_std_17)
target_compile_definitions(Sfml2.1 PRIVATE SFML_STATIC)

target_link_libraries(Sfml2.1 ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})