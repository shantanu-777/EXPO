//Contains the C++ source files for different modules.

#include <iostream>
#include <lexer.h>
#include <parser.h>
#include <interpreter.h>
using namespace std;

int main() {
    cout << "Welcome to the C++ Interpreter!" << endl;

    // Placeholder for REPL (Read-Eval-Print Loop)
    string input;
    while (true) {
        cout << ">> ";
        getline(std::cin, input);

        if (input == "exit") {
            cout << "Exiting interpreter." << endl;
            break;
        }

      try {
            // Tokenize input
            Lexer lexer(input);
            auto tokens = lexer.tokenize();

            // Parse tokens into AST
            Parser parser(tokens);
            auto ast = parser.parse();

            // Interpret and execute AST
            Interpreter interpreter;
            int result = interpreter.execute(ast);

            cout << "Result: " << result << endl;
        } catch (const exception &e) {
            cerr << "Error: " << e.what() << endl;
        }
    }

    return 0;
}