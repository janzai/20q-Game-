#include "twentyq.h"
#include "tree.h"
#include <string>
#include <fstream>
#include <cstring>
#include <limits>

// Name: Jamie Anzai
// Student ID: 5550091018

std::string usage(const char* y){
  std::string i = y;
  return "Usage: " + i + " [-h] [-f file_name]\n";
}
std::string help(const char* y){
  return usage(y) + "\nOptions:\n\t -h\tShow this text.\n\t -f\tLoad a game tree from a file\n";
} 
bool getEntry(){
  std::string line;
  std::cin >> line;
  char answer = tolower(line[0]);
  while(answer != 'y' && answer != 'n'){
    std::cout << "Please enter either Yes or No\n";
    std::cin >> line;
    answer = tolower(line[0]);
  }
  if(answer == 'y'){
    return true;
  }
    return false;
}
std::string getText(std::string prompt){
  std::string x;
  std::string y;
  std::cout << prompt;
  std::cin >> x;

  while(x.empty() == true){
    std::cout << prompt;
    std::cin >> x;
  }
  y = x.substr(0,x.find(" "));
  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  return y;
}
mesa::tree<std::string>* getOptions(int x , char** y){
  if(x == 1){
    return mesa::defaultTree();   
  }
  if(strcmp(y[1] , "-h") == 0){
      std::cout << help(y[0]);
      exit(0);
    }
  else if(strcmp(y[1] , "-f") == 0){
      std::ifstream inFile;
      inFile.open(y[2]);
      if(!inFile){
        std::cout << "File not found, starting default game.\n";
        return mesa::defaultTree();
      }
      mesa::tree<std::string>* tree = new mesa::tree<std::string>;
      mesa::fileTree(inFile, tree);  
      return tree;
    }
    return mesa::defaultTree(); 
}
void playGame(mesa::tree<std::string>* tree){  
  std::string response;
  bool x;

  while(tree->right != nullptr && tree->left != nullptr){
  
  std::cout << tree->value << std::endl;
  x = getEntry();

  if(x == false){
     tree = tree->left;
  }
  else if(x == true)
      tree = tree->right;
  }
  std::cout << "Is it " << tree->value << std::endl;
  x = getEntry(); 
  if(x == true){
    std::cout << "Computer wins!\n";
    return;
  }
  std::string newAnswer;
  std::string question;
  bool yesOrNo;
  std::cout << "OK, what was it?\n";
  std::cin.ignore();
  getline(std::cin,newAnswer);
  while(newAnswer.empty()){
    std::cout << "Please enter a non-empty input: ";
    getline(std::cin,newAnswer);
  }
  std::cout << "Give me a question that would distinguish a " << tree->value << " from " << newAnswer << std::endl;
  getline(std::cin,question);
  while(question.empty()){
    std::cout << "Please enter a non-empty input: ";
    getline(std::cin,question);
  }
  std::cout << "And would the answer to the question for a " << newAnswer << " be yes or no?\n";
  yesOrNo = getEntry();
  mesa::addNode(tree, newAnswer, question, yesOrNo);
}
