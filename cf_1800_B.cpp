/*
https://codeforces.com/contest/1800/problem/B
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
	int n,k;
	cin>>n>>k;

	string s;
	cin>>s;

	unordered_map<char,int> mp;
	unordered_map<char,bool> taken;
	
	for(int i=0;i<n;++i){
		mp[s[i]]++;
	}

	int ans=0;
	for(int i=0;i<n;++i){
		if(taken[s[i]]) continue;

		char ch_u = s[i], ch_l = s[i];
		if(isupper(ch_l)) ch_l = tolower(ch_l);
		else ch_u = toupper(ch_u);

		int diff = abs(mp[ch_u] - mp[ch_l]);
		ans+=min(mp[ch_u], mp[ch_l]);

		int d = min(k,diff/2);

		ans+=d,k-=d;

		taken[ch_u]=taken[ch_l]=true;

	}

	cout<<ans<<endl;

}

int main(){
	Faster;

	int t;
	cin>>t;

	while(t--){
	   solve();
	}
}