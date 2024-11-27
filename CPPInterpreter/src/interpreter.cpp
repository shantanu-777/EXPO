#include "interpreter.h"
#include <stdexcept>
#include <iostream>
#include <memory>

int Interpreter::execute(const std::unique_ptr<ASTNode> &node) {
    if (auto numberNode = dynamic_cast<const NumberNode *>(node.get())) {
        return visit(numberNode);
    } else if (auto binaryOpNode = dynamic_cast<const BinaryOpNode *>(node.get())) {
        return visit(binaryOpNode);
    }
    throw runtime_error("Unknown AST node type in execute()");
}

int Interpreter::visit(const NumberNode *node) {
    return node->value;
}

int Interpreter::visit(const BinaryOpNode *node) {
    int leftValue = execute(node->left);
    int rightValue = execute(node->right);

    switch (node->op) {
        case '+': return leftValue + rightValue;
        case '-': return leftValue - rightValue;
        case '*': return leftValue * rightValue;
        case '/': 
            if (rightValue == 0) throw runtime_error("Division by zero");
            return leftValue / rightValue;
        default:
            throw runtime_error("Unknown operator in BinaryOpNode");
    }
}
