//node.cpp
#include "node.h"
#include <iostream>
#include <cstring>

using namespace std;

node::node() {
  value = 0;
  label = new char[20];
  strcpy(label, " ");
  next = NULL;
  accept = false;
}
node::~node() {
  // i still have no idea what this does YAY !
}
void node::setNext(node* n) {
  next = n;
}
int node::getValue() {
  return value;
}
node* node::getNext() {
  return next;
}

void node::setAccept(bool acceptState) {
  accept = acceptState;
}

bool node::getAccept() {
  return accept;
}

void node::setLabel(char* mylabel) {
  strcpy(label, mylabel);
  //label = mylabel;
}

char* node::getLabel() {
  return label;
}
