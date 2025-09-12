#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "./MANACHER.h"

using namespace std;

string ReadFiles(string fileName);

int main(int argc, char* argv[]){
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <test_case_folder>" << endl;
        return 1;
    }
    string folder = argv[1];

    //read codes/transmissions
    vector<string> transmissions, mCodes;
    transmissions.push_back(ReadFiles(folder + "/transmission1.txt"));
    transmissions.push_back(ReadFiles(folder + "/transmission2.txt"));
    mCodes.push_back(ReadFiles(folder + "/mCode1.txt"));
    mCodes.push_back(ReadFiles(folder + "/mCode2.txt"));
    mCodes.push_back(ReadFiles(folder + "/mCode3.txt"));

    //
    for (int t = 0; t < transmissions.size(); t++) {
        string &transmission = transmissions[t];
        Manacher mob(transmission);
        
        cout << "\n=== Transmission " << t+1 << " ===\n";
        for(int i=0; i<mCodes.size(); i++){
            vector<pair<int,int>> candidates = mob.getPalindromesOfLength(mCodes[i].size());
            bool found = false;

            for(int i = 0; i < candidates.size(); i++){
                int start = candidates[i].first;
                int end = candidates[i].second;
                string candidate = transmission.substr(start, end - start + 1);

                if (candidate == mCodes[i]) {
                    found = true;
                    cout << mCodes[i] << " found at positions " << start << "-" << end << "\n";
                }
            }

            if(!found){
                cout << mCodes[i] << " not found\n";
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
