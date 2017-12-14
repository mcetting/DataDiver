// ------------------------------------------------------------- //
// when the program is opened get a file name
// check if that file exists
// if it does then load the contents and allow then to edit it
// else make a new file and allow the same
// ------------------------------------------------------------- //
#include <iostream>
#include <fstream>
using namespace std;

// prototypes
void fileEditor(string file_name); // basic editing loop
void getFileName(string *s);       // takes a pointer of a variable

// ------------------------------------------------------------- //
// Main

int main(){
    string file_name;

    // pass it the address of file name
    getFileName(&file_name);

    // constructor for ofstream object
    ifstream file(file_name.c_str());

    // check if the ofstream object is found
    if(file.good()){
        // the file exists so we will read it
        cout<<"File already exists."<<endl;
        fileEditor(file_name);
    }else{
        // the file doesnt exist so make a new one
        cout<<"New file."<<endl;

        // makes a new file with this name
        ofstream oFile(file_name.c_str());
        if(oFile.is_open()){
            // write something to it
            // debuging menu
            fileEditor(file_name);
        }

        // close the file
        oFile.close();
    }
    // close the file
    file.close();
    cout<<"CLOSING FILE"<<endl;
}
// ------------------------------------------------------------- //
// Functions

// basic editing loop
void fileEditor(string file_name){
    bool loop = true;
    // menu loop
    while(loop){
        cout<<"Options: display, remove, delete, add, help"<<endl;
        string input;
        cin>>input;
        if(input == "display"){
            // print the list
            cout<<"Printing"<<endl;
        }else if(input == "remove"){
            // remove part of the list
            cout<<"Removing"<<endl;
        }else if(input == "add"){
            // add to the list
            cout<<"Adding"<<endl;
        }else if(input == "delete"){
            // deletes the current open file
            // then ends the program
            remove(file_name.c_str());
            break;
        }else if(input == "quit"){
            // break the loop
            break;
        }else if(input == "help"){
            cout<<"Help:"<<endl;
            cout<<"display - displays targets contents to the console"<<endl;
            cout<<"remove  - removes select content from the file"<<endl;
            cout<<"delete  - deletes target file"<<endl;
            cout<<"add     - adds select content to the file"<<endl;
        }
    }
}
// pass by reference function
void getFileName(string *s){
    cout<<"Enter a file name(one word): ";
    cin>>*s;

    *s +=".txt";
}
// C++ notes

/* Pass by reference
 * pass a memory address of the variable you want to change in the function
 * function will ask for a pointer of the variable
 * this allows the original value to be changed
 */