/*
https://codeforces.com/contest/1766/problem/C
*/
#include <bits/stdc++.h>
using namespace std;

bool solve(){
	int n;
	cin>>n;
	
	string s1,s2;
	cin>>s1>>s2;

	int a=1,b=1;
	for(int i=0;i<n;++i){
		if(s1[i]=='B' && s2[i]=='B') swap(a,b);
		else if(s1[i]=='B') b=0;
		else a=0;
	}

	if(a==0 && b==0) return false;
	else return true;	
}

int main(){
	int t;
	cin>>t;

	while(t--) {
	    cout<<(solve() ? "YES":"NO")<<endl;
	}
}