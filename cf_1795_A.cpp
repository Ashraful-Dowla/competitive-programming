/*
https://codeforces.com/contest/1795/problem/A
*/
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long
#define Faster ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

//debug
#define vec_prnt(v) for(auto x: v) { cout<<x<<" "; } cout<<"\n"

const int N=1e5+10;
const int MOD=1e9+7;

void solve(){
	int n,m;
	cin>>n>>m;

	string s,t;
	cin>>s;
	cin>>t;

	reverse(t.begin(),t.end());

	s = s+t;

	int rr=0,bb=0;
	for(int i=0;i+1<s.size();++i){
		if(s[i]=='R' && s[i+1]=='R') rr++;
		if(s[i]=='B' && s[i+1]=='B') bb++;
	}

	if(rr==1 && bb==0) cout<<"YES"<<endl;
	else if(rr==0 && bb==1) cout<<"YES"<<endl;
	else if(rr==0 && bb==0) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}

int main(){
	Faster;

	int t;
	cin>>t;

	while(t--){
	   solve();
	}
}