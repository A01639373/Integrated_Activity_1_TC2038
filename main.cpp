#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "./headers/LPS_ARRAY.h"

using namespace std;

void ReadFiles(vector<string>& strings, string fileName);

int main(int argc, char* argv[]){
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <test_case_folder>" << endl;
        return 1;
    }
    string folder = argv[1];

    vector<string> transmissions, mCodes;
    ReadFiles(transmissions, folder + "/transmission1.txt");
    ReadFiles(transmissions, folder + "/transmission2.txt");
    ReadFiles(mCodes, folder + "/mCode1.txt");
    ReadFiles(mCodes, folder + "/mCode2.txt");
    ReadFiles(mCodes, folder + "/mCode3.txt");

    vector<int> lps1, 
                lps2, 
                lps3;

    
    return 0;
}

void ReadFiles(vector<string>& strings, string fileName){
    ifstream inputFile(fileName);
    if (inputFile.is_open()) {
        string line;
        while(getline(inputFile,line)){
            strings.push_back(line);
        }
        inputFile.close();
    } else{
        cout << "Error: Could not open the file." << endl;
    }
}