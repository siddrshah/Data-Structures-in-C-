/***************************************************
Author :- Siddharth Shah
Date :- 3/26/2015
Description:- In this file functions are provided to process 
		the inputfile, search ,remove and print words in the HASh
		table and some functions also calculate the required 
		statistics 
**********************************/

#include"hash.h"
#include<fstream>
#include<string>
#include<iostream>

using namespace std;

/*******
Description:- This is the constructor of the Hash. 
			  Here all the values are intialized 
input :- NA
output:- NA

***/

Hash::Hash()
{
	longestList=0;
	avgLength=0;
	collisions=0;
	currentAvgListlen = 0;
		
}

/*******
Description:-This fuction helps to process the inputfile.
input :- filename 
output:- NA

***/

void Hash::processFile (string filename)
{
	string x;
	int index;	
	ifstream inputfile(filename);
		
	while (getline(inputfile,x))
	{
		index=hf(x);
		if (hashTable[index].empty() == 0)
		{
			collisions++;
		}
		hashTable[index].push_back(x);
		averageLength();
		longestList= longList();
	}
	
}

/*******
Description:- This function is used to search the Word in the Hash Table.
input :- string
output:- True or false

***/

bool Hash::search(string word)
{
	//Hash h;
	int index = hf(word);
	for (std::list<string>::iterator it=
		hashTable[index].begin(); it != hashTable [index].end();
		++it)
	{
		if (*it==word)
			return true;
	}
	return false;
	
}


/*******
Description:- This function is used to print the Hash Table 
			in the required format 
input :- NA
output:-NA

***/
void Hash::print()
{
	int i;
	for (i=0;i< HASH_TABLE_SIZE;i++)
	{
		cout<<i<<":\t";
		for (std::list<string>::iterator it = hashTable[i].begin();
			it != hashTable[i].end(); ++it)
		{
			cout<<*it<<", ";
		}
		cout<<endl;
	}
}

/*******
Description:- This fucntion is used to find the word first
			and then remove it.
input :- string
output:- NA

***/

void Hash::remove(string word)
{
	int index= hf(word);
	if (search(word))
	{
		hashTable[index].remove(word);
		averageLength();
	}
	
}

/*******
Description:- This function is used to calculate one of the 
			statistics of the Hash Table called LOngest List
input :- NA
output:- longestlist

***/

unsigned int Hash::longList()
{
	
	for (int i=0;i<HASH_TABLE_SIZE;i++)
	{
		if(hashTable[i].size() > longestList)
		{
			longestList= hashTable[i].size();
		}		
	}
	return longestList;
}

/*******
Description:-This function is used to calculate one of the 
			statistics of the Hash Table called averageLength
input :- NA
output:- avgLength

***/

double Hash::averageLength()
{
	items=0.0;
	count=0.0;
	for (int i =0; i< HASH_TABLE_SIZE; i++)
	{
		if (!hashTable[i].empty())
		{
			count++;
		}
		for (std::list<string>:: iterator it = 
			hashTable[i].begin(); it !=hashTable[i].end();++it)
		{
			items++;
			
	    }
	}

	currentAvgListlen = items /count ;
	avgLength = (avgLength + currentAvgListlen)/2.0;
	return avgLength;
}

/*******
Description:- Thsi function is used to print the statistics.
input :- NA
output:-NA

***/

void Hash::printStats()
{
	cout<<"Total Collisions = "<< collisions <<endl;
	cout<<"Longest List Ever = "<< longestList <<endl;
	cout<<"Average List Length Over Time = "<< avgLength <<endl;
	loadFactor();
	cout<<"Load Factor = "<<lf<<endl;

}

/*******
Description:- This function is used to generate an output file 
	and later print the HAsh Table into it the required format
input :- filename
output:- NA

***/

void Hash::output(string)
{
	ofstream output("output.txt");
	if (output.is_open())
	{
		//output<<"text";
		for (int i=0; i < HASH_TABLE_SIZE;i++)
	    {
			
			output<< i<< ":\t";
			for (std::list<string>::iterator it = hashTable[i].begin();
			it != hashTable[i].end();++it)
			{
				output<< *it<<", ";
			}

			output<<endl;
		
		}
		output.close();
	}
	
}

/*******
Description:-This function is used to calculate one of the 
			statistics of the Hash Table called Load FActor
input :- NA
output:- lf

***/

double Hash::loadFactor()
{
	items=0.0;
	
	for (int i =0; i< HASH_TABLE_SIZE; i++)
	{
		for (std::list<string>:: iterator it = 
			hashTable[i].begin(); it !=hashTable[i].end();++it)
		{
			items++;
			
	    }
	}

	lf= items/ HASH_TABLE_SIZE;

	return lf;
}

/************** end***************/