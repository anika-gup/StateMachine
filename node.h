//// node.h
#ifndef NODE_H
#define NODE_H

#include <iostream>
using namespace std;

class node {
 public:
  node();
  ~node();

  void setNext(node* n);
  void setAccept(bool acceptState);
  void setLabel(char* mylabel);
  
  int getValue();
  node* getNext();
  bool getAccept();

  char* getLabel();

 private:
  int value;
  node* next;
  bool accept;
  char* label;
} ;
#endif //NODE_H
