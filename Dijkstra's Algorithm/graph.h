/*************************************************
Description :- This is the graph.h file it 
				includes all functions required for the graph.cpp
Author :- Siddharth Shah
Date:- 5/10/2015

*******************************************/

#include<string>
#include <vector>
#include<map>

//#include"SSPapp.h"
#include"minpriority.h"



class Graph
{
public:
  void addVertex(string name );
  void addEdge(string from, string to, int weight);
  string getShortestPath(string from, string to);
  Graph();
  ~Graph();




 private:


  class Vertex
  {
  public:
    string pi;
    int key;
	Vertex();
	~Vertex();
    
  };

  class Neighbor
  {
  public:
    string name;
    int weight ;
	Neighbor();
	~Neighbor();
  };


  std::map<string, Vertex> vertices;
  std::map<string, vector<Neighbor>> adjList;
  string currentSource;
  MinPriorityQ minQ;
  void buildSSPTree(string source);
  void relax(string u, string v,int weight);
  vector <Neighbor> neighborVector;
  string Ver;
  void Initializesinglesource(string from);
  void insertionSort();
  //bool isEmpty();
  

  //Vertex();

};
