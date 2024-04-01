#ifndef TOKENS_H

#include <vector>
#include <string>
#include <map>

#include "../defs/inputs.h"

std::string removeIngoreSymbols(std::string symbol);
bool ignoreSymbol(std::string symbol);
bool breakSymbol(std::string symbol);

#define TOKENS_H

#include "tokens.cpp"

#endif