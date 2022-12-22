/*
https://codeforces.com/contest/525/problem/A
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	string s;
	cin>>s;

	map<char,int>m;

	int cnt=0;

	for(int i=0;i<2*n-2;i+=2){
		char ch = tolower(s[i+1]);
		if(s[i]!=ch){
			m[s[i]]++;
			if(m[ch]==0) cnt++;
			else m[ch]--;
		}
	}

	cout<<cnt<<endl;
}