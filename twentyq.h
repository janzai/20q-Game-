#ifndef MESA_CISC187_PROJECT2_TWENTYQ_H
#define MESA_CISC187_PROJECT2_TWENTYQ_H
#include <string>
#include "tree.h"
#include <fstream>
#include <cstring>

// Name: Jamie Anzai
// Student ID: 5550091018

std::string usage(const char*);
std::string help(const char*);
mesa::tree<std::string>* getOptions(int x , char**);
bool getEntry();
std::string getText(std::string);
void playGame(mesa::tree<std::string>* tree);




#endif
