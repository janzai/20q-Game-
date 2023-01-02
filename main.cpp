#include "twentyq.h"
#include "tree.h"
#include <iostream>

// Name: Jamie Anzai 
// Student ID: 5550091018

int main(int argc, char*argv[]){
  mesa::tree<std::string>* tree = getOptions(argc , argv);
  bool yesOrNo;
  do{
   playGame(tree);
   std::cout << "Would you like to play again\n";
   yesOrNo = getEntry();
  }while(yesOrNo);
  std::cout << "Would you like to save your game?\n";
  yesOrNo = getEntry();
    if(yesOrNo){
      std::string fileName = getText("Please enter a filename to save your game\n");
      std::ofstream file(fileName);
      mesa::saveTree(file , tree);
    } 
  mesa::freeTree(tree);
  std::cout << "Goodbye!\n";
  return 0;
}
