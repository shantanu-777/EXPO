#include <iostream>
#include <memory>
#include <vector>
#include "parser.h"
using namespace std;


Parser::Parser(const vector<Token> &tokens) 
    : tokens(tokens), position(0) {}


Token Parser::currentToken() {
    return position < tokens.size() ? tokens[position] : Token(END_OF_STATEMENT, "");
}

void Parser::advance() {
    if (position < tokens.size()) position++;
}

unique_ptr<ASTNode> Parser::parse() {
    return parseExpression();
}

unique_ptr<ASTNode> Parser::parsePrimary() {
    Token token = currentToken();
    if (token.type == NUMBER) {
        advance();
        return make_unique<NumberNode>(stoi(token.value));
    }
    throw runtime_error("Unexpected token in parsePrimary()");
}

unique_ptr<ASTNode> Parser::parseExpression() {
    auto left = parsePrimary();
    return parseBinaryOp(move(left), 0); // Start with lowest precedence
}

unique_ptr<ASTNode> Parser::parseBinaryOp(unique_ptr<ASTNode> left, int precedence) {
    while (true) {
        Token token = currentToken();
        if (token.type != OPERATOR) break;

        // Assume all operators have the same precedence for simplicity
        advance();
        auto right = parsePrimary();
        left = make_unique<BinaryOpNode>(token.value[0], move(left), move(right));
    }
    return left;
}
