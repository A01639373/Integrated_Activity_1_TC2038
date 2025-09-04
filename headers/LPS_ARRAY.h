#ifndef LPS_ARRAY_H
#define LPS_ARRAY_H

#include <vector>
#include <string>

using namespace std;

vector<int> ComputeLPSArray(string pattern){
    int n = pattern.size();
    vector<int> lps(n, 0);
        
    // length of the previous longest prefix suffix
    int len = 0;  
    int i = 1;

    while (i < n) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) { 
                // fall back in the pattern
                len = lps[len - 1];  
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
}

#endif