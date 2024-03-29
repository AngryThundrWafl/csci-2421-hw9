//
// Created by Brian on 4/18/2016.
//
#include "LinkedList.h"
namespace Hash {
// Constructs the empty linked list object.
// Creates the head node and sets length to zero.
    LinkedList::LinkedList() {
        head = new Item;
        head->next = NULL;
        length = 0;
    }

// Inserts an item at the end of the list.
    void LinkedList::insertItem(Item *newItem) {
        if (!head->next) {
            head->next = newItem;
            length++;
            return;
        }
        Item *p = head;
        Item *q = head;
        while (q) {
            p = q;
            q = p->next;
        }
        p->next = newItem;
        newItem->next = NULL;
        length++;
    }

// Removes an item from the list by item key.
// Returns true if the operation is successful.
    bool LinkedList::removeItem(std::string itemKey) {
        if (!head->next) return false;
        Item *p = head;
        Item *q = head;
        while (q) {
            if (q->key == itemKey) {
                p->next = q->next;
                delete q;
                length--;
                return true;
            }
            p = q;
            q = p->next;
        }
        return false;
    }

// Searches for an item by its key.
// Returns a reference to first match.
// Returns a NULL pointer if no match is found.
    Item *LinkedList::getItem(std::string itemKey) {
        Item *p = head;
        Item *q = head;
        while (q) {
            p = q;
            if ((p != head) && (p->key == itemKey))
                return p;
            q = p->next;
        }
        return NULL;
    }

// Displays list contents to the console window.
    void LinkedList::printList() {
        if (length == 0) {
            std::cout << "\n{ }\n";
            return;
        }
        Item *p = head;
        Item *q = head;
        std::cout << "\n{ ";
        while (q) {
            p = q;
            if (p != head) {
                std::cout << p->key;
                if (p->next) std::cout << ", ";
                else std::cout << " ";
            }
            q = p->next;
        }
        std::cout << "}\n";
    }

// Returns the length of the list.
    int LinkedList::getLength() {
        return length;
    }

// De-allocates list memory when the program terminates.
    LinkedList::~LinkedList() {
        Item *p = head;
        Item *q = head;
        while (q) {
            p = q;
            q = p->next;
            if (q) delete p;
        }
    }
}