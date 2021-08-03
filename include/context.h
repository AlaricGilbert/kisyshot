#pragma once

#include <vector>
#include <string>
#include <string_view>
#include "ast/token.h"
#include "ast/syntax/syntax_unit.h"
namespace kisyshot{
    struct CodePosition{
    public:
        std::size_t line;
        std::size_t offset;
    };
    class Context{
    public:
        /**
         * The path of the given code, used in diagnostic.
         */
        std::string path;
        /**
         * The code reference string.
         */
        std::string_view code;
        /**
         * The reference to the lines of the codes.
         */
        std::vector<std::string_view> lines;
        /**
         * The tokens lexed by Lexer are stored here.
         */
        std::vector<std::unique_ptr<kisyshot::ast::Token>> tokens;
        /**
         * The abstract syntax tree generated by parser.
         */
        std::shared_ptr<kisyshot::ast::syntax::SyntaxUnit> syntaxTree;
        /**
         * The symbol table which maps the relation ship between mangled name and its variable definition node
         */
        std::unordered_map<std::string, std::shared_ptr<kisyshot::ast::syntax::VarDefinition>> symbols;
        /**
         * The symbol table which maps the relation ship between name and its function node
         */
        std::unordered_map<std::string, std::shared_ptr<kisyshot::ast::syntax::Function>> functions;
        /**
         * The gloabal var definitions
         */
        std::vector<std::shared_ptr<ast::syntax::VarDefinition>> globals;
        /**
         * Strings
         */
        std::unordered_map<std::string, std::string> strings;
        /**
         * The index of the current syntax context.
         */
        std::size_t contextID;

        Context(const std::string_view &code, std::size_t contextID);

        /**
         * Locate the given token in the source code.
         * @param token
         * @return
         */
        CodePosition locate(const ast::Token& token) const;
        /**
         * Locate the token defined by the index in the source code.
         * @param index
         * @return
         */
        CodePosition locate(std::size_t index) const;

        std::size_t firstOfLine(std::size_t line) const;
        std::size_t lastOfLine(std::size_t line) const;

        const static std::size_t npos = SIZE_MAX;

    private:
        // used for locate tokens
        std::vector<std::size_t> lineStartPos;
    };
}