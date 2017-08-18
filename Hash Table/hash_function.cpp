/* This assignment originated at UC Riverside.*/

/************************************************************
Author :- Siddharth Shah
Description:-This fucntion has been found after doing quite a lot of 
			work on the internet.
Websites used :- http://algs4.cs.princeton.edu/34hash/
			http://www.cs.princeton.edu/~rs/AlgsDS07/10Hashing.pdf
			- Have also referred
			http://www.youtube.com/watch?v=y_xnyjs9gcc
			for the creation of Hash tables assignment 
			RS stands for Robert Sedgwicks 
			It performs better with the string functions


***************************************************/
 
#include <string>
#include "hash.h"

using std::string;



int 
Hash::hf ( string str ) {
  
  // place your hash function here....
	//return ( (int) ins[0] ) % HASH_TABLE_SIZE;
	unsigned int x = 6544164;
	unsigned int y = 12353;
	unsigned int hash = 0;
	
	for (unsigned int i=0; i < str.length(); i++)
	{
		hash = hash * x +str[i];
		x = x *y;	
	}
	hash = hash % HASH_TABLE_SIZE;
	return hash;

}

