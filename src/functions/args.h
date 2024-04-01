#ifndef ARGS_H

const std::string validArgs[5] = {"-f","-o","-s","-h","-r"};

bool wrongArg(std::string arg);

#define ARGS_H

#include "./args.cpp"

#endif