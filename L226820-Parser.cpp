// Recursive Descent Parser with Parse Tree Output // Saves tree to parse_tree.txt

#include <iostream> #include <fstream> #include <sstream> #include <vector> #include <string> #include <stdexcept> #include <map> #include <iomanip>

using namespace std;

// Token structure struct Token { string type; // e.g., "id", "rw", "ltr" int index;   // index into the corresponding table string value; // actual string value };

// Global variables vector<Token> tokens; int current = 0; ofstream treeOut("parse_tree.txt"); int indentLevel = 0;

// Symbol tables map<int, string> symbolTable; map<int, string> literalTable; map<int, string> rwTable;

// Function declarations void Functions(); void ArgList(); void ArgListPrime(); void Arg(); void Stmt(); void CompStmt(); void StmtList(); void StmtListPrime(); void Expr(); void RValue(); void RValuePrime(); void Mag(); void MagPrime(); void Term(); void TermPrime(); void Factor();

// Utility functions void printNode(const string& label) { for (int i = 0; i < indentLevel; ++i) treeOut << (i == indentLevel - 1 ? "├── " : "│   "); treeOut << label << "\n"; }

void indentUp() { indentLevel++; } void indentDown() { if (indentLevel > 0) indentLevel--; }

Token peek() { if (current < tokens.size()) return tokens[current]; return {"", -1, ""}; }

Token advance() { if (current < tokens.size()) return tokens[current++]; throw runtime_error("Unexpected end of input"); }

bool match(const string& expectedType, const string& expectedValue = "") { Token token = peek(); if (token.type == expectedType && (expectedValue.empty() || token.value == expectedValue)) { advance(); printNode(token.value); return true; } return false; }

void expect(const string& expectedType, const string& expectedValue = "") { if (!match(expectedType, expectedValue)) { throw runtime_error("Syntax Error: expected " + expectedType + " " + expectedValue); } }

string lookupValue(const Token& token) { if (token.type == "id") return symbolTable[token.index]; if (token.type == "ltr") return literalTable[token.index]; if (token.type == "rw") return rwTable[token.index]; return token.value; }

// Grammar Rule Implementations void Functions() { printNode("Functions"); indentUp(); expect("rw", "28"); // function Token id = advance(); expect("id"); printNode("Identifier: " + symbolTable[id.index]); expect("("); ArgList(); expect(")"); CompStmt(); indentDown(); }

void ArgList() { printNode("ArgList"); indentUp(); if (peek().type == "rw") { Arg(); ArgListPrime(); } else { printNode("ε"); } indentDown(); }

void ArgListPrime() { printNode("ArgList'"); indentUp(); if (match(",")) { Arg(); ArgListPrime(); } else { printNode("ε"); } indentDown(); }

void Arg() { printNode("Arg"); indentUp(); expect("rw"); // Type Token id = advance(); expect("id"); printNode("Identifier: " + symbolTable[id.index]); indentDown(); }

void Stmt() { printNode("Stmt"); indentUp(); if (peek().type == "rw") { CompStmt(); } else { Expr(); } indentDown(); }

void CompStmt() { printNode("CompStmt"); indentUp(); expect("{"); StmtList(); expect("}"); indentDown(); }

void StmtList() { printNode("StmtList"); indentUp(); if (peek().type != "}") { Stmt(); StmtListPrime(); } else { printNode("ε"); } indentDown(); }

void StmtListPrime() { printNode("StmtList'"); indentUp(); if (peek().type != "}") { Stmt(); StmtListPrime(); } else { printNode("ε"); } indentDown(); }

void Expr() { printNode("Expr"); indentUp(); Token id = advance(); expect("id"); printNode("Identifier: " + symbolTable[id.index]); expect(":="); RValue(); indentDown(); }

void RValue() { printNode("RValue"); indentUp(); Mag(); RValuePrime(); indentDown(); }

void RValuePrime() { printNode("RValue'"); indentUp(); if (peek().value == "==" || peek().value == "<" || peek().value == ">") { Token op = advance(); printNode("Compare: " + op.value); Mag(); RValuePrime(); } else { printNode("ε"); } indentDown(); }

void Mag() { printNode("Mag"); indentUp(); Term(); MagPrime(); indentDown(); }

void MagPrime() { printNode("Mag'"); indentUp(); if (peek().value == "+" || peek().value == "-") { Token op = advance(); printNode("Op: " + op.value); Term(); MagPrime(); } else { printNode("ε"); } indentDown(); }

void Term() { printNode("Term"); indentUp(); Factor(); TermPrime(); indentDown(); }

void TermPrime() { printNode("Term'"); indentUp(); if (peek().value == "*" || peek().value == "/") { Token op = advance(); printNode("Op: " + op.value); Factor(); TermPrime(); } else { printNode("ε"); } indentDown(); }

void Factor() { printNode("Factor"); indentUp(); if (peek().value == "(") { advance(); printNode("("); Expr(); expect(")"); } else if (peek().type == "id") { Token id = advance(); printNode("Identifier: " + symbolTable[id.index]); } else if (peek().type == "ltr") { Token lit = advance(); printNode("Literal: " + literalTable[lit.index]); } else { throw runtime_error("Syntax Error in Factor"); } indentDown(); }

// Main Function to drive the parser int main() { // Load tables ifstream lex("lexems.txt"), sym("symbol_table.txt"), lit("literal_table.txt"), rw("rw.txt"); string line;

while (getline(sym, line)) {
    int index = symbolTable.size();
    symbolTable[index] = line;
}
while (getline(lit, line)) {
    int index = literalTable.size();
    literalTable[index] = line;
}
while (getline(rw, line)) {
    int index = rwTable.size();
    rwTable[index] = line;
}

// Read tokens
while (lex >> line) {
    if (line == "<") continue;
    string type;
    int idx;
    size_t pos = line.find(',');
    type = line.substr(1, pos - 1);
    idx = stoi(line.substr(pos + 1));
    string val = (type == "id" ? symbolTable[idx] : (type == "rw" ? rwTable[idx] : literalTable[idx]));
    tokens.push_back({type, idx, val});
}

try {
    Functions();
    treeOut.close();
    cout << "Parse successful. Tree saved to parse_tree.txt" << endl;
} catch (exception& e) {
    cerr << "Parse error: " << e.what() << endl;
}

return 0;

}

