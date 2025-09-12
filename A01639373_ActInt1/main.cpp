#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "./MANACHER.h"

using namespace std;

string ReadFiles(string fileName);
void Evaluate(vector<string>& mCodes, string transmissions);

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

    //KMP's Algorithm
    //Evaluate(mCodes, transmissions[0]);

    for (int t = 0; t < transmissions.size(); t++) {
        string &transmission = transmissions[t];
        Manacher mob(transmission); // use Manacher directly
        cout << "\n=== Transmission " << t+1 << " ===\n";

        // Loop through mCodes
        for (auto &mCode : mCodes) {
            vector<pair<int,int>> candidates = mob.getPalindromesOfLength(mCode.size());
            bool found = false;

            for (auto &p : candidates) {
                string candidate = transmission.substr(p.first, p.second - p.first + 1);
                if (candidate == mCode) {
                    found = true;
                    cout << mCode << " found at positions " << p.first << "-" << p.second << "\n";
                }
            }

            if (!found) {
                cout << mCode << " not found\n";
            }
        }
    }


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
