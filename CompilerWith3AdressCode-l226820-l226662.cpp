#include <iostream>
#include <string>
#include <fstream>
#include <vector>
const int BUFFER_SIZE = 25;
char buffer1[BUFFER_SIZE], buffer2[BUFFER_SIZE];
char* currentBuffer = buffer1;  
int forward = 0;  
bool isBuffer1Active = true;
const int SIZE = 62; 
std:: string lex;
 std::ofstream file("LEXEME_L226820.txt");
 std::ofstream ferr("ERROR_l226820.txt");
std::vector<std::string> SymbolTable;
std::vector<std::string> litTable;
std::string keywords[SIZE] = {
    "asm", "Wagarna", "new", "this", "auto", "enum", "operator", "throw", "Mantiqi", "explicit", "private",
    "True", "break", "export", "protected", "try", "case", "extern", "public", "typedef", "catch", "False", 
    "register", "typeid", "Harf", "Ashriya", "typename", "Adadi", "class", "for", "Wapas", "union", "const", 
    "dost", "short", "unsigned", "goto", "signed", "using", "continue", "Agar", "sizeof", "virtual", "default", 
    "inline", "static", "Khali", "delete", "volatile", "do", "long", "struct", "double", "mutable", "switch", 
    "while", "namespace", "template", "Marqazi", "Matn", "input->", "output<-"};
const int ROWS = 48;
const int COLS = 27;
int advance= 26;
int accept = 25;
int T[ROWS][COLS] = {
 {5,1,2,11,12,17,20,27,29,9,15,15,8,8,8,8,8,8,33,24,-1,31,46,-1,-1,0,1},
{1,1,2,-1,43,44,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,4,0,1},
{2,2,2,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,3,0,1},
{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,1,0},
{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,1,0},
{5,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,39,-1,-1,-1,6,0,1},
{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,1,0},
{7,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,6,0,1},
{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,1,1},
{-1,-1,-1,-1,-1,-1,-1,-1,-1,10,-1,-1,-1,-1,-1,-1,-1,-1,-1,16,-1,-1,-1,-1,-1,0,1},
{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,1,1},
{5,-1,-1,23,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,23,-1,-1,-1,-1,14,0,1},
{5,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,13,0,1},
{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,1,0},
{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,1,0},
{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,1,1},
{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,1,1},
{-1,-1,-1,-1,-1,18,18,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,18,-1,-1,-1,-1,19,0,1},
{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,1,1},
{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,1,0},
{-1,-1,-1,-1,-1,-1,21,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,21,-1,-1,-1,-1,22,0,1},
{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,1,1},
{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,1,0},
{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,1,1},
{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,25,-1,-1,-1,-1,26,0,1},
{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,1,1},
{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,1,0},
{-1,-1,-1,-1,-1,-1,-1,28,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,1},
{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,1,1},
{-1,-1,-1,-1,-1,-1,-1,-1,30,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,1},
{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,1,1},
{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,32,-1,-1,-1,-1,-1,0,1},
{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,1,1},
{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,34,-1,-1,-1,-1,-1,-1,38,-1,-1,-1,-1,-1,37,0,1},
{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,35,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,34,0,1},
{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,35,-1,-1,-1,-1,-1,-1,36,-1,-1,-1,-1,-1,34,0,1},
{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,1,1},
{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,1,0},
{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,36,38,0,1},
{7, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 1},
{42, -1, -1, 41, 41, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 1},
{42, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 1},
{42, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 6, 0, 1},
{-1, -1, -1, -1, -1, -1, 45, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 1},
{-1, -1, -1, -1, 45, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 1},
{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 4, 0, 1},
{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 47, -1, 46, 0, 1},
{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, 1}

};
std::ifstream inputFile("INPUT_L226820.txt");  


bool loadBuffer(char* buffer) {
    if (!inputFile.eof()) {
        int byte =inputFile.read(buffer, BUFFER_SIZE).gcount();
        if(byte<BUFFER_SIZE)buffer[byte-1]=EOF;
        return inputFile.gcount() > 0; 
    }
    return false;
}


char getNextChar() {
    if (forward >= BUFFER_SIZE) { 
        forward = 0; 

        if (!inputFile.eof()) {  
            isBuffer1Active = !isBuffer1Active; 
            currentBuffer = isBuffer1Active ? buffer1 : buffer2;  

            if (!loadBuffer(currentBuffer)) { 
                return EOF; 
            }
        } else {
            return EOF; 
        }
    }

    return currentBuffer[forward++]; 
}


