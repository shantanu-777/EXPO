#ifndef PARSER_H
#define PARSER_H
#include <string>
#include <vector>
#include <memory>
#include "lexer.h"
using namespace std;
 // Contains the Token class or struct definition

class ASTNode; // Forward declaration of ASTNode

class Parser {
public:
    explicit Parser(const std::vector<Token> &tokens);
    std::unique_ptr<ASTNode> parse();

private:
    std::vector<Token> tokens;
    size_t position;

    Token currentToken();
    void advance();
    std::unique_ptr<ASTNode> parsePrimary();
    std::unique_ptr<ASTNode> parseExpression();
    std::unique_ptr<ASTNode> parseBinaryOp(std::unique_ptr<ASTNode> left, int precedence);
};

#endif // PARSER_H
