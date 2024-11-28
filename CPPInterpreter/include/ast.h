#ifndef AST_H
#define AST_H

#include <memory>

// Base class for all AST nodes
class ASTNode {
public:
    virtual ~ASTNode() = default;  // Polymorphic base class.
};

// NumberNode: Represents a numeric literal
class NumberNode : public ASTNode {
public:
    int value;
    explicit NumberNode(int value) : value(value) {}
};

// BinaryOpNode: Represents a binary operation
class BinaryOpNode : public ASTNode {
public:
    char op;
    std::unique_ptr<ASTNode> left, right;

    BinaryOpNode(char op, std::unique_ptr<ASTNode> left, std::unique_ptr<ASTNode> right)
        : op(op), left(std::move(left)), right(std::move(right)) {}
};

#endif // AST_H
