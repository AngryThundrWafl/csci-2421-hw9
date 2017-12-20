//
// Created by Brian on 4/18/2016.
//

#include "HashTable.h"


namespace Hash {
// Constructs the empty Hash Table object.
// Array length is set to 13 by default.
    HashTable::HashTable(int tableLength) {
        if (tableLength <= 0) tableLength = 1373;
        word = new LinkedList[tableLength];
        length = tableLength;
    }

// Returns an array location for a given item key.
    int HashTable::hash(std::string itemKey) {
        int value = 0;
        for (int i = 0; i < itemKey.length(); i++)
            value += itemKey[i];
        return (value * itemKey.length()) % length;
    }

// Adds an item to the Hash Table.
    void HashTable::insertItem(Item *newItem) {
        int index = hash(newItem->key);
        word[index].insertItem(newItem);
    }

// Deletes an Item by key from the Hash Table.
// Returns true if the operation is successful.
    bool HashTable::removeItem(std::string itemKey) {
        int index = hash(itemKey);
        return word[index].removeItem(itemKey);
    }

// Returns an item from the Hash Table by key.
// If the item isn't found, a null pointer is returned.
    Item *HashTable::getItemByKey(std::string itemKey) {
        int index = hash(itemKey);
        return word[index].getItem(itemKey);
    }

// Display the contents of the Hash Table to console window.
    void HashTable::printTable() {
        std::cout << "\n\nHash Table:\n";
        for (int i = 0; i < length; i++) {
            std::cout << "Bucket " << i + 1 << ": ";
            word[i].printList();
        }
    }


// Prints a histogram illustrating the Item distribution.
    void HashTable::printHistogram() {
        std::cout << "\n\nHash Table Contains ";
        std::cout << getNumberOfItems() << " Items total\n";
        for (int i = 0; i < length; i++) {
            std::cout << i + 1 << ":\t";
            for (int j = 0; j < word[i].getLength(); j++)
                std::cout << " X";
            std::cout << "\n";
        }
    }

// Returns the number of locations in the Hash Table.
    int HashTable::getLength() {
        return length;
    }

// Returns the number of Items in the Hash Table.
    int HashTable::getNumberOfItems() {
        int itemCount = 0;
        for (int i = 0; i < length; i++) {
            itemCount += word[i].getLength();
        }
        return itemCount;
    }

// De-allocates all memory used for the Hash Table.
    HashTable::~HashTable() {
        delete[] word;        //deletes the array created in hash
    }


    void HashTable::readFile(std::ifstream &os, HashTable &table) {
        //todo see if you can use shino or create a new item variable, same thing with the write function
        while (!os.eof()) {
            Item *NEW = new Item;
            std::string werd;
            getline(os, werd);
            NEW->next = NULL;
            NEW->key = werd;
            table.insertItem(NEW);
        }
    }


    void HashTable::isWrong(HashTable &table, std::string word) {
        std::cout << word <<
        " was spelled incorrectly or was not in the dictionary would you like to add enter 1 and 0 for no" << std::endl;
        int choice;
        do {
            std::cin >> choice;
            if (choice == 1) {
                Item *NEW = new Item;
                NEW->next = NULL;
                NEW->key = word;
                table.insertItem(NEW);
                std::cout << "Word Added" << std::endl;
                return;
            }
            else if (choice != 1 && choice != 0)
                std::cout << "Wrong Input please try again" << std::endl;
        } while (choice != 0);
    }

    void HashTable::isCorrect(HashTable &table, std::string word) {
        Item *shino = new Item;
        shino = table.getItemByKey(word);
        if (shino == NULL) {
            table.isWrong(table, word);
        }
        else if (shino->key != "") {
            std::cout << word << " Was spelled correctly" << std::endl;
        }
    }
}