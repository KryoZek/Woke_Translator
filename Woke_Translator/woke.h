#include <iostream>
//#include <vector>
#include <fstream>
#include <string>
//#include <algorithm>
using namespace std;

// OPENSOURCE via @ https://github.com/FrancisKRZ/Woke_Translator.git

/*      This small project will take a file input from the terminal
        it'll read the text and replace any 'a' and 'o' with 'x' .
        To provide an immersive modern-day academic experience
        for the writer without having to worry they made a mistake. */



class Translator{

private:
    string fileName = " ";          // file name
    int numbers = 0;
    char character = ' ';
    ifstream inputFile;
    ofstream wokeFile;

public:
    // getters
    const string getFileName() const;

    // setters
    void setFileName(const string &textInput);

    // stuff
    ifstream openFile();
    ofstream makeFile();

    void translator();
    void cutString(string &str);

};

void transform(string &st);
