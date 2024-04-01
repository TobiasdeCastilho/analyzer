#ifndef INPUTS_H

const std::vector<std::string> ignoreSymbols = {
    " ",
    "\n",
    "\t",
    "\r",
    "\v",
    "\f",
    ""
};
const std::vector<std::string> breakSymbols = {
    "+",
    "-",
    "*",
    "/",
    ";",
    "=",
    "(",
    ")",
    "{",
    "}",
    " "
};
const std::map<std::string,std::string> keyWords = {
    {"if", "KW_IF"},
    {"else", "KW_ELSE"},
    {"int", "KW_INT"},    
    {"+", "KW_SUM"},
    {"-", "KW_SUB"},
    {"*", "KW_MUL"},
    {"/", "KW_DIV"},
    {";", "KW_SEMICOLON"},
    {"=", "KW_ASSIGN"},
    {"(", "KW_OPEN_PARENTHESES"},
    {")", "KW_CLOSE_PARENTHESES"},
    {"{", "KW_OPEN_BRACKET"},
    {"}", "KW_CLOSE_BRACKET"},    
};
const std::vector<std::pair<std::string,std::string>> expressions = {
    {"IDENTIFIER", "[a-zA-Z_][a-zA-Z0-9_]*"},
    {"NUMBER", "[0-9]+"},
    //{"FLOAT", "[0-9]+\\.[0-9]+"},    
};

#define INPUTS_H

#endif