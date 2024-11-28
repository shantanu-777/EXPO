#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <memory>
#include "parser.h"
#include "ast.h"  // Include AST node definitions.

class Interpreter {
public:
    int execute(const std::unique_ptr<ASTNode> &node);

private:
    int visit(const NumberNode *node);
    int visit(const BinaryOpNode *node);
};

#endif // INTERPRETER_H
