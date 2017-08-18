/*************************************************
Description :- This is the sspapp.h file it 
				includes all functions required for the graph.cpp
Author :- Siddharth Shah
Date:- 5/10/2015

*******************************************/
#include<string>
#include<vector>
#include<iomanip>
#include"graph.h"
//#include"minpriority.h"

class SSPapp
{
 public:
 // int main();
  void readGraph();
  void processQuries();
 private:
  Graph myGraph;

};
