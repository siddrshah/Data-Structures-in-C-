/**
 * @file playlist.cpp   Implementation of a Playlist for music.
 * 
 * @brief
 *    Implementation of a Playlist for music. A doubly linked list is
 *    used to store the song names.
 *
 * @author Judy Challinger
 * @date 2/1/13
 */

#include <iostream>
#include <string>

#include "playlist.h"
#include "doublylinkedlist.h"

using std::string;
using std::cin;
using std::cout;
using std::endl;

/**
 * Process a playlist command.
 *
 * Gets an entire line from std::cin, extracts the first word as the command,
 * and calls the appropriate processing function. Invalid commands are
 * ignored.
 */
void Playlist::processCommand() 
{
   string str1,firstWord,space,song;
   string command1="appendSong";
   string command2="removeSong"; 
   string command3="playCurrent";
   string command4="playReverse";
   string command5="insertBefore";
   string command6="playForward";
   string command7="insertAfter";
   string command8="gotoSong";
   string command9="gotoFirstSong";
   string command10="gotoLastSong";
   string command11="nextSong";
   string command12="prevSong";

   int size,j;
   firstWord.clear();
   space.clear();
   song.clear();
   
   getline(cin,str1);
   size=str1.length();
   space=' ';
   int i=0;

   for (i=0;i<size;i++)
   {
	   if (str1[i]!=' ')
       {
		   firstWord=firstWord+str1[i];
       }
       else
       {
		   break; 
       }
   }
   for(j=i+1;j<size;j++)
   {
	   song=song+str1[j];
   }
   if (firstWord.compare(command1) ==0)
   {
	   dll.append(song);
   }
   else if(firstWord.compare(command2)==0)
   {
	   if (!dll.empty())
	   {
		   dll.remove(song);
	   }
   }
   else if(firstWord.compare(command3)==0)
   {
	   if (!dll.empty())
	   {
		   cout<<endl<<"playing current: "<<dll.getData()<<endl; 
	   }
	   else
		   cout<<endl<<"playing current: ";
   }
   else if(firstWord.compare(command4)==0)
   {
	   cout<<endl<<"playing reverse: "<<endl;
	   cout<<dll.getData()<<endl;
	   while (dll.prev())
	   {
		   cout<<dll.getData()<<endl;
		   
	   }
		  
    }
   else if(firstWord.compare(command5)==0)
   {
      dll.insertBefore(song);
	  dll.getData();
   }
   else if(firstWord.compare(command6)==0)
   {
	   cout<<endl<<"playing forward: "<<endl;
	   cout<<dll.getData()<<endl;
	   while (dll.next())
	   {
		   cout<<dll.getData()<<endl;
			  	  
	   }
   }
   else if(firstWord.compare(command7)==0)
   {
	   dll.insertAfter(song);
	   dll.getData();
   }
   else if(firstWord.compare(command8)==0)
   {
	   if (!dll.empty())
	   {
		  dll.find(song);
	      dll.getData(); 
	   }
	   
   }
   else if(firstWord.compare(command9)==0)
   {
	   dll.begin();      
   }
   else if(firstWord.compare(command10)==0)
   {
	   dll.end();      
   }
   else if(firstWord.compare(command11)==0)
   {
	   if (!dll.empty())
	   {
		   dll.next();
	   }
   }
   else if(firstWord.compare(command12)==0)
   {
	   if (!dll.empty())
	   {
		   dll.prev();
	   }
   }
      
}

/**
 * The Playlist main loop will process command lines until eof.
 */  
void Playlist::mainLoop() {
   while (!cin.eof()) processCommand();      // process all commands
}

/**
 * The main entry point for the program.
 */
int main()
{
   Playlist myPlaylist;
   myPlaylist.mainLoop();
   return 0;
}
