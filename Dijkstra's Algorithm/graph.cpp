#include"graph.h"
#include<iostream>
#include<vector>
#include<string>
#include<map>


using namespace std;

/*****************************************

Description:- Constructor
input:- nil
output:-nil

****************************************/

Graph::Graph()
{

}

/*****************************************

Description:- destructor
input:- nil
output:- nil

****************************************/
Graph:: ~Graph()
{

}

/*****************************************

Description:- constructor
input:-nil
output:-nil

****************************************/
Graph::Vertex::Vertex()
{
	//Null= new Vertex();
	
}

/*****************************************

Description:- constructor
input:-nil
output:-nil

****************************************/

Graph::Neighbor::Neighbor()
{
	//name = "";
	//weight = 0;
}

/*****************************************

Description:- Destrutor
input:-
output:-

****************************************/

Graph::Vertex::~Vertex()
{

}

/*****************************************

Description:- Destructor
input:-
output:-

****************************************/
Graph::Neighbor::~Neighbor()
{

}

/*****************************************

Description:- This function is used to add a vertex in the node
input:- string data
output:- nil

****************************************/


void Graph::addVertex(string data)
{
	//vertices.insert(std::pai(string , ));
	//string s;
	Vertex v;
	v.pi = "";
	v.key = 0;
	//v.pi = data;
	vertices.insert(std::pair<string, Vertex>(data ,v));

	
	
}
/*****************************************

Description:- this function is used to add edge in the graph between two vertices
input:- string fr, string t, int w
output:- nil

****************************************/

void Graph::addEdge(string fr,string t, int w )
{
	string from;
	string f;
	from = fr;
	vector<Neighbor> neighborVertex;
	std::map<string,vector<Neighbor>>::iterator it ;
	Neighbor nb;
	nb.name = t;
	nb.weight = w;
	int a= 0;

	string found;
	if (adjList.empty())
	{
		neighborVertex.push_back(nb);
		adjList.insert(std::pair<string,vector<Neighbor>>(fr,neighborVertex));
	}
	else{

	// adjList.find(fr)->first;
	for (it = adjList.begin();it !=adjList.end();++it)
	{
		f = it->first;
		if (f == fr)
		{
			it->second.push_back(nb);
			a= 1;
		}
		
		
	}
	if (a==0)
		{
			
			neighborVertex.push_back(nb);
			adjList.insert(std::pair<string,vector<Neighbor>>(fr,neighborVertex));
			//cout<<"insert 1"<<endl;
		
		}
	}

	
}

/*****************************************

Description:- this function is usd to build a shortest path tree
input:- string source
output:- nil

****************************************/

void Graph::buildSSPTree(string source)
{
	string extract;
	Initializesinglesource(source);
	source = "";
	std::map<string,Vertex>::iterator it ;
	for (it = vertices.begin(); it != vertices.end();++it)
	{
		minQ.insert(it->first,it->second.key);
		//for (std::vector<Vertex>::iterator itvertex = it->first.begin();)

	}
	//insertionSort();//insertion sort
	//minQ.buildMinHeap();
	while (!minQ.isEmpty())
	{
		extract = minQ.extractMin();

		for (std::map<string,vector<Neighbor>>::iterator itmap = adjList.begin();
			itmap != adjList.end(); ++itmap)
		{
			if (itmap->first == extract)
				for (std::vector<Neighbor>::iterator itNeighbor = itmap->second.begin();
					itNeighbor != itmap->second.end();++itNeighbor)
				{
					relax(extract, (*itNeighbor).name,(*itNeighbor).weight);
				}
		}

	}
}
/*****************************************

Description:-  this function is used to get the shortest path between two vertices
input:- string from, string to 
output:- string

****************************************/

string Graph::getShortestPath(string from , string to)
{
	
	buildSSPTree(from);
	string check, parent;
	std::vector<string> parentVec;
	int last_key;
	//int i;

	std::map<string,Vertex>::iterator it;
	/*for (it = vertices.begin();it != vertices.end(); ++it)
	{
		if (from == it->first)
		{
			cout<<it->second.key<<endl;
		}
		if (to == it->first)
		{
			cout<<it->second.key<<endl;
		}
	}*/

	
	//for (it = vertices.begin();it != vertices.end(); ++it)
	//{
		it = vertices.find(to);
		last_key=it->second.key;
		parentVec.push_back(to);
		while (it->second.pi != "")
		{
			check = it->second.pi;
			parentVec.push_back(check); 
			it = vertices.find(check);
		}
		parent = it->second.pi;

	//}

		for (int i= (int)(parentVec.size()-1); i >= 0;i--)
	{
		
		cout<<parentVec[i];
		if (i > 0)
		{
			cout<<"->";
		}

	}
		cout<<" with length "<<last_key<<endl;
	

	//for (it= vertices.begin(); it != vertices.end();++it )

	
	return to;
}
/*****************************************

Description:- This function is used to sort the vertices in their increasing order
input:- nil
output:-nil

****************************************/
void Graph::insertionSort()
{
	int j;
	string keystr;
	vector<Neighbor> sort;
	Neighbor key;	
	
	//Record* key;
	std::map<string,vector<Neighbor>>::iterator it;
	//std::vector<Neighbor>::iterator itvn;
		
	for (it = adjList.begin();it != adjList.end();++it)
	{

		for(j = 1;j<=(int)sort.size()-1;j++)
		{
			//key = data.at(j);
			//keystr = (*itvn).name;
			key = sort[j];
			int i= j-1;
			while (i>=0 && sort[i].name > key.name)
			{
				sort[i+1]= sort[i];
				i=i-1;
			}
			sort[i+1] = key;
		}
	}

}



/*****************************************

Description:- This function is used to initialize the key and 
parent of all the vertices to zero and null
input:- string data
output:-

****************************************/

void Graph::Initializesinglesource(string data)
{
	std::map<string,Vertex>::iterator it ;
	for (it =vertices.begin();it != vertices.end();++it)
	{
		string start = it->first;
		//Vertex end = it->second;
		it->second.key = 999;
		it->second.pi = "";
	}
	for (it = vertices.begin(); it != vertices.end();++it)
	{
		if (it->first == data)
		{
			it->second.key = 0;
		}
	}
}


/*****************************************

Description:- this function is used to assign the parent and key to the vertices
input:- from , to , weight
output:-  nil

****************************************/
void Graph::relax(string from , string to , int weight)
{
	
	
	if (vertices[to].key > vertices[from].key + weight)
			{
				vertices[to].key = vertices[from].key + weight;
				vertices[to].pi = from;
				minQ.decreaseKey(to,vertices[to].key);
			}
			
}