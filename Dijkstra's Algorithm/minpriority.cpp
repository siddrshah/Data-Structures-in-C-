/*************************************************
Description :- This is the minpriority.cpp file it 
				includes all functions declared in 
				the minpriority.h provided
Author :- Siddharth Shah
Date:- 4/30/2015

*******************************************/


#include "minpriority.h" 
#include <iostream>
#include <iomanip>

using std::cout;
using std::vector;
using std::string;

using namespace std;

/*********************************
Description:- Constructor
input :- NIL
output:-NIl
*********************************/
MinPriorityQ::MinPriorityQ()
{

}
/*********************************
Description:- Destructor
input :- NIL
output:-NIL
*********************************/

MinPriorityQ::~MinPriorityQ()
{}


/*********************************
Description:- This function is used to 
		insert the Element in the MIN Priority Queue  
input :- string data , int key
output:- NIL
*********************************/
			
void MinPriorityQ::insert(string data, int key)
{
	Element newElement;
	newElement.id = data;
	newElement.key= key;
	minHeap.push_back(newElement);
	/*for (int i=0; i<(int)minHeap.size(); i++ )
	{
		cout<<minHeap[i].id<<endl;
		cout<<minHeap[i].key<<endl;
	}*/
	decreaseKey(newElement.id,newElement.key);
}



/*********************************
Description:- This function is used to decrease the key of the
		string id.
input :- string id , int key
output:- NIL
*********************************/
void MinPriorityQ::decreaseKey(string id, int key)
{
	int  i;
	int j= (int) minHeap.size()-1;
	Element temp;
	for (i=0;i < (int)minHeap.size();i++)
	{
		if (minHeap[i].id == id && minHeap[i].key > key )
		{
			j=i;
			break;
		}
		
	}
	
	if (key > minHeap[j].key)
	{
		return;
	}

	minHeap[j].key= key;
	while (j > 0 && minHeap[parent(j)].key > minHeap[j].key)
	{
		temp = minHeap[j];
		minHeap[j] =minHeap[parent(j)];
		minHeap[parent(j)] = temp;
		j = parent (j);

	}
}
/*********************************
Description:- This Function is used to build a minimum Heap
input :- NIL
output:- NIL
*********************************/
void MinPriorityQ::buildMinHeap()
{
	
	int i;
	int heapSize = (int)minHeap.size();
	for (i= heapSize/2;i != 1;i-- )
	{
		minHeapify(i);
	}
	
}
/*********************************
Description:- This function is used to sort the heap 
		according to the minimum value
input :- int i
output:- NIL
*********************************/
void MinPriorityQ::minHeapify(int i)
{
	int smallest;
	Element temp;
	int l = left(i);
	int r = right(i);
	int heapSize = (int)minHeap.size();
	if (l < heapSize && minHeap[l].key < minHeap[i].key)
	{
		smallest = l;
	}
	else 
		smallest = i;
	if (r < heapSize && minHeap[r].key < minHeap[smallest].key)
	{
		smallest = r;
	}
	if (smallest != i)
	{
		temp=minHeap[i];
		minHeap[i]=minHeap[smallest];
		minHeap[smallest] = temp;
		minHeapify(smallest);
	}
}

/*********************************
Description:- used to find parent 
input :- int i
 output:- i/2
*********************************/

int MinPriorityQ::parent(int i)
{
	return (i/2);
}

/*********************************
Description:- used to calculate the left node
input :- int i 
output:- 2*i
*********************************/
int MinPriorityQ::left(int i)
{
	return (2*i);
}

/*********************************
Description:- used to calculate the right node
input :- int i
output:-2 *i+1
*********************************/
int MinPriorityQ::right(int i)
{
	return (2*i+1);
}

/*********************************
Description:- used to extract the Minimum value from the Heap
input :- NIL
output:- string
*********************************/
string MinPriorityQ::extractMin()
{
	int heapSize = (int)minHeap.size();
	string a="empty";
	if ( heapSize < 1)
	{
		return a;
	}
	Element min = minHeap[0];
	minHeap[0] = minHeap[heapSize-1];
	minHeap.pop_back();
	//heapSize = heapSize- 1;
	minHeapify(0);
	return min.id;
}


/*********************************
Description:- Used to check whether the string
	is a member of the heap or not
input :- string id
output:- true or false
*********************************/
bool MinPriorityQ::isMember(string id)
{
	int i;
	for (i=0; i< (int)minHeap.size();i++)
	{
		if (minHeap[i].id == id)
		{
			return true;
			break;
		}
	}
	return false;
}

bool MinPriorityQ::isEmpty()
{
	if (minHeap.empty())
	{
		return true;
	}
	return false;
}
