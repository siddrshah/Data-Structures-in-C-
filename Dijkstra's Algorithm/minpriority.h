/*************************************************
Description :- This is the minpriority.h file it includes all 
				functions declared in the UML provided
Author :- Siddharth Shah
Date:- 4/30/2015

*******************************************/
#include <string>
#include <vector>
//#include"SSPapp.h"
//#include"Graph.h"

using std::string;
using std::vector;


class MinPriorityQ
{

public:
    
    //MinPriorityQ();
    ~MinPriorityQ();
    MinPriorityQ();
    void insert(string id, int key);
    void decreaseKey(string id, int key);
    string extractMin();
    bool isMember(string id);
	bool isEmpty();
	

private:

    class Element
    {
        public:
            string id;
            int key;
    };
    
	//void insertMinHeap(int key);
	//void heapDecreasekey(int i, int key);
	void buildMinHeap();
    void minHeapify(int i);
    int parent (int i);
    int left(int l);
    int right(int r);
    vector <Element> minHeap;
	
};
