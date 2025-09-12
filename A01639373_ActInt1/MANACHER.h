#ifndef MANACHER_H
#define MANACHER_H

#include <vector>
#include <string>
using namespace std;

class Manacher {
public:
    vector<int> pal;    // palindrome radius array
    string ms;        // transformed string

    // Constructor: transforms the string and runs Manacher
    Manacher(const string &s) {
        ms = "#";
        for (char c : s) {
            ms += "#" + string(1, c);
        }
        ms += "#";
        runManacher();
    }

    void runManacher() {
        int n = ms.size();
        pal.assign(n, 0);
        int l = 0, r = 0;

        for (int i = 1; i < n - 1; ++i) {
            int mirror = l + r - i;
            if (i < r) pal[i] = min(r - i, pal[mirror]);
            while (ms[i + 1 + pal[i]] == ms[i - 1 - pal[i]]) ++pal[i];
            if (i + pal[i] > r) {
                l = i - pal[i];
                r = i + pal[i];
            }
        }
    }

    // Get palindrome radius centered at index `cen` (original string index)
    int getLongest(int cen, int odd) {
        int pos = 2 * cen + 2 + !odd;
        return pal[pos];
    }

    // Return all palindromes of a given length in the original string
    vector<pair<int,int>> getPalindromesOfLength(int length) {
        vector<pair<int,int>> result;
        int n = (ms.size() - 2) / 2;

        for (int i = 0; i < n; ++i) {
            // Odd-length palindromes
            int oddLen = getLongest(i, 1);
            for (int len = 1; len <= oddLen; len += 2) {
                if (len == length) {
                    int start = i - len / 2;
                    int end = i + len / 2;
                    result.push_back({start, end});
                }
            }

            // Even-length palindromes
            int evenLen = getLongest(i, 0);
            for (int len = 2; len <= evenLen; len += 2) {
                if (len == length) {
                    int start = i - len / 2 + 1;
                    int end = i + len / 2;
                    result.push_back({start, end});
                }
            }
        }
        return result;
    }
};

#endif