/*
https://codeforces.com/contest/1758/problem/A
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;

	while(t--) {
	   string s;
	   cin>>s;
	   string ans="";

	   for(int i=0;i<s.size();++i){
	   	   ans = s[i] + ans;
	   	   ans+=s[i];
	   }

	   cout<<ans<<endl;

	}
}