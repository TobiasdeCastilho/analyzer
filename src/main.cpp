#include <fstream>

#include "classes/analyzer.h"
#include "functions/args.h"

int main(int argc, char *argv[])
{
  std::string arg;
  std::map<std::string, std::string> args;

  for(int i = 1; i < argc; i++)
  {                
    if(argv[i][0] == '-'){      
      if(arg != ""){
        args[arg] = "";
      }

      arg = argv[i];      
      if(wrongArg(arg)){        
        std::cout << _ERROR << "Invalid argument: " << arg << std::endl;
        exit(EXIT_UNKNOW_ARGUMENT);
      }
      continue;
    }        
    args[arg] = argv[i];    
    arg = "";
  }    
  if(arg != ""){
    args[arg] = "";
  }  

  if(args.find("-h") != args.end())
  {
    std::cout << _INFO "Usage: " << argv[0] << " -f <file> [-o <output>] [-s]" << std::endl;
    std::cout << _INFO "Options:" << std::endl;
    std::cout << _INFO "  -f <file>    Input file" << std::endl;
    std::cout << _INFO "  -o <output>  Output file" << std::endl;
    std::cout << _INFO "  -s           Silent mode" << std::endl;
    std::cout << _INFO "Example: " << argv[0] << " -f input.txt -o output.txt" << std::endl;
    std::cout << _INFO "Additional options:" << std::endl;
    std::cout << _INFO "  -h           Show this help" << std::endl;    
    std::cout << _INFO "  -r           Show regular expression" << std::endl;
    exit(EXIT_SUCESS);
  }  

  if(args.find("-r") != args.end())
  {
    std::cout << _INFO << "Regular expression: " << programExpression << std::endl;
    
    exit(EXIT_SUCESS);
  }

  if(args.find("-f") == args.end())
  {
    std::cout << _ERROR << "Input file is required" << std::endl;
    exit(EXIT_FILE_ERROR);
  }

  Analyzer analyzer(args["-f"],args["-o"]);
  if(args.find("-s") != args.end()){    
    analyzer.silent = true;
  }  

  try
  {    
    analyzer.read();  
    analyzer.verifySyntax();  
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
  }
  
  return 0;
}