#include "woke.h"


// sets the file name for input
void Translator::setFileName(const string &textInput){
    fileName = textInput;
}

// gets the given file name
const string Translator::getFileName() const{
    return fileName;
}

ifstream Translator::openFile(){
    ifstream file(fileName);
    if (!file.is_open()) cerr << "Could Not Open File!";
    return file;
}

// creates the translated file
ofstream Translator::makeFile(){
    cout << "\nObject Translator::makeFile() called" << endl;
    string new_name = getFileName();
    cutString(new_name);
    ofstream wokeFile(new_name);
    return wokeFile;
}


void Translator::cutString(string &str){
    cout << "\nObject Translator::cutString(string &str) called" << endl;
    str.erase(str.length()-4, str.length());  // cuts the last .txt
    str += "Woke";
}

// fed an input, calls the transform function and outputs the woke file.
void Translator::translator(){

    cout << "\nObject Translator::translator() called" << endl;
    ifstream inputFile = openFile();
    ofstream wokeFile = makeFile();
    string st;

    if (!inputFile.is_open()) cout << "Couldnt Open File..." << endl;
    else{
        while(inputFile >> st){
            //if ( isupper( st.at(0) ) ) wokeFile << '\n';          // kind of overkill
            transform(st);
            wokeFile << st << " ";
            if (st[st.length()-1] == '.') wokeFile << '\n';        // if it ends with '.' enters a new line
        }
    }
    wokeFile.close(); inputFile.close();
}



// transforms each word / string one-by-one
void transform(string &st){

    //cout << "\nExternal Function - transform(string &st) called" << endl;
    bool found = false;
    int i = st.length()-1;

    while(i >= 0 && !found && st.length() > 3){

        if (st[i] == 'a' || st[i] == 'o'){
            st[i] = 'x';
            found = true;
        }else if(st[i] == 'y') found = true;
        i--;
    }
}
