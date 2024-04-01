#ifndef TOKENS_H
#error "tokens.cpp must be included via tokens.h"
#endif

std::string removeIngoreSymbols(std::string symbol){
  if(symbol=="")
    return symbol;
  
  for(auto ignore : ignoreSymbols){    
    if(symbol=="")
      return symbol;    

    while(symbol.substr(0,1) == ignore)
      symbol = symbol.substr(1);    

    if(symbol=="")
      return symbol;
      
    while(symbol.substr(symbol.size() - 1, 1) == ignore){      
      symbol = symbol.substr(0, symbol.size() - 1);

    if(symbol=="")
      return symbol;
    }
  }
  
  return symbol;
}

bool ignoreSymbol(std::string symbol){
  for(auto ignore : ignoreSymbols){
    if(ignore == symbol){
      return true;
    }
  }
  return false;
}

bool breakSymbol(std::string symbol){
  for(auto ignore : breakSymbols){
    if(ignore == symbol){
      return true;
    }
  }
  return false;
}