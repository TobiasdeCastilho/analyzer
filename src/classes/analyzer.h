#ifndef ANALYZER_H

#include "../defs/globals.h"
#include "../defs/syntax.h"
#include "../functions/tokens.h"

#define DEBUG if(!this->silent) std::cout
#define ERROR std::cerr << _ERROR
#define OUT if(this->out) this->output

#include <map>
#include <regex>
#include <string>
#include <iostream>

struct FilePosition
{
  int x, y;
};

struct AnalyzerData
{
  FilePosition position;
  std::string value;
};

class Analyzer 
{
  private:    
    bool out;    
    FilePosition readFile;
    int countNumbers = 0, countFloat = 0, countIdentifiers = 0;
    std::fstream input;
    std::map<std::string, AnalyzerData> data;
    std::ofstream output;      
    std::string lexeme;
    
    bool addToken(std::string key);
    bool insertData(std::string key, AnalyzerData data);
    bool verify(std::string key);      
  public:
    Analyzer(std::string inFile, std::string outFile);
    ~Analyzer();
        
    bool silent = false;
    void read();
    void verifySyntax();
};

#define ANALYZER_H

#include "analyzer.cpp"

#endif