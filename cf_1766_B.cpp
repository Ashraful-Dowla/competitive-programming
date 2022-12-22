/*
https://codeforces.com/contest/1766/problem/B
*/
#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin>>n;
	string s;
	cin>>s;

	if(n<4) {
		cout<<"NO"<<endl;
		return ;
	}

	string prv="";
	map<string,int> mp;
	for(int i=1;i<n;++i){
		string pr;
		pr.push_back(s[i-1]);
		pr.push_back(s[i]);
		mp[pr]++;

		if((mp[pr]==2 && prv!=pr) || mp[pr]>2){
			cout<<"YES"<<endl;
			return ;
		}
		prv=pr;
	}

	cout<<"NO"<<endl;
}

int main(){
	int t;
	cin>>t;

	while(t--) {
	   solve();
	}
}