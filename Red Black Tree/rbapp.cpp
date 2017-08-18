/**********************************************************
Author:-Siddharth Shah
Date :-4/17/2015  
File :- This contains functions for processing the data for the 
		functions in rbTree.cpp

****************************************************/

#include <iostream>
#include "rbapp.h"
#include "rbtree.h"

using std::vector;
using namespace std;


RBapp r;
/************************************
Description:- this is the main of the program
input:- NA
output:-returns 0;


**********************************/

int main ()
{
	RBapp myRBTapp;
	myRBTapp.mainLoop();
	return 0;
}
/************************************
Description:- This function is used to process the 
				given file
input:- NA
output:-NA


**********************************/

void RBapp::mainLoop()
{
	while (!cin.eof()&& !done)
	{
		processCommand();
	}
}


/************************************
Description:- This function is used to process the 
				input file into command and data
input:- NA
output:-NA


**********************************/

void RBapp::processCommand()
{
	string str1, command, space, data, key, satelliteData ;
	string command1="insert";
	string command2="print";
	string command3="find";
	string command4="delete";
	string command5="quit";


	int size,j;
	command.clear();
	//key.clear();
	//satelliteData.clear();
	space.clear();


	getline(cin,str1);
	size=str1.length();
	space=' ';
	int i=0;
	for (i=0; i< size; i++)
	{
		if (str1[i]!= ' ')
		{
			command = command +str1[i];
		}
		else
		{
			break;
		}
	}
	for (j=i+1;j<size;j++)
	{
		data = data+ str1[j];
	}
	/******/
	//cout<<data;
	if (command.compare(command1) == 0)
	{
		r.processInsert(data);
	}
	else if(command.compare(command2) == 0)
	{
		r.processPrint();
	}
	else if(command.compare(command3) == 0)
	{
		r.processFind(data);
	}
	else if(command.compare(command4) == 0)
	{
		r.processDelete(data);
	}
	else if(command.compare(command5) == 0)
	{
		r.processQuit();
	}
}
/**************************************************
Description:-his function is used to process the 
			data for the rbInsert function 
input:- string data
output:- NA

***************************/

void RBapp::processInsert(string& data)
{
	string key, satelliteData;
	key.clear();
	satelliteData.clear();
	int i,j;

	for (i=0;i< (int)data.length(); i++)
	{
		if (data[i]!=' ')
		{
			key= key+ data[i];
		}
		else
		{
			break;
		}
	}
	
	for (j=i+1; j<(int)data.length() ;j++)
	{
		satelliteData = satelliteData + data[j];
	}
	//cout<<satelliteData<<endl;
	myRBT.rbInsert(key,satelliteData);
}

/**************************************************
Description:- this Function is used to process 
				the data for the print Function
input:-NA
output:-NA

***************************/

void RBapp::processPrint()
{
	myRBT.rbPrintTree();
}
/**************************************************
Description:- this function is used to process the 
			data for the find function 
input:- string z
output:-na

***************************/
void RBapp::processFind(string& z)
{
	std::vector<const string*> rbSearch;
	//cout<<z<<endl;
	rbSearch = myRBT.rbFind(z);

	for (int i=0;i< (int)rbSearch.size();i++)
	{
		
		cout<<z<<' ';
		cout << *rbSearch[i]<<endl;
	}

}
/**************************************************
Description:- This function is to process the data to be deleted 
		and sent to the further function to execute 
		the delete function
input:- string data
output:-NA

***************************/

void RBapp::processDelete(string& data)
{
	string key, satelliteData;
	key.clear();
	satelliteData.clear();
	int i,j;

	for (i=0;i< (int)data.length(); i++)
	{
		if (data[i]!=' ')
		{
			key= key+ data[i];
		}
		else
		{
			break;
		}
	}
	
	for (j=i+1; j<(int)data.length() ;j++)
	{
		satelliteData = satelliteData + data[j];
	}

	myRBT.rbDelete(key,satelliteData);
}
/**************************************************
Description:- This function is used to close the excecution
			of the program
input:-NA
output:-NA

***************************/
void RBapp::processQuit()
{
	exit(0);
}
/**************************************************
Description:-Constructor of RBApp
input:-NA 
output:-NA

***************************/

RBapp::RBapp()
{
	done=false;
}


