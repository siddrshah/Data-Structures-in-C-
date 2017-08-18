/**
 * @file CensusDataSorts.cpp   Sort functions for census population data.
 * 
 * @brief
 *    Implements several different types of sorts. Data can be sorted
 * by population or by name of town. This file contains all of the sorting
 * functions and their helpers.
 *
 * @author Judy Challinger
 * @date 2/22/13
 */

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <random>
#include <ctime>
#include "CensusData.h"


/*****************************************
This function gets called when we need to sort cities using 
insertion Sort
input:- type
output:- 0

*****************/

// formal parameter name commented out to avoid unused variable warning
void CensusData::insertionSort(int type) {


	//unsigned int j;
	if (type ==0)
		insertion_Sortpopulation();
	else if (type == 1)
		insertion_Sortcity();
}

/*****************************************
This function gets called when we need to sort cities using 
insertion Sort for population
input:- 0
output:- 0

*****************/
void CensusData::insertion_Sortpopulation()
{
	int j;
	
	Record* key;
		
		
	for(j = 1;j<=getSize()-1;j++)
	{
		key = data.at(j);
		int i= j-1;
		while (i>=0 && data.at(i)->population > key->population)
		{
			data[i+1]= data[i];
			i=i-1;
		}
		data.at(i+1) = key;
	}
		
}

/*****************************************
This function gets called when we need to sort cities using 
insertion Sort for name
input:- 0
output:- 0

*****************/
void CensusData::insertion_Sortcity()
{
	Record* key; int j;
	for (j=1;j<=getSize()-1;j++)
	{
		key = data.at(j);
		int i = j-1;
		while (i>=0 && *data.at(i)->city > *key->city)
		{
			data.at(i+1)= data.at(i);
			i=i-1;

		}
		data.at(i+1) = key;
	}
}

/*****************************************
This function gets called when we need to sort cities using merge
Sort
input:- int type
output:- 0

*****************/

// formal parameter name commented out to avoid unused variable warning
void CensusData::mergeSort(int type) {
	int p =0;
	int r= getSize()-1;
	//string* city;
	//string* city1;
	if (type==0)
		merge_sortP(p,r);
	else if (type == 1)
		merge_sortC(p,r);

}
/*****************************************
This function gets called when we need to sort cities using 
merge sort by population
input:- int p int r
output:- 0

*****************/

void CensusData::merge_sortP(int p, int r)
{
	if (p< r)
	{
		int q = (p+r)/2;
		merge_sortP(p,q);
		merge_sortP(q+1,r);
		mergeP(p,q,r);
		
	
	}
}
/*****************************************
This function gets called when we need to sort cities using 
merge Sort population
input:- int p and int r
output:- 

*****************/

void CensusData::mergeP(int p, int q,int r)
{
	int n1,n2,i,j,k;
	n1= q-p+1;
	n2=r-q;
	vector<Record*> L;
	
	vector<Record*> R;
	for (i=1;i<=n1;i++)
	{
		L.push_back(data.at(p+i-1));	
	}
	for (j=1;j<=n2;j++)
	{
		R.push_back(data.at(q+j));	
	}

	
	
	i=0;
	j=0;

	for (k=p;k<=r;k++)
	{
		if (i<n1 && j< n2)
		{
			if ((L.at(i)->population)<=R.at(j)->population)
			{
				data.at(k)=L.at(i);
				i=i+1;
			}
		
		
			else 
			{
				data.at(k)= R.at(j);
				j=j+1;
			}
		}
		else if (i<n1)
		{
			data.at(k)=L.at(i);
			i=i+1;
		}
		else if (j<n2)
		{
			data.at(k)=R.at(j);
			j=j+1;
		}
	}

}
/*****************************************
This function gets called when we need to sort cities using 
merge Sort using name
input:- int p and int r
output:- 0

*****************/

void CensusData::merge_sortC(int p, int r)
{
	if (p< r)
	{
		int q = (p+r)/2;
		merge_sortC(p,q);
		merge_sortC(q+1,r);
		mergeC(p,q,r);
		
	
	}
}

