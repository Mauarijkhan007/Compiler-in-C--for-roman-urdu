# Compiler-in-C--for-roman-urdu

Here’s a README for your compiler project, which includes a lexer, parser, and 3-address code (TAC) generator based on syntax-directed translation (SDT) principles from the Dragon Book:


---
A custom compiler front-end built in C++ that supports lexical analysis, recursive descent parsing, syntax-directed translation, and generation of Three-Address Code (TAC). Designed for a fictional language with URDU inspired keywords.


---

Features

Lexical Analysis: Identifies tokens like keywords, identifiers, literals, and operators from source code.

Recursive Descent Parser: Parses the language grammar and builds a parse tree.

Syntax-Directed Translation (SDT): Generates TAC while parsing using embedded semantic actions.

Three-Address Code Generation: Produces intermediate code in a format suitable for interpretation or further compilation.



---

Language Support

This compiler understands constructs like:

Adadi        → int  
Ashriya      → float  
Matn         → string  
Harf         → char  
Mantiqi      → bool  
Agar         → if  
Wagarna      → else  
Wapas        → return  
output<-     → output  
input->      → input
refer to reserve word table .txt for complete info 

---

Example Source Code

Adadi Marqazi() {
    Ashriya num_ = -10.5E+12 ::
    num_ = +9.3 ::
    Harf course = "c" ::
    Matn course_ = "Compiler Construction" ::
    Mantiqi _flag != True ::
    
    Agar (_flag)
        output <- "Ok" ::
    Adadi num_ = 10 ::
    Wagarna
        input -> _num ::
    Wapas 0 ::
}


---

Compiler Workflow

1. Lexical Analysis:

Input: source.txt

Output: lexems.txt, symbol_table.txt, literal_table.txt, rw.txt



2. Parsing & TAC Generation:

Input: Lexical outputs

Output: parse_tree.txt, tac.txt





---

Build Instructions

g++ Compiler_with_TAC.cpp -o compiler
./compiler

Ensure that lexems.txt and supporting tables are present in the working directory.


---

Output Files

parse_tree.txt — Visual representation of the parse tree

tac.txt — Three-address code generated from valid syntax



---

Note

Invalid tokens (like @, //, malformed identifiers) are ignored during parsing.

Only valid lexemes (as defined in the language spec) contribute to TAC generation.
