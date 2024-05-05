/*
https://leetcode.com/problems/boats-to-save-people/description/?envType=daily-question&envId=2024-05-04
*/
#include <bits/stdc++.h>
using namespace std;

int numRescueBoats(vector<int>& people, int limit) {

    sort(people.begin(), people.end());

    int lo = 0, hi = people.size() - 1, ans = 0;

    while (lo < hi) {
        if (people[lo] + people[hi] <= limit) {
            lo++, hi--;
        }
        else {
            hi--;
        }
        ans++;
    }

    if (lo == hi) {
        ans++;
    }

    return ans;
}

int main() {

    // vector<int> people = {3, 2, 2, 1};
    // int limit = 3;

    // vector<int> people = {3, 5, 3, 4};
    // int limit = 5;

    vector<int> people = {1, 2};
    int limit = 3;

    cout << numRescueBoats(people, limit) << endl;
}