bool Accept(int state)
{
    return(T[state][accept]==1);
}
bool Advance(int state)
{
     return (T[state][advance]==1);
    
}
bool Error(int state)
{
    return (state==-1);
}
int getCharCategory(int state, char ch) { 
    int returnVal;

    switch (ch) {
        case '0' ... '9': returnVal = 0; break;  // Digits
        case 'a' ... 'z': case 'A' ... 'Z': returnVal = (ch == 'E' && (state==7||state==5) )? -1 : 1; break;
        case '_': returnVal = 2; break;  // Underscore
        case '+': returnVal = 3; break;  // Plus
        case '-': returnVal = 4; break;  // Minus
        case '<': returnVal = 5; break;  // Less than
        case '>': returnVal = 6; break;  // Greater than
        case '|': returnVal = 7; break;  // Pipe
        case '&': returnVal = 8; break;  // Ampersand
        case ':': returnVal = 9; break;  // Colon
        case '%': returnVal = 10; break; // Percent
        case '*': returnVal = 11; break; // Asterisk
        case '[': returnVal = 12; break; // Left square bracket
        case ']': returnVal = 13; break; // Right square bracket
        case '{': returnVal = 14; break; // Left curly brace
        case '}': returnVal = 15; break; // Right curly brace
        case '(': returnVal = 16; break; // Left parenthesis
        case ')': returnVal = 17; break; // Right parenthesis
        case '/': returnVal = 18; break; // Forward slash
        case '=': returnVal = 19; break; // Equals
        case '.': returnVal = 20; break; // Dot
        case '!': returnVal = 21; break; // Exclamation mark
        case '"': returnVal = 22; break; // Double quote
        case '\n': returnVal = 23; break; // Newline
        default: returnVal = 24; break; // Default case for Others
    }
    if(returnVal==-1)return -1;
    return (T[state][returnVal] == -1) ? 24 : returnVal;
}
int linearSearch(std::string arr[], int size, std::string target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; 
        }
    }
    return -1;  
}

void writeToFile(const std::string arr[], int size, const std::string& filename) {
    std::ofstream file(filename);

    if (!file) {
        std::cerr << "Error opening file!" << std::endl;
        return;
    }

    for (int i = 0; i < size; i++) {
        file << i+1 << "\t" << arr[i] << "\n";
    }

    file.close();
}
void writeToFile(const std::vector<std::string>& vec, const std::string& filename) {
    std::ofstream file(filename);

    if (!file) {
        std::cerr << "Error opening file!" << std::endl;
        return;
    }

    for (size_t i = 0; i < vec.size(); i++) {
        file << i +1<< "\t" << vec[i] << "\n";
    }

    file.close();
}
int addToVector(std::vector<std::string>& vec, const std::string& element) {
   
    for (size_t i = 0; i < vec.size(); i++) {
        if (vec[i] == element) {
            return i; 
        }
    }
    
    
    vec.push_back(element);
    return vec.size() - 1;
}
void handleLex(int state , std::string lex)
{
     
     if (!file) {
        std::cerr << "Error opening file!" << std::endl;
        return;
    }
    if(state==3){
   
    int id =addToVector(SymbolTable,lex);
     file<<"<id,"<<id<<">";
    }else if(state==4)
    {
        int id = linearSearch(keywords, SIZE , lex);
        if(id==-1){
            ferr<<"<error,"<<lex<<">"<<"\n";
            std::cout<<"error";
        }
        else file<<"<rw,"<<id+1<<">";
        
    }else if(state==47)
    {
        int id = addToVector(litTable,lex);
         file<<"<ltr,"<<id+1<<">";
    }
    else if(state==36){}
    else {
         file<<"<"<<lex<<">";
        
    }
}
int nextState(int& state , char& ch){
    
int cat = getCharCategory(state,ch);
if (cat==-1)return 40;
//||(ch==' '||ch=='\n')&&(cat==24&&(ch==' '||ch=='\n')))||(state==0)
if(T[state][cat]==-1){
 
  if(Accept(state)||(ch==' '||ch=='\n')||(state==0))
    { 
         if((state==0))
    {
        if(ch==' '||ch=='\n'|| ch == '\r')
        {}
        else{
        ferr<<"<error,"<<ch<<">";
          std:: cout<<"error<"<<ch<<">";
         std:: cout<<"\n";
        }
    }
    if(Advance(state)) {
    ch=getNextChar();
    if(ch==EOF)return-2;
        
    }
    state=0;
    return nextState(state , ch);
    }
    
    }
return T[state][cat];
 }












// Recursive Descent Parser with Parse Tree Output // Saves tree to parse_tree.txt

