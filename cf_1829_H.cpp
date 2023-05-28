//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1829/problem/H
*/
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define Faster ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

#define ll long long
#define ld long double
#define vi vector<int> 
#define vs vector<string>
#define vb vector<bool> 
#define pii pair<int,int>
#define pll pair<ll,ll>


#define pb push_back
#define all(c) (c).begin(),(c).end()

//debug
#define vec_prnt(v) for(auto x: v) { cout<<x<<" "; } cout<<"\n"
#define prnt1(x) cout<<x<<endl;
#define prnt2(x,y) cout<<x<<" "<<y<<endl;

const int N=2e5+10;
const ll MOD=1e9+7;

int n, k, arr[N];
ll dp[N][65][2];

ll calc(int idx, int val, bool empty){

	if(idx==n) {
		if(empty) return 0;
		return __builtin_popcount(val)==k;
	}

	if(dp[idx][val][empty]!=-1) return dp[idx][val][empty];

	ll tk;
	if(empty) tk = calc(idx+1, arr[idx], false);
	else tk = calc(idx+1, val&arr[idx], false);

	ll ntk = calc(idx+1, val, empty);

	ll res = (tk + ntk)%MOD;

	return dp[idx][val][empty]=res;
}

void solve(){
	cin>>n>>k;

	for(int i=0;i<n;++i){
		cin>>arr[i];
	}

	for(int i=0;i<n;++i){
		for(int j=0;j<64;++j){
			dp[i][j][0]=-1;
			dp[i][j][1]=-1;
		}
	}

	prnt1(calc(0,0,true));
}

int main(){
	Faster;

	int t;
	cin>>t;

	while(t--){
	   solve();
	}
}