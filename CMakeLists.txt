cmake_minimum_required(VERSION 3.11)
project(kisyshot)

if (MSVC_VERSION GREATER_EQUAL "1900")
    include(CheckCXXCompilerFlag)
    CHECK_CXX_COMPILER_FLAG("/std:c++latest" _cpp_latest_flag_supported)
    if (_cpp_latest_flag_supported)
        add_compile_options("/std:c++latest")
    endif()
    add_compile_options(/utf-8)
    add_compile_definitions(NOMINMAX)
else()
    if(MINGW)
        add_definitions(-D_WIN32_WINNT=0x0600)
    endif()
    if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
        set(CMAKE_CXX_FLAGS "-g -Wall -Wno-long-long -pedantic -stdlib=libc++")
    else()
        set(CMAKE_CXX_FLAGS "-g -Wall -Wno-long-long -pedantic")
    endif()
    set(CMAKE_CXX_STANDARD 17)
endif()
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/artifacts)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/artifacts)
include_directories(include)
if (WIN32)
    message("test from message")
    execute_process(COMMAND mkdir -p ${PROJECT_SOURCE_DIR}/artifacts/Debug/)
    execute_process(COMMAND cp -R ${PROJECT_SOURCE_DIR}/test/cases ${PROJECT_SOURCE_DIR}/artifacts/Debug/)
else()
    execute_process(COMMAND mkdir -p ${PROJECT_SOURCE_DIR}/artifacts/)
    execute_process(COMMAND cp -r ${PROJECT_SOURCE_DIR}/test/cases ${PROJECT_SOURCE_DIR}/artifacts/cases)
endif()
set(core
        src/ast/syntax/expression.cc
        src/ast/syntax/function.cc
        src/ast/syntax/identifier.cc
        src/ast/syntax/statement.cc
        src/ast/syntax/syntax_node.cc
        src/ast/syntax/syntax_ostream_writer.cc
        src/ast/syntax/syntax_unit.cc
        src/ast/syntax/type.cc
        src/ast/syntax/var_declaration.cc
        src/ast/tac.cc
        src/ast/token.cc
        src/ast/cfg.cc
        src/ast/arms.cc
        src/compiler/codegen.cc
        src/compiler/lexer.cc
        src/compiler/parser.cc
        src/compiler/armcode.cc
        src/compiler/sema.cc
        src/diagnostic/diagnostic.cc
        src/diagnostic/diagnostic_stream.cc
        src/context.cc
        src/context_manager.cc)
set(unittest
        test/main.cc
        test/lex.cc
        test/parse.cc
        test/sema.cc)

add_executable(kisyshot main.cc ${core})
add_executable(tester test/test_all.cc)
# add_executable(tests ${unittest} ${core})
