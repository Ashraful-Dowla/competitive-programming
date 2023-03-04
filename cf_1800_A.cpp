/*
https://codeforces.com/contest/1800/problem/A
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
	int n;
	cin>>n;

	string s;
	cin>>s;

	string lo="meow";
	string up="MEOW";

	int idx=0,len=0, word=0;
	for(int i=0;i<n && idx<4;++i){
		bool ok=false;
		while(idx<4 && i<n && (lo[idx]==s[i] || up[idx]==s[i])){
			 i++;
			 len++;
			 ok=true;
		}
		if(ok) word++;
		idx++;
		--i;
	}

	// cout<<len<<" "<<word<<endl;
	cout<<(len==n && word==4 ? "YES": "NO")<<endl;
}

int main(){
	Faster;

	int t;
	cin>>t;

	while(t--){
	   solve();
	}
}