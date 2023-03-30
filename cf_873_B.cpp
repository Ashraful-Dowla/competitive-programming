/*
https://codeforces.com/contest/873/problem/B
*/
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long
#define Faster ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define pii pair<int,int> 

//debug
#define vec_prnt(v) for(auto x: v) { cout<<x<<" "; } cout<<"\n"

const int N=1e5+10;
const int MOD=1e9+7;

void solve(){
	int n;
	cin>>n;

	string s;
	cin>>s;

	unordered_map<int, int> mp;

	int sum=0,ans=0;
	for(int i=1;i<=n;++i){
		if(s[i-1]=='1') sum++;
		else sum--;

		if(mp[sum] || sum==0){
			ans = max(ans, i-mp[sum]);
		}
		else mp[sum]=i;
	}

	cout<<ans<<endl;
}

int main(){
	Faster;

	solve();
}