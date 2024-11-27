#include "lexer.h"
#include <cctype>

Lexer::Lexer(const std::string &input) : input(input), position(0) {}

char Lexer::currentChar() {
    return position < input.size() ? input[position] : '\0';
}

void Lexer::advance() {
    position++;
}

std::vector<Token> Lexer::tokenize() {
    std::vector<Token> tokens;
    while (currentChar() != '\0') {
        if (std::isspace(currentChar())) {
            advance();
        } else if (std::isdigit(currentChar())) {
            tokens.push_back(tokenizeNumber());
        } else if (std::isalpha(currentChar())) {
            tokens.push_back(tokenizeIdentifier());
        } else {
            tokens.push_back(tokenizeOperator());
        }
    }
    return tokens;
}

Token Lexer::tokenizeNumber() {
    std::string num;
    while (std::isdigit(currentChar())) {
        num += currentChar();
        advance();
    }
    return Token(NUMBER, num);
}

Token Lexer::tokenizeIdentifier() {
    std::string id;
    while (std::isalnum(currentChar()) || currentChar() == '_') {
        id += currentChar();
        advance();
    }
    return Token(IDENTIFIER, id);
}

Token Lexer::tokenizeOperator() {
    char op = currentChar();
    advance();
    return Token(OPERATOR, std::string(1, op));
}
