#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "./headers/LPS_ARRAY.h"

using namespace std;

string ReadFiles(string fileName);

int main(int argc, char* argv[]){
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <test_case_folder>" << endl;
        return 1;
    }
    string folder = argv[1];

    vector<string> transmissions, mCodes;
    transmissions.push_back(ReadFiles(folder + "/transmission1.txt"));
    transmissions.push_back(ReadFiles(folder + "/transmission2.txt"));
    mCodes.push_back(ReadFiles(folder + "/mCode1.txt"));
    mCodes.push_back(ReadFiles(folder + "/mCode2.txt"));
    mCodes.push_back(ReadFiles(folder + "/mCode3.txt"));
    

    vector<int> lps1,
                lps2, 
                lps3;


    return 0;
}

string ReadFiles(string fileName){
    ifstream inputFile(fileName);
    if (inputFile.is_open()) {
        string line;
        getline(inputFile,line);
        inputFile.close();

        return line;
    } else{
        cout << "Error: Could not open the file." << endl;
        return "";
    }
}