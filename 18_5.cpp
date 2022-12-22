/*
https://www.hackerearth.com/practice/data-structures/hash-tables/basics-of-hash-tables/practice-problems/algorithm/bob-and-string-easy/
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	int T;
	cin>>T;
	while(T--){
		string s,t;
		cin>>s>>t;
		int hshS[200], hshT[200];

		memset(hshS, 0, sizeof(hshS));
		memset(hshT, 0, sizeof(hshT));

		for(int i=0; i<s.size();i++){
			hshS[s[i]-'a']++;
		}

		for(int i=0;i<t.size();i++){
			hshT[t[i]-'a']++;
		}

		bool taken[200];
		memset(taken, 0, sizeof(taken));

		int add=0, del=0;
		for(int i=0;i<s.size();i++){
			if(taken[s[i]-'a']) continue;
			int diff = hshS[s[i]-'a'] - hshT[s[i]-'a'];
			if(diff>0) add+=diff;
			taken[s[i]-'a']=true;
		}

		memset(taken, 0, sizeof(taken));
		for(int i=0;i<t.size();i++){
			if(taken[t[i]-'a']) continue;
			int diff = hshT[t[i]-'a'] - hshS[t[i]-'a'];
			if(diff>0) del+=diff;
			taken[t[i]-'a']=true;
		}
		cout<<add+del<<endl;
	}
}