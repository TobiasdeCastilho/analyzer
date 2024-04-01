#ifndef ARGS_H
#error "args.cpp must be included via args.h"
#endif

bool wrongArg(std::string arg){
  for(auto validArg : validArgs){
    if(validArg == arg){
      return false;
    }
  }
  return true;
}