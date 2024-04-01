#ifndef SYNTAX_H

const std::string
  regexOperator = "(<KW_SUM>|<KW_SUB>|<KW_MUL>|<KW_DIV>)",
  regexExpression = "(<NUMBER_[0-9]+>|<IDENTIFIER_[0-9]+>)",
  regexConditional = "("+regexExpression+regexOperator+regexExpression+")";

const std::string
  regexIntAssignment = "<IDENTIFIER_[0-9]+><KW_ASSIGN>"+regexExpression+"<KW_SEMICOLON>",  
  regexIntDeclaration = "<KW_INT><IDENTIFIER_[0-9]+><KW_SEMICOLON>",    
  regexIf = "<KW_IF><KW_OPEN_PARENTHESES>"+regexConditional+"<KW_CLOSE_PARENTHESES><KW_OPEN_BRACKET>"+"("+regexIntDeclaration+"|"+regexIntAssignment+")"+"<KW_CLOSE_BRACKET>";  
  
const std::string programExpression = "((("+regexIntAssignment+")|("+regexIntDeclaration+")|("+regexIf+")))+";

#define SYNTAX_H

#endif
