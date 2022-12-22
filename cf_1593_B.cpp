/*
https://codeforces.com/problemset/problem/1593/B
*/
#include <bits/stdc++.h>
using namespace std;

int generate(string str,string sq){
	int st_sz = str.size()-1;

	int ans=0;
	while(st_sz>=0 && str[st_sz]!=sq[1]){
		st_sz--;
		ans++;
	}

	if(st_sz<0) return INT_MAX;

	st_sz--;
	
	while(st_sz>=0 && str[st_sz]!=sq[0]){
		st_sz--;
		ans++;
	}

	return st_sz<0 ? INT_MAX : ans;

}

int main(){
	int t;
	cin>>t;
	string seq[4] = {"00","25","50","75"};

	while(t--) {
	   string s;
	   cin>>s;
	   int ans = INT_MAX;
	   for(string sq: seq){
	   	  ans = min(ans,generate(s,sq));
	   }
	   cout<<ans<<endl;
	}
}