/*
https://codeforces.com/contest/1779/problem/A
*/
#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin>>n;

	string s;
	cin>>s;

	size_t found1 = s.find("LR");
	size_t found2 = s.find("RL");

	if(found2!=string::npos) cout<<0<<endl;
  	else if (found1!=string::npos) cout<<found1+1<<endl;
  	else cout<<-1<<endl;
}

int main(){
	int t;
	cin>>t;

	while(t--) {
	    solve();
	}
}