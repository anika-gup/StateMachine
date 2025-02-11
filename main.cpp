#include <string.h>
#include <string>
#include <typeinfo>
#include <iostream>
#include "node.h"

using namespace std;

void ADDVERTEX(int count, int graph[20][20],  char** names, node* addNode);
void ADDEDGE(int count, int graph[20][20], char** names);

void PRINTLABELS(int count, char** names);
void PRINTGRAPH(int count, int graph[20][20], char** names);

int SEARCH(int count, char** names, char* Label);

void REMOVEVERTEX(int count, int graph[20][20], char** names);
void REMOVEEDGE(int count, int graph[20][20], char** names);

void enqueue(node* &qhead, node* &current);
void dequeue(node* &qhead);
void printQueue(node* qhead);

void findShortest(int count, int graph[20][20], char** names, node* &qhead);

void validLanguage(int count, int graph[20][20], char** names, int languageInput, char* startNodeLabel, int lenLeft, int countThroughInputLanguage);

void touchingEdges(int count, int graph[20][20], char** names,  int startEdgeIndex);
void printArray();
/*
Graph Creator
Anika Gupta
Create state machine and check if a language is valid.
 */

// beware i used a global variable... sincerest apologies.......
int touchingEdgesArray[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
// for (int ll=0; ll<20; ll++) {
//   touchingEdgesArray[ll] = 0;
//  }

bool isValid = false;

node* nodeGraph[20];
node* nullNode = NULL;
for (int m=0; m<20; m++) {
  nodeGraph[m] = nullnode;
}
int main() {
  int count = -1;

  //creating graph and setting all values to -1
  int graph[20][20];
  for (int c=0; c<20; c++) {
    for (int d=0; d<20; d++) {
      
      graph[c][d] = -1;
    }
  }
  // int touchingEdgesArray[20];
  // for (int ll=0; ll<20; ll++) {
  //   touchingEdgesArray[ll]=-1;
  // }

  // creating array with all of the vertex lables
  char** names = new char*[50];
  for (int a=0; a<20; a++) {
    char* text = new char[50];
    strcpy(text, "" ) ;
    names[a] = text ;
  }
  /*
  node* nodeGraph[20];
  node* nullnode = NULL;
  for (int m=0; m<20; m++) {
      nodeGraph[m] = nullnode;
    
  }
  */
  node* qhead = NULL;
  node* addNode = new node();
  int quit = 0;
  while (quit==0) {
    //giving user options
    cout << endl;
    cout << "What would you like to do? " << endl;
    cout << "QUIT  ADDVERTEX  ADDEDGE  REMOVEVERTEX  REMOVEEDGE \n PRINTLABELS  PRINTGRAPH  FINDSHORTEST  VALIDLANGUAGE" << endl;
    cout << "ENQUEUE" << endl;
    cout << endl;
    char input[50];
    cin >> input;
    if (strcmp(input, "ADDVERTEX")==0) {
      // create then call this funct
      count++;
      ADDVERTEX(count, graph, names, nodeGraph, addNode);
    }
    else if (strcmp(input, "VALIDLANGUAGE")==0) {
      cout << "What is the string that you want to check is a valid language or not? Only integers hehe :)" ;
      isValid = false;
      int languageInput;
      cin >> languageInput;
      cout << endl;
      cout << "What's the starting node's label?" << endl;
      char* startNodeLabel = new char[20];
      cin >> startNodeLabel;
      int lenLeft = to_string(languageInput).length() + 1;
      int countThroughInputLanguage = 0;
      validLanguage(count, graph, names, languageInput,  startNodeLabel, lenLeft, countThroughInputLanguage);
      
      
    }
    else if (strcmp(input, "ENQUEUE")==0) {
      int num;
      cout << "What num? : " ;
      cin >> num;
      node* n = new node();
      enqueue(qhead, n);
    }
    else if (strcmp(input, "QUIT")==0) {
      quit  =1;
    }
    else if (strcmp(input, "ADDEDGE")==0) {
      // create then call this funct
      ADDEDGE(count, graph, names);
    }
    else if (strcmp(input, "PRINTLABELS")==0) {
      PRINTLABELS(count, names);
    }
    else if (strcmp(input, "PRINTGRAPH")==0) {
      PRINTGRAPH(count, graph, names);
    }
    else if (strcmp(input, "REMOVEVERTEX")==0) {
      REMOVEVERTEX(count, graph, names);
    }
    else if (strcmp(input, "REMOVEEDGE")==0) {
      REMOVEEDGE(count, graph, names);
    }
    else if (strcmp(input, "FINDSHORTEST")==0) {
      // Find shortest path
      //STILL NEED TO CODE THIS----------------------------
      findShortest(count, graph, names, qhead);
    }
  }
  return 0;
}

void ADDVERTEX(int count, int graph[20][20], char** names, node* addNode) {
  // Adds a vertex (creates new label)

  
  cout << endl;
  cout << "What is the label for your vertex?" << endl;
  char* Label = new char[50];
  cin >> Label;
  names[count] = Label;
  cout << "added to label names blah" << endl;
  //node* addNode = new node();
  cout << "made new node..." << endl;
  cout << "is this an accept node?! yes or no" << endl;
  char* acceptYesNo = new char[10];
  cin >> acceptYesNo;
  if (strcmp(acceptYesNo, "yes")==0) {
    addNode->setAccept(true);
    cout << "set accept true." << endl;
  }
  else {
    addNode->setAccept(false);
    cout << "set accept false." << endl;
  }
  addNode->setLabel(Label);
  nodeGraph[count] = addNode;
  cout << "Label is: " << Label << endl;
}

void touchingEdges(int count, int graph[20][20], char** names,  int startEdgeIndex) {
  //startEdgeIndex is the index value that is the index of the thing we want to check
  // if we want to go from name with index value 1, we need to add values from column of index value to an array and then return it (make the return function later)/

  cout << "reached touching edges funct" << endl;
  //int touchingEdgesArray[20];
  for (int a=0; a<20; a++) {
    touchingEdgesArray[a] = graph[startEdgeIndex][a];
  }

  printArray();

}

void printArray() {
  for (int a=0; a<20; a++) {
    cout << touchingEdgesArray[a] << ", ";
  }
  cout << endl;
}


void ADDEDGE(int count, int graph[20][20], char** names) {
  //Adds an edge (weighted with direction).
  
  cout << "Adding an edge!" << endl;
  cout << "What is your starting node's label?" << endl;
  char s[50];
  cin>> s;
  int startingIndex = SEARCH(count, names, s);
  cout << "What is your ending node's label?" << endl;
  char e[50];
  cin >> e;
  int endingIndex = SEARCH(count, names, e);
  if ((endingIndex==-1) || (startingIndex==-1)) {
    // User's given nodes don't exist
    cout << "Either one or both of your names are invalid." << endl;
  }
  else {
    cout << "What is the weight of the edge?" << endl;
    int weight;
    cin >> weight;
    //Setting edge in graph:
    graph[startingIndex][endingIndex]=weight;
  }
}

void PRINTLABELS(int count, char** names) {
  //Prints all of the labels of the vertices in graph.
  cout << "Printing Labels." << endl;
  for (int a=0; a<count+1; a++) {
    if (strcmp(names[a], "")!=0) {
      cout << names[a] << endl;
    }
    //cout << names[a] << endl;
  }
  cout << endl;
}

void validLanguage(int count, int graph[20][20], char** names, int inputLanguage,  char* startNodeLabel, int lenLeft, int countThroughInputLanguage) {
  //cout << "the language I am checking validity for is: " ;
  //cout << inputLanguage << endl;
  //cout << "nice label..." << endl;
  int startNodeIndex = SEARCH(count, names, startNodeLabel);
  //cout << "just set start node index" << endl;
  if (startNodeIndex==-1) {
    cout << "sorry to break it to you bud. that node isn't in this graph.." << endl;
  }
  else {
    lenLeft = lenLeft - 1;
    if (lenLeft == 0) {
      node* cur = nodeGraph[startNodeIndex];
      if (cur->getAccept()==true) {
	cout << "cur: " << cur->getLabel() << endl;
	cout << "it is a valid language yay!" << endl;
	isValid = true;
      }
      return;
    }
    //int countThroughInputLanguage = 0;
    //int touchEdgesArray[20] =
    touchingEdges(count, graph, names,  startNodeIndex);
    cout << to_string(inputLanguage)[countThroughInputLanguage] << endl;
    //cout << typeid(touchingEdgesArray[0]).name()<< endl;
    //char* inputLanguageStr = new char[30];
    string inputLanguageStr = to_string(inputLanguage);
    //cout <<"input language str: " << inputLanguageStr << endl;
    char otherVal = inputLanguageStr.at(countThroughInputLanguage);
    
    int otherValInt = otherVal - '0';
    for (int a=0; a<20; a++) {
      //char val = char(touchingEdgesArray[a]);
      char val = static_cast<char>(touchingEdgesArray[a]); // THIS IS NOT BEING CONVERTED PROPERLY....
      int valInt = touchingEdgesArray[a];
      //cout << "valint: " << valInt << endl;
      //cout << touchingEdgesArray[a] << endl;
      //cout << "other valint: " << otherValInt << endl;
      //cout << "other val: " << otherVal << endl;
      //int comp = val.compare(otherVal);
      //cout << comp << endl;
      //if (comp==0) {
      if (touchingEdgesArray[a]==otherValInt) {
	  cout << "THEY EQUAL EACH OTHER..." << endl;
	  char* newStartNodeLabel = names[a];
	  countThroughInputLanguage += 1;
	  cout << "calling valid language again, this time on " << names[a] << " with countthroguhinputlanguage as: " << countThroughInputLanguage << endl;
	  validLanguage(count, graph, names, inputLanguage, nodeGraph, newStartNodeLabel, lenLeft, countThroughInputLanguage);
	  // we go to a.  have to recursively call something. idk. too lazy. so sad. AHH i'm done.
	  
      }
    }
  }
  
}

void PRINTGRAPH(int count, int graph[20][20], char** names) {
  //Prints the graph 
  for (int a=0; a<count+1; a++) {
    for (int b=0; b<count+1; b++) {
      if ( (strcmp(names[a], "")!=0) && (strcmp(names[b], "")!=0)) {
	cout << graph[a][b] << "  ";
      }
      //cout << graph[a][b] << "   ";
    }

    if (strcmp(names[a], "")!=0) {
      cout << endl;
    }
  }
}

int SEARCH(int count, char** names, char* Label) {
  //Searches for whether a certain label exists in the graph and if it does exist, returns index value where it exists on the graph
  if (strcmp(Label, "")==0) {
    // (means a deleted vertex)
    return -1;
  }
  for (int a=0; a<count+1; a++) {
    if (strcmp(names[a], Label)==0) {
      // found label in graph, returning index of it.
      return a;
    }
  }

  //vertex not found:
  return -1;
}

void REMOVEVERTEX(int count, int graph[20][20], char** names) {
  //Removes a vertex
  
  char toDelete[50];
  cout << "What is the label of the vertex to delete?" << endl;
  cin >> toDelete;
  int index = SEARCH(count, names, toDelete);
  if (index==-1) {
    cout << "That vertex doesn't exist." << endl;
  }
  else {
    char* newLabel = new char[50];
    strcpy(newLabel, "");
    names[index] = newLabel;
    for (int a=0; a<count+1; a++) {
      graph[a][index] = -1;
      graph[index][a] = -1;
    }
  }
}

void REMOVEEDGE(int count, int graph[20][20], char** names) {
  // Removes an edge
  cout << "What is the starting node's label?   " << endl;
  char s[50];
  cin >> s;
  int startingIndex = SEARCH(count, names, s);
  cout << "What is your ending ndoe's label?" << endl;
  char e[50];
  cin >> e;
  int endingIndex = SEARCH(count, names, e);
  if ((endingIndex==-1) || (startingIndex==-1)) {
    cout << "Either one or both of your names are invalid." << endl;
  }
  else {
    graph[startingIndex][endingIndex] = -1;
  }
}

void enqueue(node* &qhead, node* &current) {

  // priority queue
  
  node* ccurrent = current;
  if (qhead==NULL) {
    qhead = ccurrent;
    qhead->setNext(NULL);
  }
  else if (qhead->getNext()==NULL) {
    if (current->getValue() > qhead->getValue()) {
      qhead->setNext(current);
    }
    else {
      node* temp = qhead;
      qhead = current;
      qhead->setNext(temp);
      qhead->getNext()->setNext(NULL);
    }
  }
  else if (current->getValue() < qhead->getValue()) {
    node* temp = qhead;
    qhead = current;
    qhead->setNext(temp);
  }
  else {
    node* c = qhead;
    node* prev = qhead;
    while (c!=NULL && current->getValue() > c->getValue()) {
      cout << "while loop" << endl;
      prev = c;
      
      c = c->getNext();
    }
    cout << "out of wild loop" << endl;
    prev->setNext(current);
    current->setNext(c);
  }
  printQueue(qhead);
}
void dequeue(node* &qhead) {
  if (qhead==NULL) {
    return;
  }
  node* newh = qhead->getNext();
  qhead->~node();
  qhead = newh;
}

void printQueue(node* qhead) {
  while (qhead!= NULL) {
    cout << qhead->getValue() << " " ;
    qhead = qhead->getNext();
  }
}

void findShortest(int count, int graph[20][20], char** names, node* &qhead) {
  char* start = new char[50];
  char* end = new char[50];
  cout << "What is the starting label?" << endl;
  cin >> start;
  cout << "What is the ending label?" << endl;
  cin >> end;
  int startn = SEARCH(count, names, start);
  int endn = SEARCH(count, names, end);
  if (endn==-1 || startn==-1) {
    cout << "Either one or both of the vertices you listed don't exist." << endl;
  }
  else {
    // do the algorithm stuff.
    //enqueue whatever the starting value leads to?
    // REMINDER: DO THIS LATER IF TIME !!!!!!!!!!!!!!!!!!!!!!!!!!!!!
  }
}
