/* =================================================================
PROJECT: Arithmetic Expression Compiler/Parser
DESCRIPTION: Implementing a Recursive Descent Parser to evaluate math expressions.
DELIVERABLE: A C++ program that parses strings and outputs results.
=================================================================
*/

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

/**
 * GRAMMAR RULES:
 * Expression -> Term { ('+'|'-') Term }
 * Term       -> Factor { ('*'|'/') Factor }
 * Factor     -> Number | '(' Expression ')'
 */

class ExpressionParser {
    string input;
    int pos;

    char peek() { return (pos < input.length()) ? input[pos] : '\0'; }
    char get() { return input[pos++]; }

    // Logic for 'Factor' (Numbers or Parentheses)
    double parseFactor() {
        if (peek() == '(') {
            get(); // Consume '('
            double result = parseExpression();
            get(); // Consume ')'
            return result;
        }
        
        // Parsing Numbers
        string num;
        while (isdigit(peek()) || peek() == '.') {
            num += get();
        }
        return stod(num);
    }

    // Logic for 'Term' (Multiplication and Division)
    double parseTerm() {
        double result = parseFactor();
        while (peek() == '*' || peek() == '/') {
            char op = get();
            if (op == '*') result *= parseFactor();
            else result /= parseFactor();
        }
        return result;
    }

public:
    // Logic for 'Expression' (Addition and Subtraction)
    double parseExpression() {
        double result = parseTerm();
        while (peek() == '+' || peek() == '-') {
            char op = get();
            if (op == '+') result += parseTerm();
            else result -= parseTerm();
        }
        return result;
    }

    double evaluate(string expr) {
        input = "";
        // Remove spaces
        for (char c : expr) if (c != ' ') input += c;
        pos = 0;
        return parseExpression();
    }
};

int main() {
    ExpressionParser compiler;

    // Test cases that demonstrate parsing and evaluation
    string expressions[] = {
        "10 + 5 * 2",
        "(10 + 5) * 2",
        "100 / (2 * 5) + 7",
        "50 - 10 / 2 + 3"
    };

    cout << "🚀 Initializing Arithmetic Compiler Engine..." << endl;
    cout << "-------------------------------------------" << endl;

    for (
