/**
 * @file CensusData.h   Declaration of the CensusData class.
 *
 * @author Judy Challinger
 * @date 2/22/13
 */

#ifndef CSCI_311_CENSUSDATA_H
#define CSCI_311_CENSUSDATA_H

#include <vector>
using std::ifstream;
using std::string;
using std::vector;

class CensusData {
public:
   static const int POPULATION = 0;       // type of sort
   static const int NAME = 1;
   ~CensusData();
   void initialize(ifstream&);            // reads in data
   int getSize(){return data.size();}
   void print();                          // prints out data
   void insertionSort(int);               // sorts data using insertionSort
   void mergeSort(int);                   // sorts data using mergeSort
   void quickSort(int);                   // sorts data using quickSort
private:
   class Record {                         // declaration of a Record
   public:
      string* city;
      string* state;
      int population;
      Record(string&, string&, int);
      ~Record();
   };
   vector<Record*> data;                  // data storage
//
// You may add your private helper functions here!
//
   void insertion_Sortpopulation();
   void insertion_Sortcity();
   void quick_sortpopulation(int seed,int p, int r);
   void quick_sortcity(int seed, int p, int r);
   int partitionP(int p, int r);
   int partitionC(int p, int r);
   //int compare(string *city,string *city1);
   void merge_sortP(int p, int q);
   void merge_sortC(int p, int q);
   void mergeP(int p, int q, int r);
   void mergeC(int p, int q, int r);
   
   //int random();
   //bool isSmaller(int, Record*, Record*);   // this is one I used - you may delete
};

#endif // CSCI_311_CENSUSDATA_H