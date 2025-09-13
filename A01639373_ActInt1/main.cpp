#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "./MANACHER.h"

using namespace std;

string ReadFiles(string fileName);

int main(){
    //read codes/transmissions
    vector<string> transmissions, mCodes;
    transmissions.push_back(ReadFiles("./transmission1.txt"));
    transmissions.push_back(ReadFiles("./transmission2.txt"));
    mCodes.push_back(ReadFiles("./mCode1.txt"));
    mCodes.push_back(ReadFiles("./mCode2.txt"));
    mCodes.push_back(ReadFiles("./mCode3.txt"));

    //
    for (int t = 0; t < transmissions.size(); t++) {
        string &transmission = transmissions[t];
        Manacher mob(transmission);
        
        cout << "\n=== Transmission " << t+1 << " ===\n";
        for(int i=0; i<mCodes.size(); i++){
            vector<pair<int,int>> candidates = mob.getPalindromesOfLength(mCodes[i].size());
            bool found = false;

            for(int j=0; j < candidates.size(); j++){
                // start and end of position pairs
                int start = candidates[j].first;
                int end = candidates[j].second;
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
