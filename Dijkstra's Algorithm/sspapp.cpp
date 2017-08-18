/*************************************************
Description :- This is the sspapp.cpp file it 
				includes all functions declared in the 
				sspapp.h
Author :- Siddharth Shah
Date:- 5/8/2015

*******************************************/

#include"sspapp.h"
#include<iostream>
#include<vector>
#include<string>


using namespace std;



/*class mainSSPapp
{
public:
	//void mainLoop();

private:
	MinPriorityQ myMinPriorQ;
	void processCommand();
	void processAddVertex(string);
	void processPrint();
	void processAddEdge(string);
    void processQuit();

};*/
SSPapp sspApp;
//mainSSPapp sspapp;

/*****************************************

Description:- This is the main function
input:- nil
output:- return 0

****************************************/


int main()
{
	//while (!cin.eof())
	//{
	sspApp.readGraph();	
	sspApp.processQuries();
		
	//}
	return 0;
}

/*****************************************

Description:-  this function is used to take the inputput from the user
input:-
output:-

****************************************/


void SSPapp::readGraph()
{
	
	string s1, vertex, numVertex , numEdge , edge, from,to;
	string space ;
	space = ' ' ;
	edge = "";
	
	//int i,j,k,l,a,b, weight;
	 int a, weight;
	//getline(cin,s1);
	//int stoint = std::stoi(s1);

	/*for (i=0;i<s1.length();i++)
	{
		if(s1[0] != '\n')
		{
			numVertex= numVertex + s1[0];
		}
	}*/
	cin>>numVertex;

	/*for ( j=i+1; j< s1.length();j++)
	{	
		vertex = vertex +  s1[j];
	}*/
	//int numV =std::stoi(numVertex);
	cin.ignore();
	getline(cin,vertex);

	for (a=0; a < (int)vertex.length();a++)
	{
		if (vertex[a] != ' ')
		{
			edge = edge + vertex[a];
			
		}
		if (vertex[a] ==' ')
		{
			myGraph.addVertex(edge);
			edge.clear();
		}
		if (a ==(int) (vertex.length()-1))
			myGraph.addVertex(edge);
	}
	//cin.ignore();
	/*for (k=j+1; k<s1.length(); k++)
	{
		if(s1[0] != '\n')
		{
			numEdge = s1[k];
		}
	}*/

	cin>>numEdge;
	int numE = std::stoi(numEdge);
	//cout<<numE<<endl;
	cin.ignore();
	
	while (numE > 0 )
	{
		getline(cin,s1);
		int pos = s1.find(' ');
		//cout<<pos<<endl;
		from= s1.substr(0,pos);
		s1.erase(0,pos+1);
		//cout<<from<<endl;
		int pos1 = s1.find(' ');
		to = s1.substr(0,pos1);
		s1.erase(0,pos1+1);
		//cout<<to<<endl;
		int pos2 = s1.find(' ');
		weight = std::stoi(s1.substr(0,pos2-1));
		//cout<<weight <<endl;
		myGraph.addEdge(from,to,weight);
		//cin.ignore();
		numE--;
		//cout<<numE<<endl;
	}

	/*for (l= k+1; l < s1.length(); l++)
	{
		edge = edge + s1[l];

	}

	int numV =std::stoi(numVertex);

	for (a=0; a <numV;a++)
	{
		if (vertex[a] != ' ' );
		{
			myGraph.addVertex(vertex);
		}
		if(vertex[a] == '\n')
			break;
		else
			break;
	}

	int numE = std::stoi(numEdge);

	for (b=0;b<edge.length();b++)
	{
		if (edge[b] != ' ')
		{
			from = edge[b];
			to = edge[b+2];
			weight = edge[b+4];

			myGraph.addEdge(from, to , weight);
			
		}
		break;
		
	}*/


	//sspapp.processAddVertex(vertex);

	
	//myGraph.addVertex(vertex);
	//myGraph.addEdge();
	processQuries();

}

/*****************************************

Description:- 
input:-
output:-

****************************************/

void SSPapp::processQuries()
{
	int a, b;
	
	string out;
	while (!cin.eof())
	{
		string to;
		string from;
		string process;
		getline(cin,process);
		if(process!="")
		{
		for (a=0; a <(int) process.length();a++)
		{
			if (process[a] != ' ')
			{
				from = from + process[a];
				//cout<<"edge = "<<edge<<endl;
			}
			else
				break;
		}
		for (b= a+1; b < (int)process.length();b++)
		{
			to = to + process[b];
		}

		string out = myGraph.getShortestPath(from , to);
		}
	}

	
}



/*void mainSSPapp::processAddVertex(string vertex)
{
	int i;
	string space;
	space = ' ';
	
	for (i=0; i <vertex.length();i++)
	{
		if (vertex[i] == ' ' );
		{

		}
	}
}*/