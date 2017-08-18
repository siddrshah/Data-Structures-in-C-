/*******
*@file DoublyLinkedList.cpp Implementation of all the functions used 
 for the playlist for music.
*
*@brief This file contains all the fucntions required for the fuctioning
 of the playlist, string is taken input in some fucntions to use it 
  accordingly and give result. some fuctions are bool just to give True 
 or False as result.
*
*@author Siddharth Shah

*Date of completion :- 6/2/2015
*
*
*
*
*/
#include <iostream>
#include<string>

#include "doublylinkedlist.h"

using std::string;
using std::cin;
using std::cout;
using std::endl;

/***************************************************
@Fuction :- This is the constructor of the Class DoublyLinked List

            
*********************************************/
DoublyLinkedList::DoublyLinkedList()
{

	head= NULL;
	tail=NULL;
	current=NULL;
}

/***************************************************
@Fuction :- This is the destructor of the Class DoublyLinkedList


*****************************************/

DoublyLinkedList::~DoublyLinkedList()
{
	Node *temp= new Node;
	while (head!= NULL)
	{
		temp= head->next;
		delete head;
		head=temp;	
	}
}

/***************************************************
@Fuction :- This is the constructor of the Class Node
*************************************************/

DoublyLinkedList::Node::Node()
{
	next=NULL;
	prev=NULL;
	data=new string();
}
/***************************************************
@Fuction :- This is the destructor of the Class Node
************************************************/
DoublyLinkedList::Node::~Node()
{
	delete data;
}
/*********************************************************************
@function:- This function is used to add the particular
            song to the end of the doubly Linked list in the function.

input:- string &song
output:-NA

*********************************************************************/

void DoublyLinkedList:: append(string &song)
{
   Node *temp= new Node();
   *(temp->data) = song;
   temp->next=NULL;
   if (head == NULL)
   {
	   head=temp;
	   head->prev=NULL;
	   current=head;
	   tail=head;
	   
   
   }
   else
   {
	   Node *temp1 = new Node();
	   temp1=head;
	   while(temp1->next!= NULL)
       {
		   temp1= temp1->next;
       }

       temp1->next=temp;
       temp->prev = temp1;
       tail= temp;
       current= tail;

   }
}

/********************************************************************
@function:- This function is used to remove the particular song from 
            of the doubly Linked list in the function.

input:- string &song
output:-NA

*********************************************************************/

void DoublyLinkedList::remove(string &song)
{

	
	Node *temp= new Node;
	Node *temp1= new Node;
	Node *temp2= new Node;
	
	if (*(head->data)== song && *(tail->data)==song )
	{
		delete temp;
		head=NULL;
		tail=NULL;
		current=NULL;
	}

	else if (*(head->data) == song)
	{
		
		temp1=head->next;
		delete head;
		temp1->next=temp2;
		temp2->prev=temp1;
		temp1->prev=NULL;
		current = temp1;
		head= current;

	}
	else if (*(tail->data) == song)
	{
		temp1=tail->prev;
		delete tail;
		temp1->prev=temp2;
		temp2->next=temp1;
		temp1->next=NULL;
		current=temp1;
		tail=temp1;
	}
	


	else if (!empty())
	{
		
		temp=head;
		while (temp->next != NULL)
		{
			if (*(temp->data) == song)
			{
				temp2=temp->next;
		        temp1=temp->prev;
		        delete temp;
		        temp2->prev=temp1;
		        temp1->next=temp2;
		        current=temp2;
				break;
		        
	
	         }
			temp=temp->next;
		}
	}

}

/***************************************************************
@function:- This function is used to check the next node in the 
            DoublyLinked List

input:- NA
output:-True or false

****************************************************************/

bool DoublyLinkedList::next()
{
   if (current->next!= NULL)
   {
	   current=current->next;
       return true;
   }
   else
      {
      return false;
      }
}

/*******************************************************************
@function:- This function is used to check the previous node in the 
            DoublyLinked List

input:- NA
output:-True or false

********************************************************************/


bool DoublyLinkedList::prev()
{
   if (current->prev != NULL)
      {
      current=current->prev;
	  //getData();
      return true;
      }
   else
      {
      return false;
      }
}

