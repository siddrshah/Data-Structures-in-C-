/*******
*@file DoublyLinkedList.h delcaration of all the functions used 
for the playlist for music.
*
*@brief This file contains all the declaration of the functions
        to be used in doublylinked list.cpp
*
*@author Siddharth Shah
date :- 1/30/2015
*
*
*
*
*
*/
#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

//#include "playlist.h"
using std::string;

class DoublyLinkedList
  {
   public:
      DoublyLinkedList();
      ~DoublyLinkedList();
      void append(string &song);
      bool next();
      bool prev();
      bool find(string &song);
      bool empty();
      void insertBefore(string &song);
      void insertAfter(string &song);
      void remove(string &song);
      const string& getData();
	  void begin();
	  void end();

   private:
      class Node
        {
          
         public:
             Node* next;
             Node* prev;
             string* data;
			 Node();
			~Node();
         };
      Node* head;
      Node* tail;
      Node* current;
  };
#endif