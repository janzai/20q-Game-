#include "tree.h"
#include <string>
#include <fstream>
#include <algorithm>

// Name: Jamie Anzai
// Student ID: 5550091018

mesa::tree<std::string>* mesa::defaultTree(){
  auto left_child = mesa::make_tree<std::string>("spam");
  auto right_child = mesa::make_tree<std::string>("programmer");
  mesa::tree<std::string>* tree = mesa::make_tree<std::string>("Is it bigger than a breadbox?", left_child,right_child);
  return tree;
}
void mesa::fileTree(std::ifstream& file, mesa::tree<std::string>* tree)
{
  std::string line;
    if(getline(file, line)){
          tree->value = line.substr(2,line.size());
          if(line[0] == 'Q'){
            tree->left = new mesa::tree<std::string>;
            mesa::fileTree(file, tree->left);
            tree->right = new mesa::tree<std::string>;
            mesa::fileTree(file, tree->right); 
          }
    }
}
void mesa::saveTree(std::ofstream& file, mesa::tree<std::string>* tree){
  if(tree->left == nullptr && tree->right == nullptr){
    file << "A:" << tree->value << std::endl;
    return;
} 
  file << "Q:" << tree->value << std::endl;  
  mesa::saveTree(file , tree->left);
  mesa::saveTree(file , tree->right);
}
void mesa::addNode(mesa::tree<std::string>* tree , std::string newAnswer , std::string question , bool yesOrNo){
  tree->left = new mesa::tree<std::string>;
  tree->right = new mesa::tree<std::string>;
  auto currentValue = tree->value;
  tree->value = question;
  mesa::tree<std::string>* tmp = tree->left;
  tree = tree->right;
  if(yesOrNo){
      tmp->value = currentValue;
      tree->value = newAnswer; 
  }
  else {
    tmp->value = newAnswer;
    tree->value = currentValue;
  }
}
void mesa::freeTree(mesa::tree<std::string> *tree){
  if(tree==nullptr){
    return;
  }
  mesa::freeTree(tree->right);
  mesa::freeTree(tree->left);
  delete tree; 
}

