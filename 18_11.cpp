/*
https://www.hackerearth.com/practice/data-structures/hash-tables/basics-of-hash-tables/practice-problems/algorithm/a-needle-in-the-haystack-1/
-incomplete
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		string pattern, text;
		cin>>pattern>>text;
		int hshP[30], hshT[30];

		memset(hshP, 0, sizeof(hshP));
		memset(hshT, 0, sizeof(hshT));

		for(int i=0;i<pattern.size();i++){
			hshP[pattern[i]-'a']++;
		}
		for(int j=0;j<text.size();j++){
			hshT[text[j]-'a']++;
		}
	}
}