#ifndef ANALYZER_H
#error  "analyzer.cpp must be included via analyzer.h"
#endif

Analyzer::Analyzer(std::string inFile, std::string outFile){
  if(inFile == outFile){
    DEBUG << _ERROR << "Input and output files must be different" << std::endl;
    exit(EXIT_FILE_ERROR);
  }

  if(inFile == ""){
    DEBUG << _ERROR << "Input file is required" << std::endl;
    exit(EXIT_FILE_ERROR);
  }

  if(!std::ifstream(inFile).good())
  {
    DEBUG << "File \""<< inFile <<"\" not found" << std::endl;
    exit(EXIT_FILE_NOT_FOUND);
  }  


  this->input.open(inFile);  
  if(outFile != ""){
    this->output.open(outFile);     
    this->out = true;    
  }
}

Analyzer::~Analyzer(){
  this->input.close();
  if(this->out)
    this->output.close();
}

void Analyzer::read(){  
  DEBUG << _INFO << "Reading file..." << std::endl;

  std::string line, token = "";
  int i;
  
  readFile.y = 0;
  try
  {        
    while (std::getline(this->input, line))
    {                    
      readFile.y++;
      readFile.x = 1;

      for (i = 0; i < line.size(); i++)
      {                
        token += line[i];      
        if(this->verify(token))
          token = "";                                             
                
        readFile.x++;
      }        
    }
  }
  catch (const std::invalid_argument &e)
  {    
    ERROR << "Invalid token "+token+" at line " + std::to_string(readFile.y) + " position " + std::to_string(readFile.x - token.size()) << std::endl;
    exit(EXIT_LEXICAL_ERROR);
  }  

  OUT << this->lexeme << std::endl;

  DEBUG << _SUCESS << "No lexical errors founded" << std::endl;
}

bool Analyzer::verify(std::string key) {   
  if(ignoreSymbol(key))
    return false;
  
  std::string lastChar =  key.substr(key.size() - 1, 1);
  key = removeIngoreSymbols(key);

  if(breakSymbol(lastChar)){        
    if(!ignoreSymbol(lastChar) && !breakSymbol(key)){
      this->addToken(key.substr(0, key.size() - 1));        
      this->addToken(lastChar);  
    }
    else
      this->addToken(key);

    return true;
  }
  
  return false;  
}

bool Analyzer::addToken(const std::string key){  
  AnalyzerData data;    

  if(keyWords.find(key) != keyWords.end()){        
    data.value = keyWords.find(key)->second;
    std::string keyValue = keyWords.find(key)->second;    

    return this->insertData(keyValue, data);
  }
  
  std::string token;

  for(auto expression : expressions){
    std::regex regex(expression.second);
    std::smatch match;
    if(std::regex_match(key, match, regex)){            
      data.value = expression.first;

      if(expression.first == "NUMBER"){
        this->countNumbers++;        
        token = "NUMBER_" + std::to_string(this->countNumbers);
        this->data[token] = data;
        
        return this->insertData(token, data);
      }

      if(expression.first == "FLOAT"){
        this->countFloat++;
        token = "FLOAT_" + std::to_string(this->countFloat);        
        return this->insertData(token, data);
      }
            
      this->countIdentifiers++;

      token = "IDENTIFIER_" + std::to_string(this->countIdentifiers);      
      return this->insertData(token, data);;      
    }  
  }

  throw std::invalid_argument("Invalid token: \"" + key + "\"");
}

bool Analyzer::insertData(std::string key, AnalyzerData data) {    
  this->lexeme += "<"+key+">";
  data.position = readFile;
  this->data[key] = data;  

  return true;
}

void Analyzer::verifySyntax(){  
  DEBUG << _INFO << "Verifying syntax..." << std::endl;  

  std::cout << programExpression << std::endl;
  std::regex regexPattern(programExpression);            
  
  if(!std::regex_match(this->lexeme, regexPattern)){  
    DEBUG << _ERROR << "Syntax error founded" << std::endl;
    exit(EXIT_SYNTAX_ERROR);
  }

  DEBUG << _SUCESS << "No syntax errors founded" << std::endl;
}