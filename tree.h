#ifndef MESA_PROJECT2_TREE_H
#define MESA_PROJECT2_TREE_H

// 
// Tree manipulation functions
//

#include <iostream>
#include <string>
#include <fstream>

// Name: Jamie Anzai
// Student ID: 5550091018

namespace mesa {
  // a recursive binary tree
  template<class T>
    struct tree {
      T value;
      tree<T>* left = nullptr;
      tree<T>* right = nullptr;
    };
  template<class T>
    tree<T>* make_tree(T value)
    {
      tree<T>* newTree = new tree<T>;
      newTree->value = value;
      return newTree;
    }
  template<class T>
    tree<T>* make_tree(T value, tree<T>* left, tree<T>* right)
    {
      tree<T>* newTree = new tree<T>;
      newTree->value = value;
      newTree->left = left;
      newTree->right = right;
      return newTree;
    }
  // Makes tree with default values and kids 
  mesa::tree<std::string>* defaultTree();
  // Makes a tree from a file 
  void fileTree(std::ifstream& , mesa::tree<std::string>*);
  // Saves a tree to a text file 
  void saveTree(std::ofstream& , mesa::tree<std::string>*);
  // Adds a new child to the tree
  void addNode(mesa::tree<std::string>* , std::string , std::string , bool);
  void freeTree(mesa::tree<std::string> *tree);
} // end namespace mesa

#endif

