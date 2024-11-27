#ifndef LEXER_H
#define LEXER_H

#include <string>
#include <vector>

enum TokenType {
    IDENTIFIER,
    NUMBER,
    OPERATOR,
    KEYWORD,
    END_OF_STATEMENT,
    UNKNOWN
};

struct Token {
    int type; // Token type (e.g., NUMBER, OPERATOR, etc.)
    std::string value; // Token value

    Token(int type, const std::string &value) : type(type), value(value) {}
};

const int NUMBER = 1;
const int OPERATOR = 2;
const int END_OF_STATEMENT = 3;


class Lexer {
public:
    explicit Lexer(const std::string &input);
    std::vector<Token> tokenize();

private:
    std::string input;
    size_t position;

    char currentChar();
    void advance();
    Token tokenizeNumber();
    Token tokenizeIdentifier();
    Token tokenizeOperator();
};

#endif // LEXER_H