/**********************************************************************
@function:- This function is used to whether the doubly linked list 
            is empty or not.

input:- NA
output:-True or false

*********************************************************************/

bool DoublyLinkedList::empty()
{
	if (current != NULL)
		return false;
	else
		return true;

}

/********************************************************************
@function:- This function is used to add a particular song after 
            the current song, in the doubly Linked list.

input:- string &song
output:-NA

*********************************************************************/


void DoublyLinkedList::insertAfter(string &song)
{
	Node *temp = new Node();
	Node *temp1 = new Node();
	Node *temp2= new Node();
	*(temp->data) = song;
	if (head== NULL)		// first null
	{
		current=temp;
		tail=temp;
		tail->next= NULL;
		head=temp;
		head->prev= NULL;
	
	}
	
	else if (head == tail)		// if head == current
	{
		temp->next=head->next;
		temp->prev=head;
		head->next=temp;
		current=temp;
		tail=current;
	
	}
	else if (head == current)
	{
		temp1=head->next;
		temp->next=head->next;
		temp->prev=head;
		head->next=temp;
		temp1->prev=temp;
		current=temp;
	
	}
	else if (current == tail)            // current== tail
	{
		
		tail->next=temp;
		temp->prev=tail;
		temp->next= NULL;
		current=temp;
		tail=current;
		
	}
	else if (!empty())			//in middle somewhere
	{
		temp2=current->next;
		temp2->prev= temp;
		temp->next=temp2;
		temp->prev=current;
		current->next=temp;
		current=temp;
	}
}

/*********************************************************************
@function:- This function is used to add a particular song before 
            the current song, in the doubly Linked list.

input:- string &song
output:-NA

*********************************************************************/


void DoublyLinkedList::insertBefore(string &song)
{
	Node *temp = new Node();
	Node *temp1=new Node();
	Node *temp2=new Node();
	*(temp->data) = song;
	if (head== NULL )
	{
		current=temp;
		tail=temp;
		tail->next= NULL;
		head=temp;
		head->prev= NULL;
	
	}

	else if (head== current && tail== current)
	{
		//temp=head;
		temp->prev=NULL;
		head->prev=temp;
		temp->next=head;
		//tail=head;
		current=temp;
		head=current;
	
	}
	else if (head == current )
	{
		temp->next=head;
		head->prev=temp;
		temp->prev=NULL;
		current=temp;
		head=temp;
	}
	else if (tail == current )
	{
		
		temp1=tail->prev;
		temp->next=tail;
		tail->prev= temp;
		temp->prev=temp1;
		temp1->next=temp;
		current=temp;
	}
	else if (!empty())
	{
		temp2=current->prev;
		temp2->next= temp;
		temp->prev=temp2;
		temp->next=current;
		current->prev=temp;
		//temp->next=temp1;
		current=temp;
	
	}
}

/********************************************************************
@function:- This function is used to find a particular 
            song in the doubly Linked list.

input:- string 
output:-True or false

*********************************************************************/

bool DoublyLinkedList::find(string &song)
{
	Node *temp = new Node();
	//*(temp->data) = song;

	if (*(head->data) == song )
	{
		current= head;
		return true;
	}
	else if (*(tail->data) == song)
	{
		current= tail;
		return true;
	
	}

	temp=head;
	while (temp->next != NULL)
	{
		
		if (*(temp->data)== song)
		{
			current=temp;
			return true;
		}
			
		else
		{
			temp=temp->next;
		}
		
	}
	return false;
}

const string& DoublyLinkedList::getData()
{
	return *(current->data) ;
}

/*********************************************************************
@function:- This function is used to point to the first song in 
             the doubly Linked list.

input:- NA
output:-NA

***********************************************************************/
void DoublyLinkedList::begin()
{
	if (!empty())
	{
	current = head;
	}
}
/*************************************************************************
@function:- This function is used to point to the last song in 
             the doubly Linked list.

input:- NA
output:-NA

************************************************************************/ 
void DoublyLinkedList::end()
{
	if (!empty())
	{
	current=tail;
	}

}
