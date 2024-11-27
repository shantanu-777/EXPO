//Header files for modular code.
#ifndef INTERPRETER_H
#define INTERPRETER_H
using namespace std;

#include "parser.h"

class Interpreter {
public:
    int execute(const unique_ptr<ASTNode> &node);

private:
    int visit(const NumberNode *node);
    int visit(const BinaryOpNode *node);
};

#endif // INTERPRETER_H
