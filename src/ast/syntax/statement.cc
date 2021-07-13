#include <rang/rang.h>
#include <ast/syntax/statement.h>

namespace kisyshot::ast::syntax {
    IfStatement::IfStatement(std::size_t ifTokenIndex,
                             const std::shared_ptr<Expression> &condition,
                             const std::shared_ptr<Statement> &ifClause,
                             const std::shared_ptr<Statement> &elseClause) {
        this->ifClause = ifClause;
        this->elseClause = elseClause;
        this->condition = condition;
        this->ifTokenIndex = ifTokenIndex;
    }

    void IfStatement::forEachChild(const std::function<void(std::weak_ptr<SyntaxNode>, bool)> &syntaxWalker) {
        syntaxWalker(condition, false);
        if (elseClause == nullptr) {
            syntaxWalker(ifClause, true);
        } else {
            syntaxWalker(ifClause, false);
            syntaxWalker(elseClause, true);
        }
    }

    void IfStatement::writeCurrentInfo(std::ostream &s) {
        if (s.rdbuf() == std::cout.rdbuf()) {
            s << rang::fg::magenta << "IfStatement "
              << rang::fg::yellow << "<" << this << "> "
              << rang::fg::blue << "condition: "
              << rang::fg::green << "'" << condition->toString() << "'"
              << rang::fg::reset << std::endl;
        } else {
            s << "IfStatement "
              << "<" << this << "> "
              << "condition: "
              << "'" << condition->toString() << "'"
              << std::endl;
        }
    }

    SyntaxType IfStatement::getType() {
        return SyntaxType::IfStatement;
    }

    bool IfStatement::hasChild() {
        return true;
    }

    std::size_t IfStatement::start() {
        return ifTokenIndex;
    }

    std::size_t IfStatement::end() {
        if (elseClause != nullptr)
            return elseClause->end();
        return ifClause->end();
    }

    void IfStatement::setLParenIndex(size_t lParenIndex) {
        lParenIndex = lParenIndex;
    }

    void IfStatement::setRParenIndex(size_t rParenIndex) {
        rParenIndex = rParenIndex;
    }

    void IfStatement::setElse(const std::shared_ptr<Statement> &elseClause) {
        this->elseClause = elseClause;
    }

    const std::shared_ptr<Statement> &IfStatement::getIf() const {
        return ifClause;
    }

    const std::shared_ptr<Statement> &IfStatement::getElse() const {
        return elseClause;
    }

    const std::shared_ptr<Expression> &IfStatement::getCondition() const {
        return condition;
    }

    size_t IfStatement::getIfTokenIndex() const {
        return ifTokenIndex;
    }

    size_t IfStatement::getLParenIndex() const {
        return lParenIndex;
    }

    size_t IfStatement::getRParenIndex() const {
        return rParenIndex;
    }

    void IfStatement::setElseTokenIndex(size_t index) {
        elseTokenIndex = index;
    }

    size_t IfStatement::getElseTokenIndex() const {
        return elseTokenIndex;
    }


    WhileStatement::WhileStatement(std::size_t whileTokenIndex,
                                   const std::shared_ptr<Expression> &condition,
                                   const std::shared_ptr<Statement> &body) {
        this->whileTokenIndex = whileTokenIndex;
        this->condition = condition;
        this->body = body;
    }

    void WhileStatement::forEachChild(const std::function<void(std::weak_ptr<SyntaxNode>, bool)> &syntaxWalker) {
        syntaxWalker(condition, false);
        syntaxWalker(body, true);
    }

    void WhileStatement::writeCurrentInfo(std::ostream &s) {
        if (s.rdbuf() == std::cout.rdbuf()) {
            s << rang::fg::magenta << "WhileStatement "
              << rang::fg::yellow << "<" << this << "> "
              << rang::fg::blue << "condition: "
              << rang::fg::green << "'" << condition->toString() << "'"
              << rang::fg::reset << std::endl;
        } else {
            s << "WhileStatement "
              << "<" << this << "> "
              << "condition: "
              << "'" << condition->toString() << "'"
              << std::endl;
        }
    }

    SyntaxType WhileStatement::getType() {
        return SyntaxType::WhileStatement;
    }

    bool WhileStatement::hasChild() {
        return true;
    }

    std::size_t WhileStatement::start() {
        return whileTokenIndex;
    }

    std::size_t WhileStatement::end() {
        return body->end();
    }

    void WhileStatement::setLParenIndex(size_t lParenIndex) {
        lParenIndex = lParenIndex;
    }

