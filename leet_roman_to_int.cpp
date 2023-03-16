/*
https://leetcode.com/problems/roman-to-integer/description/
*/
#include <bits/stdc++.h>
using namespace std;

map<string, int> mp = {
	{"I", 1},
	{"IV", 4},
	{"V", 5},
	{"IX", 9},
	{"X", 10},
	{"XL", 40},
	{"L", 50},
	{"XC", 90},
	{"C", 100},
	{"CD", 400},
	{"D", 500},
	{"CM", 900},
	{"M", 1000}
};

int romanToInt(string s) {

	int n = s.size();
	int ans=0;
	for(int i=0;i<n;++i) {
	    
	    string ch="";
	    while(mp[ch+s[i]]){
	    	ch.push_back(s[i]);
	    	++i;
	    }
	    ans+=mp[ch];
	    --i;
	}

	return ans;
}

int main(){
	string s="XIV";
	cout<<romanToInt(s)<<endl;
}