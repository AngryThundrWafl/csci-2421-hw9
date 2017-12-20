#include "HashTable.h"


using namespace std;

int main() {
    Hash::Item ayyeLmao;              //creates a object that will hold an item that will get read in
    Hash::HashTable table(1373);            //create a object caled table that will have a hash table
    ifstream file;              //creates an object of ofstream
    file.open("dict.txt");      //opens a data file for the ofstream file
    if(file.fail()){
        cout << "Could not open file" << endl;
        return 0;               //just in case the file does not open
    }
    table.readFile(file,table); //read in the data from the file and puts it in the hash table
    int choice;
    do{
        cout << "Welcome to spell checker please enter an option that you would like to do" << endl;
        cout << "1: Spell Check A Word" << endl;
        cout <<"2: Print the Dictionary" << endl;
        cout << "3: Exit" << endl;
        cin >> choice;
        if(choice == 1) {
            cout << "Please enter a word to spell check" << endl;
            string userWord;
            cin >> userWord;
            table.isCorrect(table, userWord);
        }
        else if(choice == 2){
            cout << "Printing Table" << endl;
            table.printTable();
        }
    }while(choice != 3);
        cout << "Exiting Program!" << endl;

    return 0;
}
