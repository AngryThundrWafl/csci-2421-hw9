//
// Created by Brian on 4/18/2016.
//
//holds the implemenation of hashtable and uses the node and linked list from linked list.h
#ifndef PINAHW9_HASHTABLE_H
#define PINAHW9_HASHTABLE_H
#include "LinkedList.h"
namespace Hash {
/////////###############CLASS FOR HASHTABLE############################################################################/////
    class HashTable {
    private:
        LinkedList *word;                                    //Array is reference to an array of the linked list each element will hold a linked list
        int length;                                          //is the size of the hashtable of the array
        int hash(std::string itemKey);                     //returns an array location for a given item key
    public:
        HashTable(
                int tableLength = 1373);                 //constructs an empty hash table, array length is set to 13 by default
        void insertItem(Item *newItem);                  //adds an item to the hash table
        bool removeItem(
                std::string itemKey);             //deletes an item bey key from the hashtable, returns true if it is succesful
        Item *getItemByKey(
                std::string itemKey);          //returns item from hashtable by key, if he item isnt found it will return a null ptr
        void printTable();                                  //display the contents of the hashtable
        void printHistogram();                               //prints the Item distribution
        int getLength();                                    //returns the location in the hash table
        int getNumberOfItems();                              //returns the number of items in the hash table
        ~HashTable();                                       //deallocates all the memory in the hash table
        //functions to read and write to file
        void readFile(std::ifstream &, HashTable &);         //opens up file reads in data inserts it into the hashtable
        void writeFile();                                   //writes the hashtable to the files
        void isWrong(HashTable &, std::string);                          //checks if the wrong put in is wrong
        void isCorrect(HashTable &, std::string);                        //checks if its correct

    };
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//############### EXTERNAL FUNCTIONS FOR MAIN ########################################################################/////wil show menu that will calls print for certain parts if the list
//####### WILL PASS IN A OSTREAM FILE AND WILL INSERT DATA TO THE HASHTABLE  WRITE DATA FROM HASH T FILE #########//
}
//#################################################################################################################//



#endif //PINAHW9_HASHTABLE_H
