/*
https://codeforces.com/problemset/problem/1430/D
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--) {
	   int n;
	   string s;
	   cin>>n;
	   cin>>s;

	   int d=1,sm=0;
	   for(int i=1;i<n;++i){
	   		if(s[i]!=s[i-1]) d++;
	   		else sm=min(sm+1,d);
	   }
	   cout<<(d+sm+1)/2<<endl;
	}
}