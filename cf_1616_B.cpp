/*
https://codeforces.com/contest/1616/problem/B
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;

	while(t--) {
	   	int n;
	   	cin>>n;
	   	string s;
	   	cin>>s;
	   	if(n==1 || s[0]==s[1]) cout<<s[0]<<s[0]<<endl;
	   	else {
	   		int k=1;
	   		while(k<n && s[k]<=s[k-1]){
	   			++k;
	   		}

	   		for(int i=0;i<k;++i) cout<<s[i];
	   		for(int i=k-1;i>=0;--i) cout<<s[i];
	   		cout<<endl;
	   	}
	}
}