/*****************************************
This function gets called when we need to sort cities using merge 
sort using name of city
input:- int p int r and int q
output:- 0

*****************/
void CensusData::mergeC(int p, int q,int r)
{
	int n1,n2,i,j,k;
	n1= q-p+1;
	n2=r-q;
	vector<Record*> L;
	vector<Record*> R;
	for (i=1;i<=n1;i++)
	{
		L.push_back(data.at(p+i-1));	
	}
	for (j=1;j<=n2;j++)
	{
		R.push_back(data.at(q+j));	
	}

	
	
	i=0;
	j=0;

	for (k=p;k<=r;k++)
	{
		if (i<n1 && j< n2)
		{
			if (*L.at(i)->city <= *R.at(j)->city)
			{
				data.at(k)=L.at(i);
				i=i+1;
			}
		
		
			else 
			{
				data.at(k)= R.at(j);
				j=j+1;
			}
		}
		else if (i<n1)
		{
			data.at(k)=L.at(i);
			i=i+1;
		}
		else if (j<n2)
		{
			data.at(k)=R.at(j);
			j=j+1;
		}
	}

}

/*****************************************
This function gets called when we need to sort cities using Quick Sort
input:- int type
output:-

*****************/



// formal parameter name commented out to avoid unused variable warning
void CensusData::quickSort(int type) {

	int seed= time(0);

	int r =getSize()-1;
	
	int p = 0;
	if (type == 0)
		quick_sortpopulation(seed,p,r );
	else if (type ==1)
		quick_sortcity(seed,p,r) ;
	
}
/*****************************************
This function gets called when we need to sort cities using 
quick sort
input:- int seed, int p, int r
output:- 0

*****************/


void CensusData::quick_sortpopulation( int seed,int p, int r)
{
	if (p<r)
	{
		std :: default_random_engine rand_number(seed);
		std :: uniform_int_distribution<int> distribution(p,r);
		int rand = distribution(rand_number);
		//referred from cplusplus.com
		Record* temp;
		temp =data.at(r) ;
		data.at(r)=data.at(rand);
		data.at(rand)=temp;
		int q = partitionP (p,r);
		if(q>0)
		quick_sortpopulation(seed,p, q-1);
		quick_sortpopulation(seed,q+1,r);	
	}
}
/*****************************************
This function gets called when we need to sort cities using 
quick sort by population
input:- 0
output:- 0

*****************/

int CensusData::partitionP(int p, int r)
{
	
	Record* x = data.at(r);
	Record* temp;
	int i = p-1;
	for (int j = p; j<=r-1; j++ )
	{
		if (data.at(j)->population<= x->population)
		{
			i= i+1;
			temp=data.at(i);
			data.at(i) = data.at(j);
			data.at(j)=temp;
		}
		
	}
	temp=data.at(i+1);
	data.at(i+1)= data.at(r);
	data.at(r)=temp;
	return i+1;

}

/*****************************************
This function gets called when we need to sort cities using quick sort
for name
input:- int p and int r and int seed
output:- -

*****************/


void CensusData::quick_sortcity(int seed,int p, int r)
{
	
	if (p<r)
	{
		std :: default_random_engine rand_number(seed);
		std :: uniform_int_distribution<int> distribution(p,r);
		int rand = distribution(rand_number);
		Record* temp;
		temp =data.at(r) ;
		data.at(r)=data.at(rand);
		data.at(rand)=temp;
		
		int q = partitionC (p,r);
		if (q>0)
		quick_sortcity(seed,p, q-1);
		quick_sortcity(seed,q+1,r);
	}

}
/*****************************************
This function gets called when we need to sort cities
in quick sort algorithms
input:- int p and int r
output:- int 

*****************/
int CensusData::partitionC(int p , int r)
{
	//int x = data.at(r)->population;
	Record* x = data.at(r);
	Record* temp;
	int i = p-1;
	for (int j = p; j<=r-1;j++ )
	{
		if (*data.at(j)->city <= *x->city)
		{
			i= i +1;
			temp=data.at(i);
			data.at(i) = data.at(j);
			data.at(j)=temp;
			
		}
		
	}
	temp=data.at(i+1);
	data.at(i+1)= data.at(r);
	data.at(r)=temp;
	return i+1;
}