    void WhileStatement::setRParenIndex(size_t rParenIndex) {
        rParenIndex = rParenIndex;
    }

    size_t WhileStatement::getWhileTokenIndex() const {
        return whileTokenIndex;
    }

    size_t WhileStatement::getLParenIndex() const {
        return lParenIndex;
    }

    size_t WhileStatement::getRParenIndex() const {
        return rParenIndex;
    }

    const std::shared_ptr<Expression> &WhileStatement::getCondition() const {
        return condition;
    }

    const std::shared_ptr<Statement> &WhileStatement::getBody() const {
        return body;
    }

    NopStatement::NopStatement(std::size_t semiTokenIndex) {
        tokenIndex = semiTokenIndex;
    }

    void NopStatement::forEachChild(const std::function<void(std::weak_ptr<SyntaxNode>, bool)> &syntaxWalker) {
    }

    void NopStatement::writeCurrentInfo(std::ostream &s) {
        if (s.rdbuf() == std::cout.rdbuf()) {
            s << rang::fg::magenta << "NopStatement "
              << rang::fg::yellow << "<" << this << "> "
              << rang::fg::reset << std::endl;
        } else {
            s << "NopStatement "
              << "<" << this << "> "
              << std::endl;
        }
    }

    SyntaxType NopStatement::getType() {
        return SyntaxType::NopStatement;
    }

    bool NopStatement::hasChild() {
        return false;
    }

    std::size_t NopStatement::start() {
        return tokenIndex;
    }

    std::size_t NopStatement::end() {
        return tokenIndex;
    }

    BreakStatement::BreakStatement(std::size_t breakTokenIndex, std::size_t semiTokenIndex) {
        breakTokenIndex = breakTokenIndex;
        semiTokenIndex = semiTokenIndex;
    }

    void BreakStatement::forEachChild(const std::function<void(std::weak_ptr<SyntaxNode>, bool)> &syntaxWalker) {
    }

    void BreakStatement::writeCurrentInfo(std::ostream &s) {
        if (s.rdbuf() == std::cout.rdbuf()) {
            s << rang::fg::magenta << "BreakStatement "
              << rang::fg::yellow << "<" << this << "> "
              << rang::fg::reset << std::endl;
        } else {
            s << "BreakStatement "
              << "<" << this << "> "
              << std::endl;
        }
    }

    SyntaxType BreakStatement::getType() {
        return SyntaxType::BreakStatement;
    }

    bool BreakStatement::hasChild() {
        return false;
    }

    std::size_t BreakStatement::start() {
        return breakTokenIndex;
    }

    std::size_t BreakStatement::end() {
        return semiTokenIndex == invalidTokenIndex ? breakTokenIndex : semiTokenIndex;
    }

    ContinueStatement::ContinueStatement(std::size_t continueTokenIndex, std::size_t semiTokenIndex) {
        continueTokenIndex = continueTokenIndex;
        semiTokenIndex = semiTokenIndex;
    }

    void ContinueStatement::forEachChild(const std::function<void(std::weak_ptr<SyntaxNode>, bool)> &syntaxWalker) {

    }

    void ContinueStatement::writeCurrentInfo(std::ostream &s) {
        if (s.rdbuf() == std::cout.rdbuf()) {
            s << rang::fg::magenta << "ContinueStatement "
              << rang::fg::yellow << "<" << this << "> "
              << rang::fg::reset << std::endl;
        } else {
            s << "ContinueStatement "
              << "<" << this << "> "
              << std::endl;
        }
    }

    SyntaxType ContinueStatement::getType() {
        return SyntaxType::ContinueStatement;
    }

    bool ContinueStatement::hasChild() {
        return false;
    }

    std::size_t ContinueStatement::start() {
        return continueTokenIndex;
    }

    std::size_t ContinueStatement::end() {
        return semiTokenIndex == invalidTokenIndex ? continueTokenIndex : semiTokenIndex;
    }

    ReturnStatement::ReturnStatement(std::size_t returnTokenIndex, std::size_t semiTokenIndex) {
        returnTokenIndex = returnTokenIndex;
        semiTokenIndex = semiTokenIndex;
        value = nullptr;
    }

    void ReturnStatement::setValue(const std::shared_ptr<Expression> &value) {
        this->value = value;
    }

    void ReturnStatement::forEachChild(const std::function<void(std::weak_ptr<SyntaxNode>, bool)> &syntaxWalker) {
        if (value != nullptr)
            syntaxWalker(value, true);
    }

