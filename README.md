# EXPO
# EXPO - C++ Interpreter Project

EXPO is a C++ interpreter designed to evaluate and execute C++ expressions. This project provides a basic framework for interpreting C++ syntax, parsing tokens, and evaluating expressions using an Abstract Syntax Tree (AST). This project aims to understand and implement an interpreter that can parse and execute simple C++ expressions.

## Features
- Tokenizes C++ expressions.
- Parses the tokens into an Abstract Syntax Tree (AST).
- Supports basic arithmetic operations such as addition, subtraction, multiplication, and division.
- Provides error handling for unexpected tokens and invalid syntax.

## Getting Started

### Prerequisites

Before you start, ensure you have the following installed:
- A C++ compiler (e.g., GCC or Clang).
- C++17 support or higher is recommended.
- `Make` (if you wish to compile using a Makefile).

### Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/shantanu-777/EXPO.git
   cd EXPO
   ```

2. Compile the project:
   - If you are using GCC:
     ```bash
     g++ -std=c++17 -o expo main.cpp parser.cpp token.cpp
     ```

3. Run the program:
   ```bash
   ./expo
   ```

### Running the Interpreter
Once you have compiled and built the interpreter, you can use it to interpret basic arithmetic expressions. For example, you can run:

```bash
./expo "3 + 5 * (2 - 8)"
```

This should output the result of the evaluated expression.

## Code Structure

- **`main.cpp`**: The entry point of the program. It initializes the interpreter and starts the parsing process.
- **`parser.cpp`**: Contains the logic for parsing tokens and building an Abstract Syntax Tree (AST).
- **`token.cpp`**: Defines the token types and the process of tokenizing input.
- **`ASTNode` and derived classes**: Represent different types of nodes in the Abstract Syntax Tree.

## Contributing

We welcome contributions! If you'd like to contribute, please fork the repository and submit a pull request with your changes. Here are a few guidelines:
1. Fork the repository and create your branch.
2. Ensure the code follows the existing style and conventions.
3. Write clear commit messages.
4. Make sure the code builds and passes tests.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Acknowledgements

- Thanks to the open-source community for inspiration and support.
- Special thanks to all contributors!

---

Feel free to reach out if you have any questions or need help setting up the project!
```

### Notes:
- **Repository Purpose**: I added a description because it's an interpreter project. If there’s something more specific you'd like to highlight about the project, you can update the "Features" and "Running the Interpreter" sections.
- **Installation Instructions**: These assume a simple setup with a C++ compiler. If you use a specific build system (like `Make` or `CMake`), update that section.
- **Code Structure**: I outlined a basic project structure. Could you modify it if the file structure is different in your case?