#include <iostream> #include <fstream> #include <sstream> #include <vector> #include <string> #include <stdexcept> #include <map>

// TAC generation
int tempCount = 0;
vector<string> tac;

string newTemp() {
    return "t" + to_string(tempCount++);
}

void emit(const string& code) {
    tac.push_back(code);
}

struct ExprResult {
    string place;
};
 #include <iomanip>

using namespace std;

// Token structure struct Token { string type; // e.g., "id", "rw", "ltr" int index;   // index into the corresponding table string value; // actual string value };

// Global variables vector<Token> tokens; int current = 0; ofstream treeOut("parse_tree.txt"); int indentLevel = 0;

// Symbol tables map<int, string> symbolTable; map<int, string> literalTable; map<int, string> rwTable;

// Function declarations void Functions(); void ArgList(); void ArgListPrime(); void Arg(); void Stmt(); void CompStmt(); void StmtList(); void StmtListPrime(); 
ExprResult Expr() {
    printNode("Expr");
    indentUp();
    Token id = advance();
    expect("id");
    string idName = symbolTable[id.index];
    expect(":=");
    ExprResult rval = RValue();
    emit(idName + " := " + rval.place);
    indentDown();
    return {"none"};
}

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


ExprResult Expr() {
    printNode("Expr");
    indentUp();
    Token id = advance();
    expect("id");
    string idName = symbolTable[id.index];
    expect(":=");
    ExprResult rval = RValue();
    emit(idName + " := " + rval.place);
    indentDown();
    return {"none"};
}


ExprResult RValue() {
    printNode("RValue");
    indentUp();
    ExprResult left = Mag();
    while (peek().value == "==" || peek().value == "<" || peek().value == ">") {
        Token op = advance();
        printNode("Compare: " + op.value);
        ExprResult right = Mag();
        string temp = newTemp();
        emit(temp + " := " + left.place + " " + op.value + " " + right.place);
        left.place = temp;
    }
    indentDown();
    return left;
}

void RValuePrime() { printNode("RValue'"); indentUp(); if (peek().value == "==" || peek().value == "<" || peek().value == ">") { Token op = advance(); printNode("Compare: " + op.value); Mag(); RValuePrime(); } else { printNode("ε"); } indentDown(); }


ExprResult Mag() {
    printNode("Mag");
    indentUp();
    ExprResult left = Term();
    while (peek().value == "+" || peek().value == "-") {
        Token op = advance();
        printNode("Op: " + op.value);
        ExprResult right = Term();
        string temp = newTemp();
        emit(temp + " := " + left.place + " " + op.value + " " + right.place);
        left.place = temp;
    }
    indentDown();
    return left;
}

void MagPrime() { printNode("Mag'"); indentUp(); if (peek().value == "+" || peek().value == "-") { Token op = advance(); printNode("Op: " + op.value); Term(); MagPrime(); } else { printNode("ε"); } indentDown(); }


ExprResult Term() {
    printNode("Term");
    indentUp();
    ExprResult left = Factor();
    while (peek().value == "*" || peek().value == "/") {
        Token op = advance();
        printNode("Op: " + op.value);
        ExprResult right = Factor();
        string temp = newTemp();
        emit(temp + " := " + left.place + " " + op.value + " " + right.place);
        left.place = temp;
    }
    indentDown();
    return left;
}

void TermPrime() { printNode("Term'"); indentUp(); if (peek().value == "*" || peek().value == "/") { Token op = advance(); printNode("Op: " + op.value); Factor(); TermPrime(); } else { printNode("ε"); } indentDown(); }


ExprResult Factor() {
    printNode("Factor");
    indentUp();
    if (peek().value == "(") {
        advance();
        printNode("(");
        ExprResult val = Expr();
        expect(")");
        indentDown();
        return val;
    } else if (peek().type == "id") {
        Token id = advance();
        printNode("Identifier: " + symbolTable[id.index]);
        indentDown();
        return { symbolTable[id.index] };
    } else if (peek().type == "ltr") {
        Token lit = advance();
        printNode("Literal: " + literalTable[lit.index]);
        indentDown();
        return { literalTable[lit.index] };
    } else {
        throw runtime_error("Syntax Error in Factor");
    }
}

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

    ofstream tacOut("tac.txt");
    for (const string& line : tac) {
        tacOut << line << endl;
    }
    tacOut.close();

    cout << "Parse successful. Tree saved to parse_tree.txt" << endl;
} catch (exception& e) {
    cerr << "Parse error: " << e.what() << endl;
}

return 0;

}

