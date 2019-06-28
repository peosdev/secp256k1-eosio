
# include_directories (${CMAKE_SOURCE_DIR}/../secp256k1)

add_compile_definitions(HAVE_CONFIG_H)

add_library(secp256k1 src/secp256k1.c)
target_include_directories( secp256k1 PUBLIC ${CMAKE_SOURCE_DIR}/../src/secp256k1 )
target_include_directories( secp256k1 PRIVATE ${CMAKE_SOURCE_DIR}/../src/secp256k1/src )