    void ReturnStatement::writeCurrentInfo(std::ostream &s) {
        if (s.rdbuf() == std::cout.rdbuf()) {
            s << rang::fg::magenta << "ReturnStatement "
              << rang::fg::yellow << "<" << this << "> ";
            if (value != nullptr)
                s << rang::fg::green << "value: '" << value->toString() << "'";
            s << rang::fg::reset << std::endl;
        } else {
            s << "ReturnStatement "
              << "<" << this << "> ";
            if (value != nullptr)
                s << rang::fg::green << "value: '" << value->toString() << "'";
            s << std::endl;
        }
    }

    SyntaxType ReturnStatement::getType() {
        return SyntaxType::ReturnStatement;
    }

    bool ReturnStatement::hasChild() {
        return value != nullptr;
    }

    std::size_t ReturnStatement::start() {
        return returnTokenIndex;
    }

    std::size_t ReturnStatement::end() {
        if (semiTokenIndex != invalidTokenIndex)
            return semiTokenIndex;
        if (value != nullptr)
            return value->end();
        return returnTokenIndex;
    }

    void ReturnStatement::setSemiTokenIndex(size_t semiTokenIndex) {
        semiTokenIndex = semiTokenIndex;
    }

    void BlockStatement::add(const std::shared_ptr<Statement> &child) {
        children.push_back(child);
    }

    void BlockStatement::writeCurrentInfo(std::ostream &s) {
        if (s.rdbuf() == std::cout.rdbuf()) {
            s << rang::fg::magenta << "BlockStatement "
              << rang::fg::yellow << "<" << this << "> "
              << rang::fg::reset << std::endl;
        } else {
            s << "BlockStatement "
              << "<" << this << "> " << std::endl;
        }
    }

    void BlockStatement::forEachChild(const std::function<void(std::weak_ptr<SyntaxNode>, bool)> &syntaxWalker) {
        for (size_t id = 0; id < children.size(); id++) {
            syntaxWalker(children[id], id == children.size() - 1);
        }
    }

    SyntaxType BlockStatement::getType() {
        return SyntaxType::BlockStatement;
    }

    bool BlockStatement::hasChild() {
        return !children.empty();
    }

    std::size_t BlockStatement::start() {
        return lBraceTokenIndex;
    }

    std::size_t BlockStatement::end() {
        if (rBraceTokenIndex != invalidTokenIndex)
            return rBraceTokenIndex;
        if (children.empty())
            return lBraceTokenIndex;
        return children.back()->end();
    }

    BlockStatement::BlockStatement(std::size_t lBraceTokenIndex) {
        lBraceTokenIndex = lBraceTokenIndex;
        rBraceTokenIndex = invalidTokenIndex;
    }

    void BlockStatement::setRBraceTokenIndex(std::size_t rBraceTokenIndex) {
        rBraceTokenIndex = rBraceTokenIndex;
    }

    ExpressionStatement::ExpressionStatement(const std::shared_ptr<Expression> &expression) {
        this->expression = expression;
        this->semiTokenIndex = invalidTokenIndex;
    }

    void ExpressionStatement::setSemiTokenIndex(std::size_t semiTokenIndex) {
        semiTokenIndex = semiTokenIndex;
    }

    void ExpressionStatement::forEachChild(const std::function<void(std::weak_ptr<SyntaxNode>, bool)> &syntaxWalker) {
        syntaxWalker(expression, true);
    }

    void ExpressionStatement::writeCurrentInfo(std::ostream &s) {
        if (s.rdbuf() == std::cout.rdbuf()) {
            s << rang::fg::magenta << "ExpressionStatement "
              << rang::fg::yellow << "<" << this << "> "
              << rang::fg::blue << "expr: "
              << rang::fg::green << "'" << expression->toString() << "'"
              << rang::fg::reset << std::endl;
        } else {
            s << "ExpressionStatement "
              << "<" << this << "> "
              << "expr: "
              << "'" << expression->toString() << "'"
              << std::endl;
        }
    }

    SyntaxType ExpressionStatement::getType() {
        return SyntaxType::ExpressionStatement;
    }

    bool ExpressionStatement::hasChild() {
        return true;
    }

    std::size_t ExpressionStatement::start() {
        return expression->start();
    }

    std::size_t ExpressionStatement::end() {
        if (semiTokenIndex == invalidTokenIndex)
            return expression->end();
        return semiTokenIndex;
    }
}