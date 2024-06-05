/*
https://leetcode.com/problems/append-characters-to-string-to-make-subsequence/description/?envType=daily-question&envId=2024-06-03
*/
#include <bits/stdc++.h>
using namespace std;

int appendCharacters(string s, string t) {

    int j = 0;
    for (int i = 0; j < t.size() && i < s.size(); ++i) {
        if (s[i] == t[j]) {
            ++j;
        }
    }

    return t.size() - j;
}

int main() {

    string s = "coaching";
    string t = "coding";

    cout << appendCharacters(s, t) << endl;
}