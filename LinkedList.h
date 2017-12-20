//
// Created by Brian on 4/18/2016.
//
//holds the implementations of linked list.h creates the struct of the item that will basically be the node, and also implements linked list
#ifndef PINAHW9_LINKEDLIST_H
#define PINAHW9_LINKEDLIST_H
#include <iostream>     //this will let us use the iostream operations
#include <string>       //so we can use strings
#include <fstream>
#include <array>
#include <list>

namespace Hash {
//##### STUCT THAT HOLDS ITEMS THAT ARE KEYS AND HOLDS PTRS TO THEM ####///
    struct Item {
        std::string key;                             //the item that will get passed
        Item *next;                                  //this will be a ptr to the next item in the struct
    };
//#######################################################################//

//############# THIS WILL HOLD A VARIABLE LIST OF ITEMS#################///
    class LinkedList {
    private:
        Item *head;                                //is a reference to the head list of data nodes
        int length;                                 //length is the number of data nodes
    public:
        LinkedList();                                //constructor for linked list, sets head to null and lengt equal to zero
        void insertItem(Item *newItem);          //inserts a item to the end of the list
        bool removeItem(
                std::string itemKey);     //removes item from list of key, returns true if operation is succesful
        Item *getItem(
                std::string itemKey);      //searches for item of key and then returns first match and if no match is found returns NULL
        void printList();

        int getLength();                            //returns the length of the list
        ~LinkedList();                              //deallocates list of memoery when it terminates
    };
////####################################################################///
}
#endif //PINAHW9_LINKEDLIST_H
