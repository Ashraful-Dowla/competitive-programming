/*
https://www.hackerearth.com/practice/data-structures/hash-tables/basics-of-hash-tables/practice-problems/algorithm/xsquare-and-double-strings-1/
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		int hsh[30];
		memset(hsh,0,sizeof(hsh));
		for(int i=0;i<s.size();i++){
			hsh[s[i]-97]++;
		}
		int cnt=0;
		for(int i=0;i<26;i++){
			if(hsh[i]>1) cnt++;
		}

		cnt == 0 ? cout<<"No"<<endl: cout<<"Yes"<<endl;
	}
}